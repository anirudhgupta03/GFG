bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> activity(n);
        
        for(int i = 0; i < n; i++){
            activity[i] = {start[i],end[i]};
        }
        
        sort(activity.begin(),activity.end(),cmp);
        
        int count = 1;
        
        int e = activity[0].second;
        
        for(int i = 1; i < n; i++){
            
            if(activity[i].first > e){
                count++;
                e = activity[i].second;
            }
        }
        return count;
    }
};
