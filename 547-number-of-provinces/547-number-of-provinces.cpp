class Solution
{
public:
    int find(int a, vector<int> &parent)
    {
        if (parent[a] == -1)
            return a;
        return parent[a] = find(parent[a], parent);
    }
    void unionFunc(int a, int b, vector<int> &parent, vector<int> &size)
    {
        a = find(a, parent);
        b = find(b, parent);

        if (a != b)
        {
            if (size[a] > size[b])
            {
                parent[b] = a;
                size[a] += size[b];
            }
            else
            {
                parent[a] = b;
                size[b] += size[a];
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> parent(n, -1);
        vector<int> size(n, 1);
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected[0].size(); j++)
            {
                if (isConnected[i][j])
                {
                    unionFunc(i, j, parent, size);
                }
            }
        }
        int noOfProvinces = 0;
        for (int i = 0; i < parent.size(); i++)
        {
            if (parent[i] == -1)
                noOfProvinces++;
        }
        return noOfProvinces;
    }
};