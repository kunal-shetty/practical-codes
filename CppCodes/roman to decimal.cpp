#include<iostream>
using namespace std;
int romanToInt(string s) {
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case 'I':
                result += 1;
                break;
            case 'V':
                result += (i > 0 && s[i - 1] == 'I') ? 3 : 5;
                break;
            case 'X':
                result += (i > 0 && s[i - 1] == 'I') ? 8 : 10;
                break;
            case 'L':
                result += (i > 0 && s[i - 1] == 'X') ? 30 : 50;
                break;
            case 'C':
                result += (i > 0 && s[i - 1] == 'X') ? 80 : 100;
                break;
            case 'D':
                result += (i > 0 && s[i - 1] == 'C') ? 300 : 500;
                break;
            case 'M':
                result += (i > 0 && s[i - 1] == 'C') ? 800 : 1000;
                break;
        }
    }
    return result;
}