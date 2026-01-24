class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0,j = 1;
        int len = nums.size();
        if (len == 0)
            return 0;

        while (j < len) {
            if (nums[i] != nums[j]) {
                nums[i+1] = nums[j];
                i++;
            }
            j++;
        }
        return i+1;
    }
};