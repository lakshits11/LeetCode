class Solution {
public:
    vector<double> convertTemperature(double cel) {
        double ff = cel*1.80 + 32.00;
        double kel = cel + 273.15;
        return {kel, ff};
    }
};