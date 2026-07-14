class Solution {
public:
    bool checkInclusion(string s1, string s2) {
     vector <int> freq(26,0);
    vector <int> freq2(26,0);
    int l=0,r=0,count=0;
    for(int i=0;i<s1.length();i++){
        freq[s1[i]-'a']++;
    }

    while(r<s2.length()){
        freq2[s2[r]-'a']++;
        if(r-l+1==s1.length()){
            if(freq==freq2){
                return true;
            }
            freq2[s2[l]-'a']--;
            l++;
        }
        r++;
    }
    return false;
    }
};
