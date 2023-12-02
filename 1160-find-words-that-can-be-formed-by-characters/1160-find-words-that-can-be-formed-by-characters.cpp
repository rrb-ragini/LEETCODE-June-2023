#include <vector>
#include <string>
#include <map>

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> m;
        int count = 0;
        
        // Count the frequency of each character in chars
        for (auto c : chars) {
            m[c]++;
        }
        
        // Check if a word can be formed using the characters in chars
        for (auto word : words) {
            map<char, int> mp = m;
            bool canFormWord = true;

            for (auto j : word) {
                if (mp.find(j) != mp.end() && mp[j] > 0) {
                    mp[j]--;
                } else {
                    canFormWord = false;
                    break;
                }
            }

            if (canFormWord) {
                count += word.size();
            }
        }

        return count;
    }
};
