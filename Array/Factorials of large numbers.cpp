class Solution {
public:
    vector<int> factorial(int N){
        
        vector<int> v;
        v.push_back(1);
        
        for(int i = 2; i <= N; i++){
            
            int carry = 0;
            
            for(int j = 0; j < v.size(); j++){
                int temp = i*v[j] + carry;
                v[j] = temp%10;
                carry = temp/10;
            }
            
            while(carry){
                v.push_back(carry%10);
                carry /= 10;
            }
        }
        
        reverse(v.begin(),v.end());
        return v;
    }
};
