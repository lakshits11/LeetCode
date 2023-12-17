static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();

class FoodRatings {
private:

    unordered_map<string,string> foodsToCuisines{};
    unordered_map<string,int> foodsToRatings{};
    unordered_map<string,set<pair<int,string>>> cuisineRatings{};

public:

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodsToCuisines[foods[i]] = cuisines[i];
            foodsToRatings[foods[i]] = ratings[i];
            cuisineRatings[cuisines[i]].insert(make_pair(-ratings[i], foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating = foodsToRatings[food];
        string& cuisine = foodsToCuisines[food];
        cuisineRatings[cuisine].erase(make_pair(-oldRating, food));
        foodsToRatings[food] = newRating;
        cuisineRatings[cuisine].insert(make_pair(-newRating, food));
    }
    
    string highestRated(string cuisine) {
        return cuisineRatings[cuisine].begin()->second;
    }
};