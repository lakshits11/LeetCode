static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
#define ll long long
class Solution {
public:
    ll distributeCandies(int n, int limit) {
        ll count = 0;
        
        for (int x = 0; x <= min(n, limit); ++x) {
            int remaining = n - x;
            
            // Now we want to distribute `remaining` candies to the other 2 children
            // Each child must get [0, limit] candies
            
            int min_y = max(0, remaining - limit);      // Ensures z <= limit
            int max_y = min(limit, remaining);          // Ensures y <= limit and z >= 0

            if (min_y <= max_y) {
                count += (max_y - min_y + 1);
            }
        }

        return count;
    }
};