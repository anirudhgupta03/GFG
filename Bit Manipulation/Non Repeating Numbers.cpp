class Solution{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xorsum = 0;
        
        for(auto x : nums){
            xorsum = xorsum ^ x;
        }
        
        int setBit = 0, pos = 0, temp = xorsum;
        
        while(setBit != 1){
            setBit = temp & 1;
            pos++;
            temp >>= 1;
        }
      
        int a = 0 , j = (1 << (pos - 1));
        for(auto x : nums){
            
            if((x & j) != 0){
                a = a ^ x;
            }
        }
        vector<int> v;
        v.push_back(a);
        v.push_back(temp^a);
        sort(v.begin(),v.end());
        return v;
    }
};
