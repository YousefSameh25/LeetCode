/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var countOdds = function(low, high) {
    var ans = 0;
    if (low % 2 != 0)
        low++ , ans++;
    if (high % 2 != 0)
        high-- , ans++;
    ans += (high - low) / 2;
    return ans;
};