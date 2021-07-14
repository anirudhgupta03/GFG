class Solution
{
    public:
    #define pic pair<int,char>
    struct cmp{
      bool operator()(pair<int,char> p1, pair<int,char> p2){
          return p1.first < p2.first;
      }  
    };
    string rearrangeString(string str)
    {
        unordered_map<char,int> umap;
        
        for(int i = 0; i < str.size(); i++){
            umap[str[i]]++;
        }
        
        priority_queue<pic,vector<pic>,cmp> pq;
        
        for(auto x: umap){
            pq.push({x.second,x.first});
        }
        
        string res;
        
        while(pq.size() > 1){
            
            char c = pq.top().second;
            int curr = pq.top().first;
            pq.pop();
            char n = pq.top().second;
            int next = pq.top().first;
            pq.pop();
           
            res.push_back(c);
            res.push_back(n);
            
            curr -= 1;
            next -= 1;
            
            if(curr > 0){
                pq.push({curr,c});
            }
            if(next > 0){
                pq.push({next,n});
            }
        }
        
        if(!pq.empty() && pq.top().first > 1){
            return "-1";
        }
        else if(!pq.empty()){
            res.push_back(pq.top().second);
        }
        return res;
    }
    
