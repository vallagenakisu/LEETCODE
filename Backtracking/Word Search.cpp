#include <bits/stdtr1c++.h>
using namespace std;
vector<vector<bool>> taken;
int row, col;

bool fun(int i, int j, vector<vector<char>> &board, string word, int w)
{
    if (word[w] != board[i][j])
        return false;

    if (w == word.size() - 1)
        return true;
    taken[i][j] = true;

    for (int k = 0; k < 4; k++)
    {
        int dx[] = {-1, 0, 0, 1, -1, 1, 1, -1};
        int dy[] = {0, 1, -1, 0, 1, 1, -1, -1};
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni >= 0 and ni < row and nj >=0 and nj < col)
        {
            if (!taken[ni][nj])
            {
                if(fun(ni, nj, board, word, w + 1))  return true;
            }
        }
    }
    taken[i][j] = false;
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    row = board.size();
    col = board[0].size();
    taken.assign(row, vector<bool>(col, false));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (fun(i, j, board, word, 0))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'D'},
        {'S', 'A', 'A', 'T'},
        {'A', 'C', 'A', 'E'}};
    string word = "DAS";
    cout << exist(board, word);
}