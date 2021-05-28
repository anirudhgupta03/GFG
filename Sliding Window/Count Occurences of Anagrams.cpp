public:
	int search(string pat, string txt) {
	    
	    if(pat.size() == 0){
	        return txt.size();
	    }
	    int alpha1[26] = {0};
	    
	    for(int i = 0; i < pat.size(); i++){
	        alpha1[pat[i] - 'a']++;
	    }
	    
	    int l = 0, r = 0;
	    
	    int alpha2[26] = {0};
	    
	    int mct = 0, dct = pat.size();
	    
	    int count = 0;
	    
	    while(r < txt.size()){
	        
	        alpha2[txt[r] - 'a']++;
	        
	        if(alpha2[txt[r] - 'a'] <= alpha1[txt[r] - 'a']){
	            mct++;
	        }
	        else if(alpha1[txt[r]-'a'] == 0){
	            l = r + 1;
	            for(int i = 0; i < 26; i++){
	                alpha2[i] = 0;
	            }
	            mct = 0;
	        }
	        else if(alpha1[txt[r]-'a'] != 0){
	            
	            while(l < r && txt[l] != txt[r]){
                    alpha2[txt[l]-'a']--;
                    if(alpha2[txt[l]-'a'] < alpha1[txt[l]-'a']){
                        mct--;
                    }
                    l++;
                }
                alpha2[txt[l]-'a']--;
                l++;
	        }
	  
	        if(mct == dct){
	            count++;
	            mct--;
	            alpha2[txt[l] - 'a']--;
	            l++;
	        }
	        r++;
	    }
	    return count;
	}
};
