class Solution {
public:
    string makeGood(string s) {
        string st; //treat as a stack
        for(char c:s){
            if(!st.empty() && abs(c-st.back()) == 32){
                st.pop_back();
            }else{
                st.push_back(c);
            }
        }
        return st;
    }
};