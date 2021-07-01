class Solution{  
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int count = 0, ele;
        ele = a[0];
        count = 1;
        
        for(int i = 1; i < size; i++){
            
            if(ele != a[i]){
                count--;
            }
            else{
                count++;
            }
            
            if(count == 0){
                ele = a[i];
                count = 1;
            }
        }
        count = 0;
        
        for(int i = 0; i < size; i++){
            
            if(a[i] == ele){
                count++;
            }
        }
        
        if(count > size/2){
            return ele;
        }
        
        return -1;
    }
};
