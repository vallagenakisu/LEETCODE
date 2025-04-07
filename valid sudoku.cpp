#include<bits/stdc++.h>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0 ; i < 9 ; i++){
        unordered_set<char> test ;
        for(int j = 0 ; j < 9 ; j++){
            if(board[i][j] == '.') continue;
            else if(test.count(board[i][j])) return false;
            else{
                test.insert(board[i][j]);
            }   
        }
    }
    for(int i = 0 ; i < board.size();i++){
        unordered_set<char>test;
        for(int j = 0 ; j < board.size() ; j++){
            if(board[i][j] == '.') continue;
            else if(test.count(board[j][i])) return false;
            else{
                test.insert(board[j][i]);
            }
        }
    }
    for(int square = 0 ; square < 9 ; square++){
        unordered_set<char> test ;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                int row = (square / 3 ) * 3 + i;
                int col = (square % 3 ) * 3 + j;
            if(board[i][j] == '.') continue;
            else if(test.count(board[i][j])) return false;
            else{
                test.insert(board[i][j]);
            }
            }
        }
    }
    return true;
}



int main()
{
    vector<vector<char>> board = {
        {'1','2','.','.','3','.','.','.','.'},
        {'4','.','.','5','.','.','.','.','.'},
        {'.','9','1','.','.','.','.','.','3'},
        {'5','.','.','.','6','.','.','.','4'},
        {'.','.','.','8','.','3','.','.','5'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','.','.','.','.','.','2','.','.'},
        {'.','.','.','4','1','9','.','.','8'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << isValidSudoku(board);

}