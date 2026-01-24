#include<iostream>
#include<string>
#include<ctype.h>
#include<vector>
using namespace std;
bool isPangram(string sentence){
	bool check = true;
	int arr[26] = { 0 };
	for(int i = 0; i < sentence.length(); i++)
		tolower(sentence[i]);
	vector<char> letters = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for(int i = 0; i < sentence.length(); i++){
		for(int j = 0; j < letters.size(); j++){
			if(sentence[i] == letters[j])
			arr[j] = 1;
		}
	}
	for(int i = 0; i < 26; i++){
		if(arr[i] == 0)
		return false;
	}
	return true;
}