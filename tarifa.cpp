#include <iostream>

int main() {
    int x, n, p;
    int data = 0;
    std::cin >> x >> n;
    for (int i = 0; i < n; i++) {
        data += x;
        std::cin >> p;
        data -= p;
    }
    std::cout << data + x << std::endl;
    return 0;
}