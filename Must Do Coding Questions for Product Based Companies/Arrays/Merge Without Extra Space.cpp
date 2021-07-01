//Time Complexity - O(NlogN + MlogM)
//Space Complexity - O(1)
class Solution{
public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int l = n - 1, r = 0;
            
            while(l >= 0 && r < m){
                
                if(arr1[l] > arr2[r]){
                    swap(arr1[l],arr2[r]);
                    l--;
                    r++;
                }
                else{
                    break;
                }
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
};
