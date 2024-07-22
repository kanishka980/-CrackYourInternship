class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                st1.push(s[i]);
            } else if (!st1.empty() && s[i] == '#') {
                st1.pop();
            }
        }
        for (int i = 0; i < t.length(); i++) {
            if (t[i] >= 'a' && t[i] <= 'z') {
                st2.push(t[i]);
            } else if ( !st2.empty() && t[i] == '#') {
                st2.pop();
            }
        }

        if (st1 == st2) {
            return true;
        } else {
            return false;
        }
    }
};
