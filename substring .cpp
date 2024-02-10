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


// void printSubstrings(std::string str, std::string curr = "", int index = 0) { /// recursive approach 
//     if(index == str.length()) {
//         std::cout << curr << std::endl;
//         return;
//     }
//     // Two recursive calls, one includes the character at current index, the other does not
//     printSubstrings(str, curr, index + 1);
//     printSubstrings(str, curr + str[index], index + 1);
// }

int main() {
    std::string str = "abc";
    printSubstrings(str);
    return 0;
}





// class Solution {  // leetcode 647
// public:
//     // Helper function to count the number of palindromes centered at s[i] and s[j]
//     int palin(int i, int j, string &s){
//         int cnt = 0;
//         // Expand around the center and count the palindromes
//         while(i >= 0 && j < s.length() && s[i] == s[j]){
//             cnt++; // Increment the count for each palindrome
//             i--; // Move to the left
//             j++; // Move to the right
//         }
//         return cnt;
//     }
    
//     int countSubstrings(string s) {
//         int cnt = 0;
//         // Iterate over the string
//         for(int i = 0; i < s.length() ;i++){
//            // For each character, consider it as the center of a palindrome
//            int j = i;
//            // Count the palindromes of odd length (centered at s[i])
//            int oddLengthVale = palin(i,j , s);
//            // Count the palindromes of even length (centered between s[i] and s[i+1])
//            int evenLengthVale= palin(i , j+1 ,s);
//            // Add the counts to the total count
//            cnt += (oddLengthVale + evenLengthVale);
//         }
//         // Return the total count
//         return cnt;
//     }
// };
