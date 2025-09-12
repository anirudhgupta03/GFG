//https://www.youtube.com/watch?v=D1oDwWCq50g&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=23
//Method - 1
class Solution {
  public:
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k) {
        // code here
        if(nums1.size() > nums2.size()){
            return kthElement(nums2, nums1, k);
        }
        int m = nums1.size(), n = nums2.size();
        int lo = max(0, k - n), hi = min(k, m);
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int ul = INT_MIN, ur = INT_MAX, bl = INT_MIN, br = INT_MAX;
            if(mid > 0){
                ul = nums1[mid - 1];
            }
            if(mid < m){
                ur = nums1[mid];
            }
            if(k - mid - 1 >= 0){
                bl = nums2[k - mid - 1];
            }
            if(k - mid < n){
                br = nums2[k - mid];
            }
            
            if(ul <= br && bl <= ur){
                return max(ul, bl);
            }
            else if(ul > br){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return -1;
    }
};

//Method - 2
class Solution {
  public:
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k) {
        // code here
        if(nums1.size() > nums2.size()){
            return kthElement(nums2, nums1, k);
        }

        int m = nums1.size(), n = nums2.size();

        int lo = 0, hi = m;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            if(mid > k){
                hi = mid - 1;
                continue;
            }
            if(k - mid > n){
                lo = mid + 1;
                continue;
            }
            
            int ul = INT_MIN, ur = INT_MAX, bl = INT_MIN, br = INT_MAX;
            
            if(mid > 0){
                ul = nums1[mid - 1];
            }

            if(mid < m){
                ur = nums1[mid];
            }

            if(k - mid - 1 >= 0){
                bl = nums2[k - mid - 1];
            }
            
            if(k - mid < n){
                br = nums2[k - mid];
            }
            
            if(ul <= br && bl <= ur){
                return max(ul, bl);
            }
            else if(ul > br){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return -1;
    }
};
