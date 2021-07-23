//Ref: https://www.youtube.com/watch?v=YrtczUOlRC8&t=818s
class Solution{	
  public:
		int AlternatingaMaxLength(vector<int>&nums){
		    
		    
		    int incr = 1, decr = 1;
		    
		    for(int i = 1; i < nums.size(); i++){
		        
		        if(nums[i] > nums[i-1]){
		            incr = decr + 1;
		        }
		        else if(nums[i] < nums[i-1]){
		            decr = incr + 1;
		        }
		    }
		    
		    return max(incr, decr);
		}

};
