#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const string& word : strs) {
            int count[26] = {0};

            for (char c : word) {
                count[c - 'a']++;
            }

            string key;
            key.reserve(52);  // small optimization

            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]);
                key += '#';
            }

            mp[key].push_back(word);
        }

        vector<vector<string>> result;
        result.reserve(mp.size());

        for (auto& it : mp) {
            result.push_back(move(it.second));
        }

        return result;
    }
};