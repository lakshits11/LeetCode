static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class Solution {
public:
    int cycleSort(vector<int>& nums)
    {
        int n = nums.size();
        int len = n;
        map<int, int> map;
        for (int i = 0; i < len; i++)
            map[nums[i]] = i;
        sort(nums.begin(), nums.end());
        bool visited[len];
        for(int i = 0; i < len ; i++) visited[i] = false;
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
		    // already swapped and corrected or already present at correct pos
            if (visited[i] || map[nums[i]] == i)
                continue;
            int j = i, cycle_size = 0;
            while (!visited[j])
            {
                visited[j] = true;
				// move to next node
                j = map[nums[j]];
                cycle_size++;
            }
            if (cycle_size > 0)
            {
			// Update answer by adding current cycle.
                ans += (cycle_size - 1);
            }
        }
        return ans;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
		// nullptr to identify end of level
        q.push(nullptr);
        vector<int> v;
        int ans = 0;
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            if(!temp)
            {
                ans += cycleSort(v);
                v.clear(); // clear values of old level
				// if there are more elements in queue then push null to identify end else no elements are present 
				// so don't push anything
                if(!q.empty())
                    q.push(nullptr);
            }
            else
            {
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

        }
        
        return ans;
    }
};