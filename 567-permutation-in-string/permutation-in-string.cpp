class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> f1(26,0);
        vector<int> f2(26,0);
        for(int i =0;i<s1.length();i++){
            f1[s1[i]-'a']++;
        }
        int k = s1.length();
        for(int i=0;i<k;i++){
            f2[s2[i]-'a']++;
        }
        if(f1 == f2) return true;
        for(int i=k;i<s2.length();i++){
            f2[s2[i]-'a']++;
            f2[s2[i-k]-'a']--;
            if(f1 == f2) return true;
        }
        return false;
    }
};