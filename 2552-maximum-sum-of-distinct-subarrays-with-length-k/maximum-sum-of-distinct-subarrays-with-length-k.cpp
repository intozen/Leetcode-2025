class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        /*
            use a map if the size of the map == k for k consecutive elements then 
            basically condition of subarray is satisfied and check the sum and return it 
            compare to max and return max as ans 
        */
        long long ans = 0;
        map<int,int>mp;
        int i = 0;
        int n = nums.size();
        long long sum = 0;
        for(int j = 0;j < k;j++){
            mp[nums[j]]++;
            sum += nums[j];
        }
        long long mx = 0;
        if(mp.size() == k){
            mx = sum;
        }
        
        // for(i = 1; i < n; i++) {
        //     mp[nums[i-1]]--;
        //     if(mp[nums[i-1]] == 0) {
        //         mp.erase(nums[i-1]);
        //     }
        //     if(i+k-1 < n)
        //         mp[nums[i+k-1]]++;
        //     else break;
            
        //     if(mp.size() == k){
        //         sum -= nums[i-1];
        //         sum += nums[i+k-1];
        //         mx = max(sum, mx);
        //     }
        //     else {
        //         i = i+k-1;
        //     }
            
        // }
        // return mx;
        i = k;
        while(i < nums.size()){
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] == 0) mp.erase(nums[i-k]);
            
            sum += nums[i];
            sum -= nums[i-k];
            if(mp.size() == k )
                mx = max(mx, sum);
            i++;
        }
        return mx;
    }
};