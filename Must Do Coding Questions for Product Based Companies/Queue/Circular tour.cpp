struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int s = 0, d = 0;
       
       int start = 0;
       
       for(int i = 0; i < n; i++){
           
           if(s + p[i].petrol >= p[i].distance){
               s = s + p[i].petrol - p[i].distance;
           }
           else{
               start = (i + 1)%n;
               d += s + p[i].petrol - p[i].distance;
               s = 0;
           }
       }
       
       if(s + d >= 0)
       return start;
       
       return -1;
    }
};
