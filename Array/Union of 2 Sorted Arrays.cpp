class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int m = a.size(), n = b.size();
        int ptr1 = 0, ptr2 = 0;
        
        vector<int> res;
        
        while(ptr1 < m && ptr2 < n){
            if(a[ptr1] <= b[ptr2]){
                int ele = a[ptr1];
                res.push_back(ele);
                
                while(ptr1 < m && a[ptr1] == ele) ptr1++;
                while(ptr2 < n && b[ptr2] == ele) ptr2++;
            }
            else{
                int ele = b[ptr2];
                res.push_back(ele);
                
                while(ptr2 < n && b[ptr2] == ele) ptr2++;
            }
        }
        
        while(ptr1 < m){
            int ele = a[ptr1];
            res.push_back(a[ptr1]);
            while(ptr1 < m && a[ptr1] == ele) ptr1++;
        }
        
        while(ptr2 < n){
            int ele = b[ptr2];
            res.push_back(b[ptr2]);
            while(ptr2 < n && b[ptr2] == ele) ptr2++;
        }
        
        return res;
    }
};
