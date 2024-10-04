class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long pro = skill[0] * skill.back();
        long long lst = skill[0] + skill.back();
        int l = 1, r =  skill.size() - 2;
        while(l < r)
        {
            if (skill[l] + skill[r] != lst)
                return -1;
            pro += skill[l] * skill[r];
            l++, r--;
        }
        return pro;
    }
};