//Method - 1
//Time Complexity - O(N*N)
//Space Complexity - O(1)
//TLE
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array.
    int findMinInd(int ind, vector<int> &nums){
        
        int minEle = nums[ind], minInd = ind;
        
        for(int i = ind+1; i < nums.size(); i++){
            if(nums[i] < minEle){
                minEle = nums[i];
                minInd = i;
            }
        }
        
        return minInd;
    }
	int minSwaps(vector<int> &nums)
	{
	    int count = 0;
	    
	    for(int i = 0; i < nums.size(); i++){
	        int ind = findMinInd(i,nums);
	        if(ind != i){
	            count++;
	            swap(nums[i],nums[ind]);
	        }
	    }
	    return count;
	}
};
//Method - 2
//Time Complexity - O(NlogN)
//Space Complexity - O(N)
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    
	    vector<pair<int,int>> v(n);
	    
	    for(int i = 0; i < n; i++){
	        v[i] = {nums[i],i};
	    }
	    
	    sort(v.begin(),v.end());
	    
	    vector<int> vis(n,0);
	    
	    int ans = 0;
	    
	    for(int i = 0; i < n; i++){
	        
	        if(vis[i] || v[i].second == i){
	            continue;
	        }
	        
	        int cycle_size = 0;
	        int j = i;
	        
	        while(!vis[j]){
	            vis[j] = 1;
	            j = v[j].second;
	            cycle_size++;
	        }
	        
	        if(cycle_size > 0){
	            ans += (cycle_size - 1);
	        }
	    }
	    return ans;
	}
};
