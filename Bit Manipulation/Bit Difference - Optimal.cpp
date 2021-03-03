class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        a = a^b;  //Now the position where there is 1 means that at that positions of a and b bits must be different as 0^1 = 1 and 1^0 = 1
        
        int count = 0;
        //Count the set bits 
        while(a){
            a = a & (a-1);
            count++;
        }
        return count;
    }
};
