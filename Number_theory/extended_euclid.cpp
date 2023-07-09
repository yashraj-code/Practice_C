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

int main()
{
    int a = 16;
    int b = 10;

    Triplet ans = extend_euclid(a, b);
    cout << ans.gcd << endl;
    cout << ans.x << endl;
    cout << ans.y << endl;
    return 0;
}
