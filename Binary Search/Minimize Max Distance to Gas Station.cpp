//Ref: https://www.youtube.com/watch?v=kMSBvlZ-_HA&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=20
//Method - 1
//Using Heap
//TC: O(NlogN) + O(KlogN)
//SC: O(N - 1)
#define pdi pair<double,int>
class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        int n = stations.size();
        if(n == 1){
            return 0;
        }
        
        vector<int> sections(n - 1, 0);
        priority_queue<pdi> pq;
        for(int i = 0; i < n - 1; i++){
            pq.push({stations[i + 1] - stations[i], i});
        }
        for(int i = 1; i <= K; i++){
            pdi p = pq.top();
            pq.pop();
            int ind = p.second;
            sections[ind]++;
            int gasStationsPresent = sections[ind];
            pq.push({(double)(stations[ind + 1] - stations[ind])/(gasStationsPresent + 1), ind});
        }
        return pq.top().first;
    }
};

//Method - 2
//Binary Search
class Solution {
  public:
    pair<bool, double> maxDist(double mid, vector<int> &stations, int K){
        
        double maxGap = INT_MIN;
        int stationsRequired = 0;
        
        for(int i = 1; i < stations.size(); i++){
            double diff = stations[i] - stations[i - 1];
            if(diff > mid){
                int currentStationsRequired = (int)(ceil(diff/mid) - 1);
                stationsRequired += currentStationsRequired;
                maxGap = max(maxGap, diff/(currentStationsRequired + 1));
            }
            else{
                maxGap = max(maxGap, diff);
            }
            if(stationsRequired > K){
                return {false, -1.0};
            }
        }
        return {true, maxGap};
    }
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        int n = stations.size();
        if(K == 0){
            return stations[n - 1] - stations[n - 2];
        }
        if(n == 1){
            return 0;
        }
        double lo = 0.01, hi = INT_MAX, ans = INT_MIN;
        for(int i = 1; i < stations.size(); i++){
            ans = max(ans, (double)(stations[i] - stations[i - 1]));
        }
        hi = ans;

        while(hi - lo > 0.01){
            double mid = lo + (hi - lo)/2;
            pair<bool, double> res = maxDist(mid, stations, K);
            if(res.first){
                ans = min(ans, res.second);
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        return ans;
    }
};
