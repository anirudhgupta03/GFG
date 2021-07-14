//Ref: https://www.youtube.com/watch?v=8nx5dxFuvLo
class Solution{
public:
	bool recreationalSpot(int arr[], int n){
		
		int premin[n];
		premin[0] = arr[0];
		
		for(int i = 1; i < n; i++){
		    premin[i] = min(premin[i-1],arr[i]);
		}
		
		stack<int> st;
		for(int j = n - 1; j >= 0; j--){
		    if(arr[j] > premin[j]){
		        
		        while(!st.empty() && st.top() <= premin[j]){
		            st.pop();
		        }
		        if(!st.empty() && st.top() < arr[j]){
		            return true;
		        }
		        st.push(arr[j]);
		    }
		}
		
		return false;
	}
};
