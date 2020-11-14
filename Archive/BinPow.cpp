// Реализация алгоритма бинарного возведения в степень (a ** n) 
// О(logN)
int binpow (int a, int n) {
        int res = 1;
        while (n) {
                if (n & 1)
                a *= a; res *= a;
        }       n >>= 1;
    return res; 
}