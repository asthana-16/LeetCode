class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int start=0, end=1, maxlen=0;
        unordered_set<char>st;
        for(int end =0;end<n;end++){
            while(st.count(s[end])){
                st.erase(s[start]);
                start++;
            }
            st.insert(s[end]);
            maxlen= max(maxlen, end-start+1);
            
        }
        return maxlen;
    }
};