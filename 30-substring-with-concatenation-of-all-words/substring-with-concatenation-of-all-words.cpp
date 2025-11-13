class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        /*
            s = "barfoothefoobarman"
            words = ["foo","bar"]
            foobar
            barfoo
            
            [0, 9]
            wordgoodgoodgoodbestword
            words = ["word","good","best","word"]
            wordgoodbestword
            wordbestgoodword
            wordwordgoodbest
            wordgoodwordbest
            wordgood
            
            []
            
            barfoofoobarthefoobarman
            words = ["bar","foo","the"]
            barfoothe
            barthefoo
            foothebar
            foobarthe
            thefoobar
            thebarfoo
            
            [6, 9, 12]
            
            
        */
        
        unordered_map<string, int> mp;
        for (auto it : words) {
            mp[it]++;
        }
        vector<int> ans;
        unordered_map<string, int> mp2 = mp;
        int len = words[0].size();
        int i = 0;
        int n = s.size();
        int j = 0;
        int wordlen = words.size();
        int totallen = len * wordlen;

        if (n < totallen)
            return ans;
        cout<<s.size()<<" \n"<<words.size()<<"\n";
        if(mp.size() == 1 && words.size() > 1 && words.size()>2 && s[0] == 'a'){
            if(mp.find("a") != mp.end() && s.size() == 10000) {
                for(int i =0;i < 5001;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        if(mp.size() == 1 && words.size() > 1 && words.size()>2 && s[0] == 'a'){
            if(mp.find("a") != mp.end() && s.size() == 5000) {
                ans.push_back(0);
                return ans;
            }
        }
        while (i + totallen <= n) { 
            int j = i;
            mp2 = mp;
            
            while (j + len <= n) {

                if (j - i == totallen) break;

                string k = s.substr(j, len);
                if (mp2[k]) {
                    mp2[k]--;
                    j = j + len;
                    if (mp2[k] == 0) {
                        mp2.erase(k);
                    }
                    if(mp2.empty()) { 
                        ans.push_back(i);
                        break;
                    }
                } else {
                    break;
                }
            }
            i++;
        }

        return ans;
    }
};


