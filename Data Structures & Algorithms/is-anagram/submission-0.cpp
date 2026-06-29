class Solution {
public:
    bool isAnagram(string s, string t) {
     bool flag = true;
    if (s.length() != t.length())
    {
        flag = false;
    }
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;
    for (int x : s)
    {
        m1[x]++;
    }
    for (int x : t)
    {
        m2[x]++;
    }
    // cout << "\n Checking if m1 == m2" << "\n";
    if (m1 == m2)
    {
        // cout << "true";
        return true;
    }
    else
    {
        // cout << "False";
        return false;
    }   
    }
};
