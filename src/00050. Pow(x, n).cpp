class Solution {
public:
    double pow(double x, long n) {
        if (n == 0) return 1;
        double tmp = pow(x, n/2);
        if (n % 2 == 0) return tmp * tmp;
        else {
            return tmp * tmp * x;
        }
    }
    
    double myPow(double x, int n) {
        long t = n;
        if (x == 0) return 0;
        if (n < 0) {
            x = 1/x;
            t *= -1;
        }
        return pow(x, t);
    }
};