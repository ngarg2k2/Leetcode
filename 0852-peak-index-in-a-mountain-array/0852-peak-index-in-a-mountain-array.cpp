class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int l=0;
        int h=arr.size()-1;
        int m=(l+h)/2;
        while(h>=l){
            if(arr[m]>arr[m-1]&&arr[m]>arr[m+1]){
                return m;
            }else if(arr[m]>arr[m-1]){
                l=m;
            }else{
                h=m;
            }
            m=(l+h)/2;
        }
        return m;
    }
};