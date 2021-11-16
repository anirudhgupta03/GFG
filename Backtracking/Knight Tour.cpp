//https://www.codingninjas.com/codestudio/problems/knight-tour_1170518?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

bool solve(int count, int x, int y, int n, int m, vector<vector<int>> &board, vector<vector<int>> &valid){
    
    if(count == n*m){
        valid = board;
        return true;
    }
    
    for(int i = 0; i < 8; i++){
        int xo = x + dx[i], yo = y + dy[i];
        if(xo >= 0 && yo >= 0 && xo < n && yo < m && board[xo][yo] == -1){
            board[xo][yo] = count;
            bool flag = solve(count + 1, xo, yo, n, m, board, valid);
            if(flag) return true;
            board[xo][yo] = -1;
        }
    }
    return false;
}
vector<vector<int>> knightTour(int n, int m) {
    
    vector<vector<int>> board(n, vector<int>(m,-1));
    vector<vector<int>> valid(n, vector<int>(m,-1));
    
    board[0][0] = 0;
    bool flag = solve(1,0,0,n,m,board,valid);
    
    if(flag){
        return valid;
    }
    board[0][0] = -1;
    return board;
}
