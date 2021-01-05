//Start comparing from the last of the first array and from the start of the second array
//then check if the element in the array is greater then swap with the element in the second array else break


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
