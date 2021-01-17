class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 0;
        sign = (dividend < 0) ? sign^1 : sign;
        sign = (divisor < 0) ? sign^1 : sign;
        long dividend_l = abs(dividend);
        long divisor_l = abs(divisor);
        
        vector<long> fval, fcoef;
        fval.push_back(divisor_l);
        fcoef.push_back(1);
        
        while (fval[fval.size()-1] <= dividend_l) {
            fval.push_back(fval[fval.size()-1] + fval[fval.size()-1]);
            fcoef.push_back(fcoef[fcoef.size()-1] + fcoef[fcoef.size()-1]);
        }
        
        long rs = 0;
        while (dividend_l >= divisor_l) {
            int cs = 0;
            for (int i = 0; i < fval.size(); i++) {
                if (fval[i] > dividend_l) {
                    cs = i - 1;
                    break;
                }
            }
            rs += fcoef[cs];
            dividend_l = dividend_l - fval[cs];
        }
        
        if (sign == 0) {
            if (rs > INT_MAX){
                return INT_MAX;
            }
            return rs;
        } else {
            return rs - rs - rs;
        }
    }
};