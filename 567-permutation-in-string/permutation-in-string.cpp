class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
           ab eidbaooo
           
           mp1 where s1 chars are stored with their number of occurences 
           cnt = s1.size();
           for(i in s2)
           if(mp1[i]){
            mp1[i]--;
            while(j<n && mp2[s[j]] > 0 && cnt<k){
                if(mp1[j])
                    j++;
                    mp1[j]--;
            }
           }
           
        */
        
        /*
            algo by ayan -- >
            1.put two pointers left and right
            2.go to right and upgrade the frequency of current
            3.if(size of right-left==size of string 1&&freq1==freq2)
            4.return true;
            5.else upgrade the left counter subract the frequency
            6.and keep checking 
            
       */
        int left = 0;
        int right = 0;
        int n = s2.size();
        int m = s1.size();
        if(m>n)
            return false;
        vector<int>fre1(26,0);
        vector<int>fre2(26,0);
        
        for(int i=0;i<m;i++)
        {
            fre1[s1[i]-'a']++;
        }
        
        while(right<s2.size())
        {
            fre2[s2[right]-'a']++;
            if(right-left+1==s1.size()&&fre2==fre1)
                return true;
            else if(right-left+1<s1.size())
            {
                right++;
            }
            else{
                fre2[s2[left]-'a']--;
                left++;
                right++;
            }
        }
        return false;
    }
};