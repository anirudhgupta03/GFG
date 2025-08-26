class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largestEle = -1, secondLargestEle = -1;
        
        for(int i: arr){
            if(i > largestEle){
                secondLargestEle = largestEle;
                largestEle = i;
            }
            else if(i > secondLargestEle && i != largestEle){
                secondLargestEle = i;
            }
        }
        return secondLargestEle;
    }
};
