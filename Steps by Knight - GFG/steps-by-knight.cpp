// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
private:
    vector<vector<int>> dir = {{-2,-1},{-2,1},{-1,-2},{1,-2},{2,-1},{2,1},{-1,2},{1,2}};
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&init,vector<int>&final,int N)
	{
	    init[0] -= 1;
	    init[1] -= 1;
	    final[0]-=1;
	    final[1]-=1;
	    vector<vector<int>> vis(N, vector<int>(N, 0));
	    queue<pair<int, int>> q;
	    int ans = 0;
	    q.push(make_pair(init[0], init[1]));
	    while(!q.empty())
	    {
	        int qlen = q.size();
	        for(int i = 0; i < qlen; i++)
	        {
	            pair<int, int> p = q.front();
	            q.pop();
	            if(vis[p.first][p.second] == 1) continue;
	            vis[p.first][p.second] = 1;
	            if(p.first==final[0] && p.second==final[1])
	                return ans;
	            for(vector<int> k : dir)
	            {
	                int newx = p.first+k[0], newy = p.second+k[1];
	                if(newx >=0 && newx<N && newy>=0 && newy<N)
	                {
	                    pair<int, int> temp = make_pair(newx, newy);
	                    if(vis[newx][newy]==0) {
	                       // vis[newx][newy]=1;
	                        q.push(temp);
	                    }
	                }
	            }
	        }
	        ans++;
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends