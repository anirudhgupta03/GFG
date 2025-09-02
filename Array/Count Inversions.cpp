class Solution {
  public:
    int ans;
    void countInversion(int lo, int mid, int hi, vector<int> &arr){
        
        vector<int> lr, rr;
        
        for(int i = lo; i <= mid; i++){
            lr.push_back(arr[i]);
        }
        for(int i = mid + 1; i <= hi; i++){
            rr.push_back(arr[i]);
        }
        
        int ptr1 = 0, ptr2 = 0, ptr3 = lo;
        while(ptr1 < lr.size() && ptr2 < rr.size()){
            if(lr[ptr1] > rr[ptr2]){
                arr[ptr3] = rr[ptr2];
                ans += lr.size() - ptr1;
                ptr2++;
            }
            else{
                arr[ptr3] = lr[ptr1];
                ptr1++;
            }
            ptr3++;
        }
        while(ptr1 < lr.size()){
            arr[ptr3] = lr[ptr1];
            ptr1++;
            ptr3++;
        }
        while(ptr2 < rr.size()){
            arr[ptr3] = rr[ptr2];
            ptr2++;
            ptr3++;
        }
    }
    void solve(int lo, int hi, vector<int> &arr){
        
        if(lo >= hi){
            return;
        }
        int mid = lo + (hi - lo)/2;
        solve(lo, mid, arr);
        solve(mid + 1, hi, arr);
        countInversion(lo, mid, hi, arr);
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        ans = 0;
        int n = arr.size();
        solve(0, n - 1, arr);
        return ans;
    }
};
