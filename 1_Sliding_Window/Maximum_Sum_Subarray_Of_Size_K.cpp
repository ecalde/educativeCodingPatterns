using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
public:
    static int findMaxSumSubArray(int k, const vector<int>& arr) {
        int windowSum = 0, maxSum = 0;
        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
            windowSum += arr[windowEnd];  // add the next element
            // slide the window, we don't need to slide if we've not hit the required window size of 'k'
            if (windowEnd >= k - 1) {
                maxSum = max(maxSum, windowSum);
                windowSum -= arr[windowStart];  // subtract the element going out
                windowStart++;                  // slide the window ahead
            }
        }

        return maxSum;
    }
};

