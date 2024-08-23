class Solution {
public:

    string GetNum (int& i, string& s, bool bast)
    {
        string num;
        num.push_back(s[i++]);
        if (num.back() == '-' or num.back() == '+')
            num.push_back(s[i++]);
        if (s.size() and s[i] >= '0' and s[i] <= '9')
            num.push_back(s[i++]);
        
        if (bast)
            i++;
        return num;
    }

    string fractionAddition(string s) {
        /*
            -1 / 2 + 1 / 2 -> -2 + 2 / 4 = 0 / 4 = 0 -> 0 / 1 etc...
        */
        int i = 0;
        string bast = GetNum(i, s, 1);
        string makam = GetNum(i, s, 0);

        while(i < s.size())
        {
            string bast2 = GetNum(i, s, 1);
            string makam2 = GetNum(i, s, 0);

            int newMakam = stoi(makam2) * stoi(makam);

            int newBast = stoi(bast) * stoi(makam2);
            newBast += stoi(bast2) * stoi(makam);

            bast = to_string(newBast);
            makam = to_string(newMakam);
        }

        string bastRes = to_string(stoi(bast) / __gcd(stoi(bast), stoi(makam)));
        string makamRes = to_string(stoi(makam) / __gcd(stoi(bast), stoi(makam)));

        if (bastRes[0] == '-' and makamRes[0] == '-')
            return bastRes.substr(1) + "/" + makamRes.substr(1);
        
        if (bastRes[0] != '-' and makamRes[0] != '-')
            return bastRes + "/" + makamRes;

        if (bastRes[0] == '-')
            return bastRes + "/" + makamRes;
        
        return "-" + bastRes + "/" + makamRes.substr(1);
    }
};