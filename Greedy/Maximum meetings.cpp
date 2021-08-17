//codingninjas.com/codestudio/problems/maximum-meetings_1062658?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2){
    if(p1.first.second == p2.first.second){
        return p1.second < p2.second;
    }
    return p1.first.second < p2.first.second;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    
    vector<pair<pair<int,int>,int>> v;
    
    for(int i = 0; i < start.size(); i++){
        v.push_back({{start[i],end[i]},i+1});
    }
    
    sort(v.begin(),v.end(),cmp);
	
    int count = 1, e = v[0].first.second;
    
    vector<int> res;
    res.push_back(v[0].second);
    
    for(int i = 1; i < v.size(); i++){
        if(v[i].first.first > e){
            count++;
            e = v[i].first.second;
            res.push_back(v[i].second);
        }
    }
    
    return res;
}
