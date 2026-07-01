class Solution {
public:
    bool isValid(string s) {
    stack <char> st;
    if(s.length()%2!=0) return false;
    for(char c: s){
        if( c=='(' || c=='[' || c=='{'){
            st.push(c);
        }   
        else if(st.size()<=0){
            return false;
        }
        else{
            if(abs(int(st.top()-int(c)))<=2){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    if(st.size()>0){
        return false;
    }
    return true;
    }
};
