
public class Solution {

    private static final int MAX_ABSOLUTE_VALUE = (int) Math.pow(10, 4);

    public int arrayPairSum(int[] nums) {

        int[] frequency = new int[2 * MAX_ABSOLUTE_VALUE + 1];
        for (int n : nums) {
            ++frequency[n + MAX_ABSOLUTE_VALUE];
        }

        int countPairs = 0;
        int totalPairs = nums.length / 2;
        int remainderToCompleteStartedPair = 0;

        for (int i = 0; i < frequency.length && totalPairs > 0; ++i) {

            frequency[i] -= remainderToCompleteStartedPair;
            if (frequency[i] == 0) {
                remainderToCompleteStartedPair = 0;
                continue;
            }

            if (frequency[i] > 0) {
                countPairs += ((frequency[i] + 1) / 2) * (i - MAX_ABSOLUTE_VALUE);
                totalPairs -= (frequency[i] + 1) / 2;
                remainderToCompleteStartedPair = Math.max(frequency[i], 0) % 2;
            }

        }
        return countPairs;
    }
}
