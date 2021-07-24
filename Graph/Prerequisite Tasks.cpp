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
	        q.pop();
	        res.push_back(curr);
	        
	        for(int i = 0; i < al[curr].size(); i++){
	            int child = al[curr][i];
	            in[child]--;
	            if(in[child] == 0){
	                q.push(child);
	            }
	        }
	    }
	    
	    if(res.size() == N) return true;
	    return false;
	}
};
