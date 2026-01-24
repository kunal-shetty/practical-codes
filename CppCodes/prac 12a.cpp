#include <iostream>
using namespace std;

int main() {
    string str = "12345";
    int num = stoi(str);
    cout<<"String to int : "<<num<<endl;
    int newNum = 67890;
    string newString = to_string(newNum);
    cout<<"Int to string : "<<newString;
    return 0;
}