class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1,high=10000009;
        while(low<high){
            int mid=(low+high)/2;
            double time=0;
            for(auto it:dist){
                if(time>(int)time){
                    time=double((int)time+1);
                }
                time+=((double)it)/((double)mid);
            }
            if(time>hour){
                low=mid+1;  
            } 
            else{
                high=mid;  
            } 
        }
        return (low>10000000 ? -1 : low);
    }
};