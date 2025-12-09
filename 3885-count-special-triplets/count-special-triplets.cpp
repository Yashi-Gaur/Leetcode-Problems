class Solution {
public:
    const long long MOD = 1000000007LL;   // modulo constant

    int specialTriplets(vector<int>& nums) {
        
        unordered_map<int, int> mppPrev;  // counts of numbers seen on LEFT of current index
        unordered_map<int, int> mppNext;  // counts of numbers on RIGHT of current index

        // fill mppNext with full frequency of all numbers
        for (int x : nums) 
        {
            mppNext[x]++;
        }

        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) 
        {
            int cur = nums[i];    // middle element (j position)

            // reduce its count from right side because now we are at position j
            mppNext[cur]--;
            if (mppNext[cur] == 0) mppNext.erase(cur);

            // update left count with element just before j
            int prev = i - 1;
            if (prev >= 0) 
                mppPrev[nums[prev]]++;

            // value needed on both sides = 2 * nums[j]
            int req = cur * 2;

            // check if required value exists on both left and right
            if (mppPrev.find(req) != mppPrev.end() && mppNext.find(req) != mppNext.end()) 
            {
                long long cnt1 = mppPrev[req];   // number of required values on left
                long long cnt2 = mppNext[req];   // number of required values on right

                // multiply and add to answer with modulo
                ans = (ans + (cnt1 * cnt2) % MOD) % MOD;
            }
        }

        return (int)ans;
    }
};
