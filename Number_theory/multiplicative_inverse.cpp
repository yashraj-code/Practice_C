#include<iostream>

using namespace std;

class Triplet
{
    public:
        int x;
        int y;
        int gcd;
};

Triplet extend_euclid(int a, int b)
{
    // Base case
    if (b == 0)
    {
        // AS gcd(a, 0) = a
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    Triplet smallAns = extend_euclid(b, a % b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    return ans;
}

int mminverse(int a, int m)
{
    // It is similar aX+bY=1
    // there we calculated X,Y
    // here it is aB+mQ=1
    // we want coff B only 
    Triplet ans= extend_euclid(a,m);
    return ans.x;
}

int main()
{
    int a = 16;
    int m = 10;

    int ans = mminverse(a, m);
    cout << ans << endl;
    return 0;
}
