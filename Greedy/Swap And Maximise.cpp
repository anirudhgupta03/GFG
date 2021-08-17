//https://www.codingninjas.com/codestudio/problems/swap-and-maximise_1164405?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;
int maxSum(vector<int> &arr, int n)
{
	int l = 0, r = n - 1;
    
    sort(arr.begin(),arr.end());
    vector<int> temp;
    
    while(l < r){
       temp.push_back(arr[l]);
        temp.push_back(arr[r]);
        l++;
        r--;
    }
    
    if(l == r){
        temp.push_back(arr[l]);
    }
    
    int maxsum = 0;
    
    for(int i = 1; i < temp.size(); i++){
        maxsum += abs(temp[i]-temp[i-1]);
    }
    maxsum += abs(temp[n-1]-temp[0]);
    return maxsum;
}
