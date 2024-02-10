#include <iostream>
#include <string>

void printSubstrings(std::string str) {
    int n = str.length();
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++) {
            std::cout << str.substr(i, len) << std::endl;
        }
    }
}

int main() {
    std::string str = "abc";
    printSubstrings(str);
    return 0;
}