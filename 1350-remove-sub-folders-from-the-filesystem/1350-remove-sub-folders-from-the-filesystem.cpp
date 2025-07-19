class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        for(const auto& a : folder){
            if(res.empty()) res.push_back(a);
            else{
                const string& prev = res.back();
                if(a.find(prev) == 0 && a.size()>prev.size() && a[prev.size()]=='/'){
                    continue;
                }
                else{
                    res.push_back(a);
                }
            }
        }
        return res;
    }
};