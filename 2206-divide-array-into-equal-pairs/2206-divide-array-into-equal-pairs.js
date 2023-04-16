/**
 * @param {number[]} nums
 * @return {boolean}
 */
var divideArray = function(nums) {
    var map = [];
    for (var i = 0 ; i <= 500 ; i++)
        map[i] = 0;
    
    for (var i = 0 ; i < nums.length ; i++)
        map[nums[i]]++;
    
    for (var i = 0 ; i <= 500 ; i++)
    {
        if (map[i] % 2 != 0)
            return false;
    }
    return true;
};