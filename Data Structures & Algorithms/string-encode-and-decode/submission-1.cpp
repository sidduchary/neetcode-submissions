class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.size() == 0) return "";
        
        string ec;
        for(auto& str: strs) ec+= (to_string(str.size())+",");
        ec[ec.size()-1] = '@';
        for(auto& str: strs) ec+= str;
        return ec;
    }

    vector<string> decode(string s) {
        if (s.size()== 0) return {};

        vector<int> siz;
        int n = s.size();
        int start = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == ',' || s[i] == '@') {
                siz.push_back(stoi(s.substr(start, i-start)));
                start = i+1;
                if (s[i] == '@') break;
            }
        }

        vector<string> res;
        for(int& it: siz) {
            res.push_back(s.substr(start,it));
            start+=it;
        }
        return res;
    }
};
