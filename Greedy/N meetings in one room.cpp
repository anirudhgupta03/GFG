bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}
class Solution{
    public:
        int maxMeetings(int start[], int end[], int n) {
        
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++){
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        int count = 1;
        
        int s = v[0].first;
        int f = v[0].second;
        
        for(int i = 1; i < v.size(); i++){
            if(v[i].first > f){
                count++;
                f = v[i].second;
            }
        }
        return count;
    }
};
