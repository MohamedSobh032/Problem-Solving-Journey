/**
 * @brief First Solution
 * -- Time Complexity: O(nq), n = number of shifts, q = length of string
 * -- Space Complexity: O(1)
 * -- Brute-force approach, rotate each character in the string q times
 */
class Solution {
public:
    void rotate(char& curr, const int& dir) {
        if (dir == 0) {
            if (curr == 'a') curr = 'z';
            else curr--;
        } else {
            if (curr == 'z') curr = 'a';
            else curr++;
        }
    }

    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        for (int i = 0; i < shifts.size(); i++)
            for (int j = shifts[i][0]; j <= shifts[i][1]; j++)
                rotate(s[j], shifts[i][2]);
        return s;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(nq + q), n = number of shifts, q = length of string
 * -- Space Complexity: O(q)
 * -- Using a difference array to store the rotation values
 */
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        std::vector<int> rotation(s.size(), 0);
        for (const auto& shift: shifts)
            for (int j = shift[0]; j <= shift[1]; j++)
                rotation[j] += shift[2] ? 1 : -1;
                
        for (int i = 0; i < s.size(); i++) {
            int totalShift = rotation[i] % 26;
            if (totalShift < 0) totalShift += 26;
            s[i] = 'a' + (s[i] - 'a' + totalShift) % 26;
        }
        return s;
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(n + q), n = number of shifts, q = length of string
 * -- Space Complexity: O(q)
 * -- Calculates only the start and the end of the difference array, then computes the prefix sum
 */
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size(); std::vector<int> rotation(n + 1, 0);
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            rotation[start] += direction ? 1 : -1;
            if (end + 1 < n) rotation[end + 1] -= direction ? 1 : -1;
        }

        int currRotation = 0;
        for (int i = 0; i < n; i++) {
            currRotation += rotation[i];
            int totalShift = (currRotation % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + totalShift) % 26;
        }

        return s;
    }
};

/**
 * @brief Fourth Solution
 * -- Time Complexity: O(n + q), n = number of shifts, q = length of string
 * -- Space Complexity: O(q)
 * -- Calculates only the start and the end of the difference array, then computes the prefix sum within the array itself
 */
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size(); std::vector<int> rotation(n + 1, 0);
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2] ? 1 : -1;
            rotation[start] += direction;
            if (end + 1 < n) rotation[end + 1] -= direction;
        }

        for (int i = 1; i < n; i++) rotation[i] += rotation[i - 1];

        for (int i = 0; i < n; i++) {
            int totalShift = rotation[i] % 26;
            if (totalShift < 0) totalShift += 26;
            s[i] = 'a' + (s[i] - 'a' + totalShift) % 26;
        }
        return s;
    }
};