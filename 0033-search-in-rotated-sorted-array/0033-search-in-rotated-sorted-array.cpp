class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        while(h>=l){
            int m=(h+l)/2;
            int mid=nums[m];
            if(target==mid){
                return m;
            }else if(nums[l]<=mid){
                if(target>=nums[l]&&target<=mid){
                    h=m-1;
                }else{
                    l=m+1;
                }
            }else{
                if(target>=mid&&target<=nums[h]){
                    l=m+1;
                }else{
                    h=m-1;
                }
            }
        }
        return -1;
    }
};