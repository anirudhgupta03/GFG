//Ref: https://www.youtube.com/watch?v=37E9ckMDdTk
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largestEle = -1, secondLargestEle = -1;
        
        for(int ele: arr){
            if(ele > largestEle){
                secondLargestEle = largestEle;
                largestEle = ele;
            }
            else if(ele > secondLargestEle && ele != largestEle){
                secondLargestEle = ele;
            }
        }
        return secondLargestEle;
    }
};
