// refer votrubac's solution (easy to understand)

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        int arr[10001];
        memset(arr, 0, sizeof(arr));
        int maxc = 0, maxce = 0, pos = 0;
        for(int i = 0; i < b.size(); ++i)
        {
            maxc = max(maxc, ++arr[b[i]]);
            maxce = maxc==arr[b[i]] ? b[i] : maxce;
        }
        for(int i=0;i<10001;++i)
        {
            int n = i==0?maxce:i;
            while(arr[n]-- > 0)
            {
                b[pos] = n;
                // pos = pos+2<b.size()?pos+2:1;
                pos = pos+2>=b.size()?1:pos+2;
            }
        }
        return b;
        
    }
};