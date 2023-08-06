class Solution {
public:
    bool isValid(string ss) {
        stack<char>s;
        for(auto i:ss){
            if(i=='('||i=='['||i=='{'){
                s.push(i);
            }else{
                if(s.empty()){
                    return false;
                }
                char ch=s.top();
                if(i==')'&&ch=='('||i==']'&&ch=='['||i=='}'&&ch=='{'){
                    s.pop();
                }else{
                    return false;
                }
            }
        }
        return s.empty();
    }
};