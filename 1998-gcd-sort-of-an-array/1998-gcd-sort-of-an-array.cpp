class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // Path compression
    }
    void Union(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) parent[pu] = pv;
    }
};

class Solution {
public:
    // spf[x] is the smallest prime factor of number x, where x >= 2
    vector<int> spf;
    bool gcdSort(vector<int>& nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int maxNum = *max_element(nums.begin(), nums.end());
        sieve(maxNum + 1);

        UnionFind uf(maxNum+1);
        for (int x : nums)
            for (int f : getPrimeFactors(x))
                uf.Union(x, f);

        vector<int> sortedArr(nums);
        sort(sortedArr.begin(), sortedArr.end());
        for (int i = 0; i < nums.size(); ++i)
            if (uf.find(nums[i]) != uf.find(sortedArr[i]))
                return false; // can't swap nums[i] with sortedArr[i]
        return true;
    }
    void sieve(int n) { // O(Nlog(logN)) ~ O(N)
        spf.resize(n);
        for (int i = 2; i < n; ++i) spf[i] = i;
        for (int i = 2; i * i < n; i++) {
            if (spf[i] != i) continue; // skip if `i` is not a prime number
            for (int j = i * i; j < n; j += i)
                if (spf[j] > i) spf[j] = i; // update to the smallest prime factor of j
        }
    }
    vector<int> getPrimeFactors(int n) { // O(logN)
        vector<int> factors;
        while (n > 1) {
            factors.push_back(spf[n]);
            n /= spf[n];
        }
        return factors;
    }
};