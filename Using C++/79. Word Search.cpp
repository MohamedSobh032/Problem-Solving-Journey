/**
 * @brief First/Only Solution
 * -- O(n * m * 4l)
 * -- DFS on all elements, using all the starting positions available
 */
class Solution
{
public:
    std::vector<std::vector<char>> board;
    std::string word;
    int rowsize;
    int colsize;

    bool dfs(int index, int row, int column)
    {

        if (word.size() == index)
            return true;
        if (row < 0 || column < 0 || row >= rowsize || column >= colsize || word[index] != board[row][column])
            return false;

        char temp = board[row][column];
        board[row][column] = '\0';
        bool result = dfs(index + 1, row + 1, column) || dfs(index + 1, row - 1, column) || dfs(index + 1, row, column + 1) || dfs(index + 1, row, column - 1);
        board[row][column] = temp;

        return result;
    }

    bool exist(vector<vector<char>> &board, string word)
    {

        this->rowsize = board.size();
        this->colsize = board[0].size();
        this->board = board;
        this->word = word;

        for (int i = 0; i < rowsize; i++)
        {
            for (int j = 0; j < colsize; j++)
                if (dfs(0, i, j))
                    return true;
        }
        return false;
    }
};