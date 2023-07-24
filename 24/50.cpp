class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n == -1)
            return 1/x;
        
        double n_sqrtPow = myPow(x, n/2);
        
        if(n % 2 == 1)
            return n_sqrtPow * n_sqrtPow * x;
        else if(n % 2 == 0)
            return n_sqrtPow * n_sqrtPow ;
        else
            return n_sqrtPow * n_sqrtPow * 1/x;
    }
};