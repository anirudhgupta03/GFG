class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static cmp(pair<int,int> &p1,pair<int,int> &p2){
        return p1.second < p2.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meetings(n);
        
        for(int i = 0; i < n; i++){
            meetings[i] = {start[i], end[i]};
        }
        
        sort(meetings.begin(), meetings.end(),cmp);
        
        int term = meetings[0].second, count = 1;
        
        for(int i = 1; i < n; i++){
            if(meetings[i].first > term){
                count++;
                term = meetings[i].second;
            }
        }
        return count;
    }
};
