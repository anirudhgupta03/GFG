//Ref: https://www.youtube.com/watch?v=TURfqTmD8UQ
class Solution{
public:
    int dx[8] = {0,0,1,-1,-1,-1,1,1};
    int dy[8] = {-1,1,0,0,1,-1,-1,1};
    bool solve(int ind, string word, int m, int n, int x, int y, vector<vector<char>> &board, vector<vector<int>> &vis){
        
        if(ind == word.size()){
            return true;
        }
        
        vis[x][y] = 1;
        
        for(int i = 0; i < 8; i++){
            
            int xo = x + dx[i], yo = y + dy[i];
            
            if(xo >= 0 && xo < m && yo >= 0 && yo < n && vis[xo][yo] == 0){
                if(board[xo][yo] == word[ind]){
                    if(solve(ind+1,word,m,n,xo,yo,board,vis)){
                        return true;
                    }
                }
            }
        }
        
        vis[x][y] = 0;
        return false;
    }
    bool searchWord(string word, vector<vector<char>> &board, int m, int n){
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word[0] == board[i][j]){
                    
                    if(solve(1,word,m,n,i,j,board,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    
	    int m = board.size(), n = board[0].size();
	    
	    vector<string> res;
	    
	    for(int i = 0; i < dictionary.size(); i++){
	        
	        if(searchWord(dictionary[i],board,m,n)){
	            res.push_back(dictionary[i]);
	        }
	    }
	    
	    return res;
	}
};
