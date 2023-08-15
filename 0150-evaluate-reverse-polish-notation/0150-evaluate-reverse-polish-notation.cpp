class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto i:tokens){
            if((i.length()>1)||(i>="0"&&i<="9")){
                s.push(stoi(i));
            }else{
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                if(i=="+"){
                    s.push(a+b);
                }else if(i=="-"){
                    s.push(a-b);
                }else if(i=="*"){
                    s.push(a*b);
                }else{
                    if(b==0){
                        s.push(0);
                    }else{
                        s.push(a/b);
                    }
                }
            }
        }
        return s.top();
    }
};