// a * x + m * y = 1
// a * x = 1 ( mod m)
// найденное х и будет являться обратным к а
// Time O(logM)
int x, y;
int g = gcd (a, m, x, y);//WideGCD
if (g != 1)
    cout << "no solution";
else {
    x = (x % m + m) % m;
    cout << x; 
}

// Нахождение всех простых по заданному модулю 
// Time O(n)
// Обозначим через r[i] искомое обратное к числу i по модулю m
r[1] = 1;
for (int i=2; i<m; ++i)
        r[i] = (m - (m/i) * r[m%i] % m) % m;
