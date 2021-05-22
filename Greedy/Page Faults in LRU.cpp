class Solution{
public:
    
    #define pii pair<int,int>

    struct mycomp{
      bool operator()(pair<int,int> p1, pair<int,int> p2){
          return p1.second > p2.second;
      }  
    };
    
    int pageFaults(int N, int C, int pages[]){
        
        priority_queue<pii,vector<pii>,mycomp> pq;
        
        int timer = 0;
        
        int count = 0;
        
        for(int i = 0; i < N; i++){
            
            vector<pii> temp;
            
            if(!pq.empty() || pq.size() == C){
                
                while(pq.size()){
                   temp.push_back(pq.top());
                   pq.pop();
                }
                
                bool flag = false;
                for(int j = 0; j < temp.size(); j++){
                    if(temp[j].first == pages[i]){
                        flag = true;
                        temp.erase(temp.begin()+j);
                        temp.push_back({pages[i],timer});
                        break;
                    }
                }
                
                if(!flag && temp.size() == C){
                    count++;
                    temp.erase(temp.begin());
                    temp.push_back({pages[i],timer});
                }
                else if(!flag && temp.size() < C){
                    count++;
                    temp.push_back({pages[i],timer});
                }
                
                for(int j = 0; j < temp.size(); j++){
                    pq.push(temp[j]);
                }
            }
            else{
                count++;
                pq.push({pages[i],timer});
            }
            
            //cout << pq.top().first << endl;
            timer++;
        }
        return count;
    }
};
