class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(string s : strs){
            int num=s.length();
            encoded=encoded+to_string(num)+'#'+s;
        
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
    int start=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='#'){
            string len=s.substr(start,i-start);
            int wordStart=len.length();
            int length=stoi(len);
            string str=s.substr(start+wordStart+1,length);
            ans.push_back(str);
            start=start+wordStart+1+length;
            i=start-1;
        }
    }
    return ans;
    }
};
