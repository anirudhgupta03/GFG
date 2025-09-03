//Ref: https://www.youtube.com/watch?v=n7uwj04E0I4&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=24
//Start comparing from the last of the first array and from the start of the second array
//then check if the element in the array is greater then swap with the element in the second array else break
//Method - 1
class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	        int i=n-1,j=0;
	        while(j<m && i>=0){
	            if(arr1[i]>arr2[j]){
	                swap(arr1[i],arr2[j]);
	                i--;
	                j++;
	            }
	            else{
	                break;
	            }
	        }
	        sort(arr1,arr1+n);
	        sort(arr2,arr2+m);
	}
};

//Method - 2
//Gap Method
//TC: O((N+M)*log(N+M))
//SC: O(1)
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size();
        int len = n + m;
        int gap = (len/2) + (len%2);
        
        while(gap > 0){
            int left = 0;
            int right = gap;
            while(right < len){
                if(left < n && right >= n){
                    if(a[left] > b[right - n]){
                        swap(a[left], b[right - n]);
                    }
                }
                else if(left >= n){
                    if(b[left - n] > b[right - n]){
                        swap(b[left - n], b[right - n]);
                    }
                }
                else{
                    if(a[left] > a[right]){
                        swap(a[left], a[right]);
                    }
                }
                left++;
                right++;
            }
            if(gap == 1) break;
            gap = (gap/2) + (gap %2);
        }
    }
};
