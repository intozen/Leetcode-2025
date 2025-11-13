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
        /*
            Same logic as original:
            - mp stores frequency of target words
            - mp2 used per window
            - check substrings of size len
            But now:
            - We add offset sliding (0 to len-1)
            - Slide by len at a time
            - Maintain window using mp2 and count
        */

        unordered_map<string,int> mp;
        for (auto &it : words) {
            mp[it]++;
        }

        vector<int> ans;
        int len = words[0].size();
        int n = s.size();
        int wordlen = words.size();
        int totallen = len * wordlen;

        if (n < totallen)
            return ans;

        // try every offset
        for (int start = 0; start < len; start++) {

            int i = start;                // left pointer
            int count = 0;                // how many words matched
            unordered_map<string,int> mp2; // seen words

            // slide right pointer j by word length
            for (int j = start; j + len <= n; j += len) {

                string k = s.substr(j, len);

                // valid word
                if (mp.count(k)) {

                    mp2[k]++;
                    count++;

                    // shrink window if exceeded allowed freq
                    while (mp2[k] > mp[k]) {
                        string leftWord = s.substr(i, len);
                        mp2[leftWord]--;
                        i += len;
                        count--;
                    }

                    // if window contains all words
                    if (count == wordlen) {
                        ans.push_back(i);

                        // move left by one word to search further
                        string leftWord = s.substr(i, len);
                        mp2[leftWord]--;
                        i += len;
                        count--;
                    }

                } else {
                    // reset window if invalid word
                    mp2.clear();
                    count = 0;
                    i = j + len;
                }
            }
        }

        return ans;
    }
};
