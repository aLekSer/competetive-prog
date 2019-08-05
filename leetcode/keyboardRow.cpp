//500. Keyboard Row

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        static regex re("^[qwertyuiopQWERTYUIOP]*|[asdfghjklASDFGHJKL]*|[zxcvbnmZXCVBNM]*$");
        vector<string> ans;
        for (auto& word : words) {
            if (regex_match(word, re)) ans.push_back(word);
        }
        return ans;
    }
};
