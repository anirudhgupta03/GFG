//https://www.codingninjas.com/codestudio/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day_1169470?leftPanelTab=0
//https://www.geeksforgeeks.org/buy-maximum-stocks-stocks-can-bought-th-day/
#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.first < p2.first;
}
int maxStock(vector<int> &prices, int n, int amount){
    
    vector<pair<int,int>> v;
    
    for(int i = 0; i < n; i++){
        v.push_back({prices[i], i + 1});
    }
    
    sort(v.begin(),v.end(),cmp);
    
    int maxCount = 0;
    
    for(int i = 0; i < v.size(); i++){
        if(amount >= v[i].first){
            int temp = min(v[i].second, amount/v[i].first);
            maxCount += temp;
            amount -= temp*(v[i].first);
        }
        else{
            break;
        }
    }
    return maxCount;
}
