class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector <double> ret = {celsius + 273.15 , celsius * 1.8 + 32};
        return ret;
    }
};