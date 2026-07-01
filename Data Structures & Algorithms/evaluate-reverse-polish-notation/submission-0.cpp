class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack <int> st;
    for(int i=0;i<tokens.size();i++){
        if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
            int output=0;
            int op1= st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            if(tokens[i]=="+"){
                output=op1+op2;
            }
            else if(tokens[i]=="-"){
                output=op2-op1;
            }
            else if(tokens[i]=="*"){
                output=op1*op2;
            }
            else{
                output=op2/op1;
            }
            st.push(output);
        }
        else{
            st.push(stoi(tokens[i]));
        }
    }
    return st.top();
    }
};
