static const auto speedup = []() -> int{
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;
}();
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        queue<int> queue;

        // Create a queue of indexes
        for (int i = 0; i < N; i++) {
            queue.push(i);
        }
        
        sort(deck.begin(), deck.end());

        // Put cards at correct index in result
        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            // Reveal Card
            result[queue.front()] = deck[i];
            queue.pop();

            // Move next card to bottom
            if (!queue.empty()) {
                queue.push(queue.front());
                queue.pop();
            }
        }
        return result;
    }
};