//Dutch National Flag Algorithm
class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int lo = 0, mid = 0, hi = array.size() - 1;
        
        while(mid <= hi){
            
            if(array[mid] < a){
                swap(array[mid],array[lo]);
                lo++;
                mid++;
            }
            else if(array[mid] > b){
                swap(array[mid],array[hi]);
                hi--;
            }
            else{
                mid++;
            }
        }
    }
};
