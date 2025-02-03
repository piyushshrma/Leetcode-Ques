class Solution {
public:
    string removing(string str, string part, int len) {
        int st = str.find(part);
        str.erase(st, len);  // Erase the found part
        return str;
    }

    string removeOccurrences(string str, string part) {
        int len = part.length();
        while (str.length()>0 && (str.find(part) < str.length())) {  // Keep removing part while it's found
            str = removing(str, part, len);  // Reassign the result back to str
        }
        return str;
    }
};
