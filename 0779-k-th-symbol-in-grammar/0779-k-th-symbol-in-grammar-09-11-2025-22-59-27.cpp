class Solution {
public:
    /**
     * @brief Finds the k-th symbol using a binary tree path approach.
     * This method views the grammar as an infinite binary tree where each node's value
     * is determined by its parent and whether it's a left or right child.
     */
    int kthGrammar(int n, int k) {
        // We start at the root (value 0) and count how many times our value
        // "flips" as we traverse down the path to our target node (n, k).
        int flips = 0;

        // We determine the path by climbing UP from (n, k) to the root.
        // We only need to iterate n-1 times to reach the root from row n.
        for (int i = 0; i < n - 1; ++i) {
            // Check if k corresponds to a "right child" position.
            // Right children are at even positions (2, 4, 6...).
            if (k % 2 == 0) {
                // Moving from a right child to its parent flips the value.
                flips = !flips;
            }
            // Move up to the parent node. The parent's k-th position is ceil(k/2).
            // For integers, (k+1)/2 is a clever way to calculate ceil(k/2).
            k = (k + 1) / 2;
        }

        // The final value is 0 if there was an even number of flips,
        // and 1 if there was an odd number of flips.
        return flips;
    }
};