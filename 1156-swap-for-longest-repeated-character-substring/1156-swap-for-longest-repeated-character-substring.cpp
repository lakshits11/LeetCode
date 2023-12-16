/****** EXPLAINED CODE FOR SOME PART, FOR ELSE, SEE YOUTUBE VIDEO BY LEETUTION */
/*

class Solution {
public:
    int maxRepOpt1(string text) {
        
        vector< pair<int,int> > a[26];
		//this is to store the ranges in which a particular character occurs
		//ex. in "aaabaa" a[0] = { {0,2}, {4,5} } and a[1] = { {3,3} }
		
        int n=text.length(), ans=1; //ans can be minimum 1
        
		//logic for finding the ranges for all the characters
        for(int i=0;i<n;i++)
        {
            int j;
            for(j=i+1;j<n;j++)
                if(text[j]!=text[i])
                    break;
            //from [i to j-1] we have the same characters i.e., text[i]
            a[text[i]-'a'].push_back({i, j-1}); //pushing back the pair
            i=j-1; 
			//after i++ we will again start from index j
        }
        
		//for all characters what is max ans we can get
        for(char ch='a'; ch<='z'; ch++)
        {
            int total = a[ch-'a'].size(); //total ranges we have for the current character ch
            if(total==0) continue;
            int posLength; //max ans possible with this character
            
            for(int i=0; i<total; i++) //go through all the ranges of character ch
            {
                pair<int,int> cur = a[ch-'a'][i]; //current range
                posLength = cur.second-cur.first+1; // ex. {1,3} has 3 same characters
                if(total > 1) posLength++;
				//now if we have more than 1 range for the current character, we can bring one character
				//from that range to one of the ends of this current range to increase posLength by 1
                ans = max(ans, posLength);
                
				//now checking if i and i-1 ranges of this character can be joined (cur and prev)
                if(i!=0) //not with the first segment, because this has no previous
                {
                    pair<int,int> prev = a[ch-'a'][i-1]; //this is the previous occurence of same character
                    if(prev.second+2 == cur.first)      //ex. "aaabaaa" let prev={0,2} and cur={4,6} for 'a'
					//only one character between cur and prev ranges
                    {
                        posLength = (prev.second-prev.first+1) + (cur.second-cur.first+1);
                        if(total > 2) posLength++;
						//same as before if we have one more range apart from prev and cur we can replace the 
						//character separating prev and cur with some character from that range
						//ex. "baaabaaaba" here answer is 7, the 'a' at index 9 can be swapped with 'b' at index 4
						//in this if last 'a' was not there, we would have to swap 'b'(at index 4) with some 'a' from
						//either cur or prev ranges, in that case posLength would not have incremented by 1
                        ans=max(ans, posLength);
                    }
                }
            }
        }
        return ans;
    }
};

*/


static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int maxRepOpt1(string &t) {
        vector<int> arr[26];
        for(int i=0;i<t.size();i++)
            arr[t[i]-'a'].push_back(i);
        int res = 0;
        
        for(int i=0;i<26;i++)
        {
            vector<int> &temp = arr[i];
            int curr = 1, prev = 0, sum = 0;
            for(int j=1; j < temp.size();++j)
            {
                if(temp[j] == temp[j-1]+1) ++curr;
                else if(temp[j] == temp[j-1]+2) {prev = curr;curr=1;}
                else {prev = 0;curr=1;}
                sum = max(sum, prev+curr);
            }
            // sum<temp.size() means ki abhi prev aur curr ke baad bhi aur elements remaining hai to:
            // 1. agar suppose prev aur curr ke beech ek element aata hai i.e. unke beech ka diff == 2, then sum<temp.size() ka matlab hai abhi aur instances of our current alphabet are remanining which can replace that beech waala element. So we added one to that
            // 2. else if sum==temp.size, i.e. all instances  of current element are covered, so no adding one
            res = max(res, sum+(sum<temp.size()?1:0));
        }
        
        
        return res;
    }
};