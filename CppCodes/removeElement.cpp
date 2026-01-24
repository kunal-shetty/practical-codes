#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
	nums.erase(find(nums.begin(), nums.end(), val));
	return nums.size();
}
