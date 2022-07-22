
#include <vector>
using namespace std;

class Solution {
    
    inline static const int MAX_ABSOLUTE_VALUE = static_cast<int> (pow(10, 4));
    
public:
    int arrayPairSum(vector<int>& nums) {
        
        vector<int> frequency(2 * MAX_ABSOLUTE_VALUE + 1);
        for (const auto& n : nums) {
            ++frequency[n + MAX_ABSOLUTE_VALUE];
        }

        int countPairs = 0;
        int totalPairs = nums.size() / 2;
        int remainderToCompleteStartedPair = 0;

        for (int i = 0; i < frequency.size() && totalPairs > 0; ++i) {

            frequency[i] -= remainderToCompleteStartedPair;
            if (frequency[i] == 0) {
                remainderToCompleteStartedPair = 0;
                continue;
            }

            if (frequency[i] > 0) {
                countPairs += ((frequency[i] + 1) / 2) * (i - MAX_ABSOLUTE_VALUE);
                totalPairs -= (frequency[i] + 1) / 2;
                remainderToCompleteStartedPair = max(frequency[i], 0) % 2;
            }

        }
        return countPairs;
    }
};
