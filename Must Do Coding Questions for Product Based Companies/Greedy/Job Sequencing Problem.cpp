/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    bool static cmp(Job job1, Job job2){
        return job1.profit > job2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int maxDeadline = 0;
        
        for(int i = 0; i < n; i++){
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        vector<int> v(maxDeadline + 1, -1);
        
        sort(arr, arr + n, cmp);
        
        int maxProfit = 0, count = 0;
        
        for(int i = 0; i < n; i++){
            bool flag = false;
            for(int j = arr[i].dead; j >= 1; j--){
                if(v[j] == -1){
                    v[j] = arr[i].id;
                    maxProfit += arr[j].profit;
                    count++;
                    break;
                }
            }
        }
        vector<int> res = {count, maxProfit};
        return res;
    } 
};
