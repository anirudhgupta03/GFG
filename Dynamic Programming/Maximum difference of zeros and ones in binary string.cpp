class Solution{
public:	
	int maxSubstring(string S)
	{
	    int currSum = 0, maxSum = INT_MIN;
	    
	    for(int i = 0; i < S.size(); i++){
	        
	        if(S[i] == '0') currSum += 1;
	        else currSum -= 1;
	        
	        maxSum = max(maxSum,currSum);
	        
	        if(currSum < 0){
	            currSum = 0;
	        }
	    }
	    
	    return maxSum;
	}
};
