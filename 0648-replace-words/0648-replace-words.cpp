class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word, res;
        
        while (ss >> word) {
            string prefix;
            for (int i = 1; i <= word.size(); ++i) {
                prefix = word.substr(0, i);
                if (dict.count(prefix)) {
                    word = prefix;
                    break;
                }
            }
            res += word + " ";
        }
        
        res.pop_back();
        return res;
    }
};