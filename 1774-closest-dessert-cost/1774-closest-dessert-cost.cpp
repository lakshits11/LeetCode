static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {

private:
    void dfs(vector<int>& toppings, int index, int currentCost, int target, int& closest) {
        // Update closest if current cost is better
        if (abs(currentCost - target) < abs(closest - target) || 
            (abs(currentCost - target) == abs(closest - target) && currentCost < closest)) {
            closest = currentCost;
        }
        
        // If we've exceeded the target by more than the current difference, no need to add more toppings
        if (currentCost > target + abs(target - closest) || index == toppings.size()) {
            return;
        }
        
        // Skip this topping
        dfs(toppings, index + 1, currentCost, target, closest);
        
        // Add one of this topping
        dfs(toppings, index + 1, currentCost + toppings[index], target, closest);
        
        // Add two of this topping
        dfs(toppings, index + 1, currentCost + 2 * toppings[index], target, closest);
    }

public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        // Start with the cheapest option
        int closest = baseCosts[0];
        
        // Generate all possible costs using DFS
        for (int base : baseCosts) {
            dfs(toppingCosts, 0, base, target, closest);
        }
        
        return closest;
    }
};