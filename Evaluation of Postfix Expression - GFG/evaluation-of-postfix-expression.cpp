//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>s;
        for(auto i:S){
            if(i>='0'&&i<='9'){
                s.push(i-'0');
            }else{
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                if(i=='+'){
                    s.push(a+b);
                }else if(i=='-'){
                    s.push(a-b);
                }else if(i=='*'){
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

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends