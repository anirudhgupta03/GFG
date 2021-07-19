// C++ program for Minimum swap required
// to convert binary tree to binary search tree
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
