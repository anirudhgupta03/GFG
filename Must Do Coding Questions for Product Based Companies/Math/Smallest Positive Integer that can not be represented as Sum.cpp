//Similar Question: https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/
class Solution
{   
public:
    long long smallestpositive(vector<long long> array, int n)
    { 
        sort(array.begin(),array.end());
        
        long long ans = 1;
        
        for(int i = 0; i < n; i++){
            
            if(array[i] <= ans){
                ans += array[i];
            }
            else{
                return ans;
            }
        }
        return ans;
    } 
};
