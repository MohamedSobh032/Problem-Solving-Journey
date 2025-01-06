/**
 * @brief First Solution
 * -- Time Complexity: O(n^2)
 * -- Space Complexity: O(1)
 * -- Brute-force approach
 */
class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.size(); std::vector<int> moves(n, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    moves[i] += (boxes[j] == '1') ? abs(i - j) : 0;
        return moves;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Prefix sum approach, Calculates the number of moves from the left and from the right, then add them up together
 */
class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.size();
        std::vector<int> moves_left(n, 0); std::vector<int> moves_right(n, 0);
        int counter_left = (boxes[0] == '1'), counter_right = (boxes[n - 1] == '1');

        for (int i = 1; i < n; i++) {
            moves_left[i] += moves_left[i - 1] + counter_left; counter_left += (boxes[i] == '1');
            moves_right[n - 1 - i] += moves_right[n - i] + counter_right; counter_right += (boxes[n - 1 - i] == '1');
        }

        for (int i = 0; i < n; i++) moves_left[i] += moves_right[i];
        return moves_left;
    }
};