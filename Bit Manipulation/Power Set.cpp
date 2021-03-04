public:
		vector<string> AllPossibleStrings(string s){
		    
		    vector<string> v;
		    int n = s.size();
		    
		    for(int i = 0; i < (1 << n); i++){
		        string str;
		        for(int j = 0; j < n; j++){
		            
		            int k = 1 << j;
		            
		            if((i & k) != 0){
		                str.push_back(s[j]);
		            }
		        }
		        if(str == ""){
		            continue;
		        }
		        v.push_back(str);
		    }
		    sort(v.begin(),v.end());
		    return v;
		}
};
