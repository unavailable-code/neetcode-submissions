class Solution {
public:
    bool isPalindrome(string s) {
    int l=0,r=s.length()-1;
    while(l<r){
        if(!iswalnum(s[l])){
            l++;
            continue;
        }
        if(!iswalnum(s[r])){
            r--;
            continue;
        }
        if((char)tolower(s[l])!=(char)tolower(s[r])){
            return false;
        }
        l++;
        r--;
    }
    return true;
    }
};
