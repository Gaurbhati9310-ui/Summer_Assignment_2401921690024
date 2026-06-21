class Solution {
public:
    int operate(int a ,int b,string tokens){
        if(tokens == "+"){
            return b+a;
        }
        if(tokens == "-"){
            return b-a;
        }
        if(tokens == "*"){
            return (long)b*(long)a;
        }
        if(tokens == "/"){ 
            return b/a;
        }
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n =tokens.size();
        for(int  i = 0; i<n;i++){
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i]=="/"){
            int a = st.top();
            st.pop();
            int b =st.top();
            st.pop();
            int result=operate(a,b,tokens[i]);
            st.push(result);
        }
        else{
            st.push(stoi(tokens[i]));
        }
        }
        return st.top();
    }
};
