// Iterative
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0 || x == 1) return x;
        
        double ans = 1.0;
        long long nn = n;
        if(nn < 0) nn = -1 * nn;

        while(nn){
            if(nn%2 == 1){
                ans = ans * x;
                nn = nn-1;
            }
            else{
                x = x * x;
                nn = nn/2;
            }
        }
        if(n < 0) ans = double(1.0)/ans;
        return ans;
    }
};


// Recursive
class Solution {
public:
    double power(double x, long long n) {
        if (n == 0) return 1;
        double half = power(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }

    double myPow(double x, int n) {
        if (x == 0 || x == 1) return x;

        long long nn = n;
        if (nn < 0) nn = -nn;

        double result = power(x, nn);

        return (n < 0) ? 1.0 / result : result;
    }
};

