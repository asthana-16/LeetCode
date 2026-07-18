class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> st;
        string result = "";
        int i=0;
        while(i<n){
            while(i<n && path[i]== '/') i++;
            string temp ="";
            while(i<n && path[i]!='/'){
                temp += path[i];
                i++;
            }
            if(temp == ".."){
                if(!st.empty()) st.pop_back();
                continue;
            }
            if(temp == "." || temp =="") continue;
            else st.push_back(temp);
        }
        for(string s: st){
            result += "/" +s;
        }
        return result.empty() ? "/" : result;
    }
};