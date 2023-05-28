#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int &y = x;

    cout << "x: " << x << endl;  // Output: x: 10
    cout << "y: " << y << endl;  // Output: y: 10

    y = 20;

    cout << "x: " << x << endl;  // Output: x: 20
    cout << "y: " << y << endl;  // Output: y: 20

    return 0;
}
