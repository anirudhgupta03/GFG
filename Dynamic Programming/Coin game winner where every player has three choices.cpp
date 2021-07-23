//https://www.codingninjas.com/codestudio/problems/coin-game-winner-where-every-player-has-three-choices_1229492?topList=top-dynamic-programming-questions&leftPanelTab=0
//Ref: https://www.youtube.com/watch?v=uXqoNkv_Iv0
#include<bits/stdc++.h>
using namespace std;
int coinGameWinner(int n, int a, int b)
{
    bool dp[n+1];
    
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++){
        
        if(!dp[i-1]){
            dp[i] = 1;
        }
        else if(i - a >= 0 && !dp[i-a]){
            dp[i] = 1;
        }
        else if(i - b >= 0 && !dp[i-b]){
            dp[i] = 1;
        }
        else{
            dp[i] = 0;
        }
    }
    
    return dp[n];
}

