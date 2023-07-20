class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(ans.size()==0){
                ans.push_back(asteroids[i]);
            }else{
                if(ans.back()>0&&asteroids[i]<0){
                    if(ans.back()==abs(asteroids[i])){
                        ans.pop_back();
                    }else if(abs(asteroids[i])>ans.back()){
                        ans.pop_back();
                        // 5 8 -9
                        if(ans.size()==0){
                            ans.push_back(asteroids[i]);
                        }else{
                            i--;
                        }
                    }
                }else{
                    ans.push_back(asteroids[i]);
                }
            }
        }
        return ans;
    }
};
