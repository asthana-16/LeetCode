class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, char>mp1,mp2;
        for(int i=0;i<s.length();i++){
            char s1=s[i];
            char t1=t[i];
            if(mp1.count(s1) && mp1[s1] != t1) return false;
            if(mp2.count(t1) && mp2[t1] != s1) return false;
            mp1[s1] = t1;
            mp2[t1] = s1;
        }
        return true;
    }
};