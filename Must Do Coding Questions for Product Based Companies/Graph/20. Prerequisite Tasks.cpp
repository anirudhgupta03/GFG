class Solution{
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    
	    vector<int> al[N];
	    vector<int> in(N,0);
	    
	    for(int i = 0; i < pre.size(); i++){
	        int a = pre[i].first, b = pre[i].second;
	        al[b].push_back(a);
	        in[a]++;
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < N; i++){
	        if(in[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> res;
	    while(!q.empty()){
	        
	        int curr = q.front();
	        res.push_back(curr);
	        q.pop();
	        
	        for(int i = 0; i < al[curr].size(); i++){
	            in[al[curr][i]]--;
	            if(in[al[curr][i]] == 0){
	                q.push(al[curr][i]);
	            }
	        }
	    }
	    
	    if(res.size() == N){
	        return true;
	    }
	    return false;
	}
};
