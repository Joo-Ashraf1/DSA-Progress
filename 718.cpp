#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ull = unsigned long long;
    const ull BASE1 = 131, MOD1 = 1e9 + 7;
    const ull BASE2 = 137, MOD2 = 1e9 + 9;

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int lo = 0, hi = min(nums1.size(), nums2.size()), ans = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (solve(nums1, nums2, mid)) {
                ans = mid;
                lo = mid + 1;  
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    bool solve(vector<int>& nums1, vector<int>& nums2, int len) {
        if (len == 0) return true;

        ull pow1 = 1, pow2 = 1;
        for (int i = 0; i < len - 1; i++) {
            pow1 = pow1 * BASE1 % MOD1;
            pow2 = pow2 * BASE2 % MOD2;
        }
        unordered_set<ull> seen;
        ull h1 = 0, h2 = 0;
        for (int i = 0; i < len; i++) {
            h1 = (h1 * BASE1 + nums1[i]) % MOD1;
            h2 = (h2 * BASE2 + nums1[i]) % MOD2;
        }
        seen.insert(h1 << 32 | h2);  

        for (int i = len; i < (int)nums1.size(); i++) {
            h1 = (h1 - (ull)nums1[i - len] * pow1 % MOD1 + MOD1) % MOD1;
            h1 = (h1 * BASE1 + nums1[i]) % MOD1;

            h2 = (h2 - (ull)nums1[i - len] * pow2 % MOD2 + MOD2) % MOD2;
            h2 = (h2 * BASE2 + nums1[i]) % MOD2;

            seen.insert(h1 << 32 | h2);
        }
        h1 = h2 = 0;
        for (int i = 0; i < len; i++) {
            h1 = (h1 * BASE1 + nums2[i]) % MOD1;
            h2 = (h2 * BASE2 + nums2[i]) % MOD2;
        }
        if (seen.count(h1 << 32 | h2)) return true;

        for (int i = len; i < (int)nums2.size(); i++) {
            h1 = (h1 - (ull)nums2[i - len] * pow1 % MOD1 + MOD1) % MOD1;
            h1 = (h1 * BASE1 + nums2[i]) % MOD1;

            h2 = (h2 - (ull)nums2[i - len] * pow2 % MOD2 + MOD2) % MOD2;
            h2 = (h2 * BASE2 + nums2[i]) % MOD2;

            if (seen.count(h1 << 32 | h2)) return true;
        }
        return false;
    }
};