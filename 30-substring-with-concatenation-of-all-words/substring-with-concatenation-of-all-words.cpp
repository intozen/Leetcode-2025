// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         /*
//             s = "barfoothefoobarman"
//             words = ["foo","bar"]
//             foobar
//             barfoo

//             [0, 9]
//             wordgoodgoodgoodbestword
//             words = ["word","good","best","word"]
//             wordgoodbestword
//             wordbestgoodword
//             wordwordgoodbest
//             wordgoodwordbest
//             wordgood

//             []

//             barfoofoobarthefoobarman
//             words = ["bar","foo","the"]
//             barfoothe
//             barthefoo
//             foothebar
//             foobarthe
//             thefoobar
//             thebarfoo

//             [6, 9, 12]


//         */

//         unordered_map<string, int> mp;
//         for (auto it : words) {
//             mp[it]++;
//         }
//         vector<int> ans;
//         unordered_map<string, int> mp2 = mp;
//         int len = words[0].size();
        
//         int n = s.size();
//         int j = 0;
//         int wordlen = words.size();
//         int totallen = len * wordlen;

//          for (int offset = 0; offset < len; offset++) {

//             int i = offset;

//          }
//         if (n < totallen)
//             return ans;

//         while (i + totallen <= n) { 
//             int j = i;
//             mp2 = mp;

            
//             while (j + len <= n) {

//                 if (j - i == totallen) break;

//                 string k = s.substr(j, len);
//                 if (mp2[k]) {
//                     mp2[k]--;
//                     j = j + len;
//                     if (mp2[k] == 0) {
//                         mp2.erase(k);
//                     }
//                     if(mp2.empty()) { 
//                         ans.push_back(i);
//                         break;
//                     }
//                 } else {
//                     break;
//                 }
//             }
//             i++;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        int wordCount = words.size();
        int wordLen = words[0].size();
        if (wordLen == 0) return ans;

        int n = s.size();
        int windowLen = wordCount * wordLen;
        if (n < windowLen) return ans;

        unordered_map<string,int> freq;
        for (auto &w : words) freq[w]++;

        // Try each offset 0..wordLen-1
        for (int offset = 0; offset < wordLen; ++offset) {
            int left = offset;
            int count = 0; // how many words currently in window
            unordered_map<string,int> seen;

            // slide right in steps of wordLen
            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string w = s.substr(right, wordLen);

                // if this piece is a valid word
                if (freq.count(w)) {
                    seen[w]++;
                    count++;

                    // if seen exceeds allowed, shrink from left
                    while (seen[w] > freq[w]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // If window has exactly wordCount words, record start
                    if (count == wordCount) {
                        ans.push_back(left);
                        // move left forward by one word to look for next possibility
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                } else {
                    // not a word — reset window after this position
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};
