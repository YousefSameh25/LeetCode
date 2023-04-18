/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number[]}
 */
var kWeakestRows = function(mat, k) {
    let v = [];
    for (let i = 0; i < mat.length; i++) {
    let row = mat[i];
    let l = 0, r = row.length - 1, ans = 0;
    while (l <= r) {
      let mid = Math.floor((l + r) / 2);
      if (row[mid] === 1) {
           l = mid + 1;
           ans = mid + 1;
         } else {
           r = mid - 1;
         }
       }
       v.push([ans, i]);
     }
      v.sort((a, b) => a[0] - b[0]);
      while (v.length > k) {
        v.pop();
      }
      let ans = [];
      for (let i = 0; i < v.length; i++) {
        ans.push(v[i][1]);
      }
      return ans;
};