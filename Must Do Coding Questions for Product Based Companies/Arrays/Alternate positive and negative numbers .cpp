class Solution{
public:

	void rearrange(int arr[], int n) {
	    
	    vector<int> neg, pos;
	    
	    for(int i = 0; i < n; i++){
	        
	        if(arr[i] >= 0){
	            pos.push_back(arr[i]);
	        }
	        else{
	            neg.push_back(arr[i]);
	        }
	    }
	    
	    int l = 0, r = 0, i = 0;
	    
	    while(l < neg.size() && r < pos.size()){
	        if(i % 2 == 0){
	            arr[i] = pos[r];
	            r++;
	        }
	        else{
	            arr[i] = neg[l];
	            l++;
	        }
	        i++;
	    }
	    
	    while(l < neg.size()){
	        arr[i] = neg[l];
	        i++;
	        l++;
	    }
	    
	    while(r < pos.size()){
	        arr[i] = pos[r];
	        i++;
	        r++;
	    }
	}
};
