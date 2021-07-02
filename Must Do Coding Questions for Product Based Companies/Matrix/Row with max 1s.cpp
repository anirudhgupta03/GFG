//Ref: https://www.youtube.com/watch?v=z092lX-nhik
//Time Complexity - O(M+N)
//Space Complexity - O(1)
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    
	    int i = 0, j = m - 1;
	    
	    int count = 0, row = -1;
	    
	    while(i >= 0 && i < n && j >= 0 && j < m){
	        
	        if(arr[i][j] == 1){
	            count++;
	            row = i;
	            j--;
	        }
	        else{
	            i++;
	        }
	    }
	    return row;
	}

};
