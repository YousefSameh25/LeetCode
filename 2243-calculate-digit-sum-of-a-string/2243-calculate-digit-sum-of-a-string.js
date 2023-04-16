/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var digitSum = function(s, k) 
{

    while(s.length > k)
    {
        var idx = 0,  str = "" , sum = 0;
        for (var i = 0 ; i < s.length ; i++)
        {
            sum += s[i] - '0';
            idx++;
            if (idx == k)
            {
                str += sum.toString();
                sum = 0 , idx = 0;
            }
        }
        if (idx > 0)
            str += sum.toString();
        console.log(str);
        s = str;
    }
    return s;
};