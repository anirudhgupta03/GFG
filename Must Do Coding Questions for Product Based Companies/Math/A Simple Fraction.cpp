class Solution{
public:
	string fractionToDecimal(int num, int den) {
	    
	    string res;
	    
	    int a = num/den;
	    
	    res += to_string(a);
	    
	    if(num % den == 0){
	        return res;
	    }
	    
	    num %= den;
	    
	    unordered_map<int,int> umap;
	    res.push_back('.');
	    
	    int pos = res.size();
	    
	    while(num){
	        num *= 10;
	        if(umap.find(num) != umap.end()){
	            break;
	        }
	        else{
	            umap[num] = pos;
	        }
	        res.push_back(num/den + '0');
	        num %= den;
	        pos++;
	    }
	    
	    if(num == 0){
	        return res;
	    }
	    res.push_back(')');
	    res.insert(res.begin() + umap[num],'(');
	    
	    return res;
	}
};
