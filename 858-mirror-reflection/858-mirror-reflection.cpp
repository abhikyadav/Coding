class Solution {
public:
    int mirrorReflection(int p, int q) {
    int l = lcm(p, q);
        if ((l / p) % 2 == 0)
            return 0;
        if ((l / q) % 2 == 0)
            return 2;
        return 1;
    }
    int gcd(int a, int b){
          if (b == 0)
            return a;
          return gcd(b, a % b);
    }
    int lcm(int a, int b){
        return (a / gcd(a, b)) * b;
    }
};