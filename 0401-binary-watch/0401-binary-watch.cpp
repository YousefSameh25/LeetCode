class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        int items[] = {1 ,2 , 4 ,8 , 1 , 2 ,4 ,8 ,16 ,32};
        bool hours[] = {1 , 1 , 1, 1, 0 , 0, 0, 0, 0, 0};
        vector<string> res;
        for(int msk = 0 ; msk < (1<< 10); msk++ )
        {
            if(__builtin_popcount(msk) != turnedOn)
                continue;
            int h = 0 , m = 0;
            for(int i = 0 ; i < 10 ;i++)
            {
                if(msk & ( 1 << i) )
                {
                    if(hours[i])
                        h+= items[i];
                    else
                        m += items[i];
                }
            }
            if(h<= 11 and m <= 59)
            {
                string tmp = to_string(h);
                string tmp2 = to_string(m);
                if(tmp2.size() == 1)
                    tmp2= "0" + tmp2;
                res.push_back(tmp + ":" + tmp2);
            }


        }
        return res;
    }
};