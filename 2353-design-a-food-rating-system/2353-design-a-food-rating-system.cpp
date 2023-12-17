static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

struct comp{
    bool operator()(const pair<int, string> &a, const pair<int, string> &b)const
    {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};

class FoodRatings {
public:
    unordered_map<string, int> r;
    map<string, set<pair<int, string>, comp>> m;
    unordered_map<string, string> c;
    
    FoodRatings(vector<string>& food, vector<string>& cuisines, vector<int>& ratings) {
        int n = food.size();
        for(int i=0;i<n;i++)
        {
            r[food[i]] = ratings[i];
            m[cuisines[i]].insert({ratings[i], food[i]});
            c[food[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        m[c[food]].erase({r[food], food});
        m[c[food]].insert({newRating, food});
        r[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return (*m[cuisine].begin()).second;
    }
};
