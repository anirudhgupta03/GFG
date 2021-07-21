class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int p1 = 0, p2 = 0, p3 = 0;
            
            vector<int> res;
            
            while(p1 < n1 && p2 < n2 && p3 < n3){
                
                int maxEle = max({A[p1],B[p2],C[p3]});
                
                if(A[p1] == B[p2] && B[p2] == C[p3]){
                    res.push_back(A[p1]);
                    while(p1 < n1 - 1 && A[p1] == A[p1+1]) p1++;
                    p1++;
                    while(p2 < n2 - 1 && B[p2] == B[p2+1]) p2++;
                    p2++;
                    while(p3 < n3 - 1 && C[p3] == C[p3+1]) p3++;
                    p3++;
                    continue;
                }
                if(A[p1] < maxEle) p1++;
                if(B[p2] < maxEle) p2++;
                if(C[p3] < maxEle) p3++;
            }
            
            return res;
        }

};
