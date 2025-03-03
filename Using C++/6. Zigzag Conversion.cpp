/**
 * @brief First Solution
 * ---> O(n)
 * ---> Appends character in a vector of vectors with an algorithm O(n)
 */
class Solution
{
public:
    string convert(string s, int numRows)
    {
        // Algorithm can't handle 1 row
        if (numRows == 1)
            return s;

        // Algorithm
        vector<vector<char>> zigzag(numRows);
        int counter = 0;
        bool direction = true;
        for (int i = 0; i < s.size(); i++)
        {
            zigzag[counter].push_back(s[i]);
            if (direction)
            {
                counter++;
                if (counter == numRows)
                {
                    counter -= 2;
                    direction = false;
                }
            }
            else
            {
                counter--;
                if (counter == -1)
                {
                    counter += 2;
                    direction = true;
                }
            }
        }

        // Append new string
        string ret = "";
        for (const auto &row : zigzag)
        {
            for (const auto &elem : row)
                ret += elem;
        }
        return ret;
    }
};

/**
 * @brief Second Solution
 * ---> O(n)
 * ---> Same as above, uses vector of strings instead of vectors of vectors
 * ---> Uses adder instead of direction
 */
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> zigzag(numRows);
        int counter = 0, counterAdder = 1;
        for (const auto &c : s)
        {
            zigzag[counter] += c;
            if (counter == 0)
                counterAdder = 1;
            else if (counter == numRows - 1)
                counterAdder = -1;
            counter += counterAdder;
        }
        string ret;
        for (const auto &row : zigzag)
            ret += row;
        return ret;
    }
};