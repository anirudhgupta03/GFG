class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        
        vector<vector<int>> res;
        
        int minEle = INT_MAX, maxEle = INT_MIN, minInd, maxInd = -1, turn = 0;
        
        bool flag = false;
        
        for(int i = 0; i < A.size(); i++){
            
            if(turn == 0){
                if(flag){
                    vector<int> temp = {minInd,maxInd};
                    maxInd = -1;
                    res.push_back(temp);
                    flag = 0;
                }
                if(A[i] <= minEle){
                    minEle = A[i];
                    minInd = i;
                }
                else{
                    maxEle = INT_MIN;
                    i--;
                    turn = 1;
                }
            }
            else{
                if(A[i] >= maxEle){
                    maxEle = A[i];
                    maxInd = i;
                }
                else{
                    i--;
                    minEle = INT_MAX;
                    flag = 1;
                    turn = 0;
                }
            }
        }
        if(!flag && maxInd != -1){
            vector<int> temp = {minInd,maxInd};
            res.push_back(temp);
        }
        return res;
    }
};
