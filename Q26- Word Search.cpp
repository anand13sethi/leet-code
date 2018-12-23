/*
Link - https://leetcode.com/problems/word-search
*/

bool dfs(vector<vector<char> >&board, string word, int i, int j, int cur){
   if(cur == word.size())
       return true;
   if(i < 0 || j < 0 || i == board.size() || j == board[i].size())
       return false;
   bool res;
   if(word[cur] != board[i][j])
       return false;
   board[i][j] = ' ';
   res = dfs(board, word, i-1, j, cur+1) || dfs(board, word, i+1, j, cur+1) || dfs(board, word, i, j-1, cur+1) || dfs(board, word, i, j+1, cur+1);
   board[i][j] = word[cur];
   return res;
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
             if(dfs(board, word, i, j, 0))
                  return true;
        }
    }
    return false;
}