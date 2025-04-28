#include <iostream>
#include <cmath>

int gcd(int a, int b) {
    return (b == 0) ? std::abs(a) : gcd(b, a % b);
}

int main(){


}
