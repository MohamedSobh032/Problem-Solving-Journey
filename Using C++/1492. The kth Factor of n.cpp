/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(factors)
 * -- Iterates on all numbers from 1 to n and stores the factors of n in a vector.
 */
class Solution {
public:
    int kthFactor(int n, int k) {
        std::vector<int> factors;
        for (int i = 1; i <= n; i++)
            if (n % i == 0)
                factors.push_back(i);
        return factors.size() <= k - 1 ? -1 : factors[k - 1];
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Same as above, but, instead of storing the factors in a vector, we store the last factor in a variable.
 */
class Solution {
public:
    int kthFactor(int n, int k) {
        int counter = 0;
        int last_value = -1;
        for (int i = 1; i <= n; i++) {
            if (n % i != 0) continue;
            counter++;
            last_value = i;
            if (counter == k) break;
        }
        return counter < k ? -1 : last_value;
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(sqrt(n))
 * -- Space Complexity: O(factors)
 * -- Iterates on all numbers from 1 to sqrt(n) and stores the factors of n in a set.
 */
class Solution {
public:
    int kthFactor(int n, int k) {
        std::set<int> factors;
        int sqroot = sqrt(n);

        for (int i = 1; i <= sqroot; i++) {
            if (n % i != 0) continue;
            factors.insert(i);
            factors.insert(n / i);
        }
        if (k > factors.size()) return -1;
        auto it = factors.begin();
        std::advance(it, k - 1);
        return *it;
    }
};