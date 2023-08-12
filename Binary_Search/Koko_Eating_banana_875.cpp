// https://leetcode.com/problems/koko-eating-bananas/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool ispossible(vector<int> piles, int mid, int h) {
       long long int hours_needed = 0;
        for (int p : piles) 
        {
            // Division operation used to round do round off
            hours_needed += (p + mid - 1) / mid;
        }
        return hours_needed <= h;
    }


    int minEatingSpeed(vector<int>& piles, int h) {

        sort(piles.begin() , piles.end());

        int start = 1;

        int end = piles[piles.size() - 1];
        int mid = start + (end - start)/2;
        int ans = -1;
        while(start <= end)
        {
            if(ispossible(piles , mid , h))
            {
                ans = mid;
                
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
           
        }

        return ans;       
    }
};


class Solution {
public:

    bool ispossible(std::vector<int> piles, int mid, int h) {
        long long int hours_needed = 0;
        for (int p : piles) {
            hours_needed += (p + mid - 1) / mid;
        }
        return hours_needed <= h;
    }

    int minEatingSpeed(std::vector<int>& piles, int h) {
        std::sort(piles.begin(), piles.end());

        int start = 1;
        int end = piles[piles.size() - 1];
        int mid = start + (end - start) / 2;
        int ans = -1;
        while (start <= end) {
            if (ispossible(piles, mid, h)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Sample input: piles = {3, 6, 7, 11}, h = 8
    std::vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int min_eating_speed = solution.minEatingSpeed(piles, h);

    std::cout << "Minimum eating speed required: " << min_eating_speed << std::endl;

    return 0;
}
