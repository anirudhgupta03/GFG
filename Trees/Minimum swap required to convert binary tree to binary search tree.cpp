// C++ program for Minimum swap required
// to convert binary tree to binary search tree

//Time Complexity - O(nlogn)
//Space Complexity - O(n)
#include<bits/stdc++.h>
using namespace std;
 
// Inorder Traversal of Binary Tree
void inorder(int a[], vector<int> &v,vint n, int index)
{
    if(index >= n){
      return;
    }
    inorder(a, v, n, 2 * index + 1);
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}
 
// Function to find minimum swaps to sort an array
int minSwaps(vector<int> &nums)
{
    int n = nums.size();
    vector<pair<int,int>> v(n);
  
    for(int i = 0; i < n; i++){
      v[i] = {nums[i],i};
    }
    sort(v.begin(),v.end());
    
    vector<int> vis(n,0);
    
    int swaps = 0;
  
    for(int i = 0; i < n; i++){
       if(vis[i] == 1 || i == v[i].second){
         continue;
       }
       else{
         int cycle_size = 1;
         vis[i] = 1;
         int ind = v[i].second;
         
         while(vis[ind] == 0){
           cycle_size++;
           vis[ind] = 1;
           ind = v[ind].second;
         }
         if(cycle_size - 1 > 0){
           swaps += cycle_size - 1;
         }
       }
    }
    return swaps;
}
int main()
{
    int a[] = { 5, 6, 7, 8, 9, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    std::vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
}

//https://www.codingninjas.com/codestudio/problems/minimum-swaps-to-convert-binary-tree-into-bst_1118109?leftPanelTab=1
#include<bits/stdc++.h>
using namespace std;
void inorder(int ind, int n, vector<int> &v, vector<int> &arr){
    
    if(ind >= n){
        return;
    }
    
    inorder(2*ind + 1, n, v, arr);
    v.push_back(arr[ind]);
    inorder(2*ind + 2, n, v, arr);
}
bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.first < p2.first;
}
int minimumSwaps(vector<int>&arr, int n) {
			
    vector<int> v;
    inorder(0,n,v,arr);
    
    vector<pair<int,int>> temp;
    for(int i = 0; i < v.size(); i++){
        temp.push_back({v[i],i});
    }
    
    sort(temp.begin(),temp.end(),cmp);
    vector<int> vis(n,0);
    	
    int swaps = 0;
    
    for(int i = 0; i < n; i++){
        if(vis[i] == 1 || i == temp[i].second){
            continue;
        }
        
        int cycle_size = 1;
        vis[i] = 1;
        
        int ind = temp[i].second;
        while(vis[ind] == 0){
            cycle_size++;
            vis[ind] = 1;
            ind = temp[ind].second;
        }
        swaps += cycle_size - 1;
    }
    return swaps;
}			
