//https://www.codingninjas.com/codestudio/problems/count-customers-who-did-not-get-a-computer_1115775?leftPanelTab=1
//Method - 1
//TLE
#include<bits/stdc++.h>
using namespace std;
int countCustomers(vector<int> &arr, int k)
{
    unordered_map<int,int> umap;
    
    int count = 0;
    
    for(int i = 0; i < arr.size(); i++){
        
        if(umap.find(arr[i]) != umap.end()){
            if(umap[arr[i]] == 1) k++;
        }
        else{
            if(k == 0){
              umap[arr[i]] = 0;
              count++;  
            }
            else{
                umap[arr[i]] = 1;
                k--;
            }
        }
    }
    return count;
}

//Method - 2
#include<bits/stdc++.h>
using namespace std;
int countCustomers(vector<int> &arr, int k)
{
    int n = arr.size();
    int umap[n+1] = {0};
    
    int count = 0;
    
    for(int i = 0; i < arr.size(); i++){
        
        if(umap[arr[i]] != 0){
            if(umap[arr[i]] == 1) k++;
        }
        else{
            if(k == 0){
              umap[arr[i]] = 2;
              count++;  
            }
            else{
                umap[arr[i]] = 1;
                k--;
            }
        }
    }
    return count;
}
