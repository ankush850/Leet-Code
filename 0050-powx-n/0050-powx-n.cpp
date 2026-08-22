class Solution {
public:
    double myPow(double x, int n) {

        if (n == 0)
            return 1;

        if (x == 0)
            return 0;

        return pow(x, (long long)n);
    }

    double pow(double x, long long n) {

        if (n == 0)
            return 1;

        if (n < 0)
            return 1.0 / pow(x, -n);

        if (n % 2 == 0)
            return pow(x * x, n / 2);
        else
            return x * pow(x * x, n / 2);
    }
};