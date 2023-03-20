#include <iostream>
#include <string>

int main() {
    std::string s;
    int count = 0;
    std::cin >> s;
    for (int i = 1; i < s.length() - 1; i++) {
        count++;
    }
    std::string e_string = "";
    for (int i = 0; i < count * 2; i++) {
        e_string += "e";
    }
    std::cout << "h" << e_string << "y" << std::endl;
    return 0;
}