class Solution {
public:
    bool isPossible(vector<int>&weights,int days,int mid){
        int d=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=mid){
                sum+=weights[i];
            }else{
                d++;
                // weights[i]>mid  -> this cnd bcz array given is not sorted
                if(d>days||weights[i]>mid){
                    return false;
                }
                sum=weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start=0;
        int end=0;
        for(auto i:weights){
            end+=i;
        }
        int ans=0;
        int mid=start+(end-start)/2;
        while(end>=start){
            if(isPossible(weights,days,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }
};