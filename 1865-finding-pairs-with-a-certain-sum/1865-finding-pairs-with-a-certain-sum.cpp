class FindSumPairs {
public:
    vector<int> n1, n2;
    unordered_map<int, int> u;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        swap(n1, nums1);
        swap(n2, nums2);
        sort(n1.begin(), n1.end());
        for(int i=0;i<n2.size();++i) ++u[n2[i]];
    }
    
    void add(int index, int val) {
        --u[n2[index]];
        n2[index] += val;
        ++u[n2[index]];
    }
    
    int count(int tot) {
        int res = 0;
        for(int i = 0; i < n1.size() && n1[i] < tot; ++i) {
            auto it = u.find(tot - n1[i]);
            if(it != u.end())
                res += it->second;
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */