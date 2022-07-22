
/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function (nums) {

    const  MAX_ABSOLUTE_VALUE = Math.pow(10, 4);
    const frequency = new Array(2 * MAX_ABSOLUTE_VALUE + 1).fill(0);
    for (let n of nums) {
        ++frequency[n + MAX_ABSOLUTE_VALUE];
    }

    let countPairs = 0;
    let totalPairs = Math.floor(nums.length / 2);
    let remainderToCompleteStartedPair = 0;

    for (let i = 0; i < frequency.length && totalPairs > 0; ++i) {

        frequency[i] -= remainderToCompleteStartedPair;
        if (frequency[i] === 0) {
            remainderToCompleteStartedPair = 0;
            continue;
        }

        if (frequency[i] > 0) {
            countPairs += Math.floor((frequency[i] + 1) / 2) * (i - MAX_ABSOLUTE_VALUE);
            totalPairs -= Math.floor((frequency[i] + 1) / 2);
            remainderToCompleteStartedPair = Math.max(frequency[i], 0) % 2;
        }
    }
    return countPairs;
};
