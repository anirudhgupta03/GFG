//https://www.codingninjas.com/codestudio/problems/check-if-possible-to-survive_1170052?leftPanelTab=0
bool isPossibleToSurvive(int n, int x, int d){
    
    if(n < x){
        return false;
    }
    
    int t1 = 6*n, t2 = 6*x;
    
    if(t1 - t2 >= x || d <= 6){
        return true;
    }
    else{
        return false;
    }
}
