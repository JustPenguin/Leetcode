/*
Leetcode :twoSum
給定一個值，和一個已知陣列。回傳 陣列中 相加後能滿足該值的元素 其位置


Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?


*/

#include<iostream> //cout語法需要
#include <vector> //vector語法需要
using namespace std; //vector語法需要

class Solution { //物件原型
public:
    vector<int> twoSum(vector<int>& nums, int target) { //回傳值為vector型陣列
        vector<int> answer; //可修改長度的陣列

        for(int i=0; i < (nums.size()-1); i++){
            int another = target-nums[i]; //於此先定義另一正確選項，可避免需用下列迴圈才定義(會增加宣告次數)
            for(int j=(i+1); j<nums.size(); j++){
                if(nums[j] == another){
                    answer.push_back(i); //陣列最尾端新增該元素，會同步增長陣列長度
                    answer.push_back(j);
                 
                }
            }
        }

        return answer;
    }
};

int main(){ //實際測試
	vector<int> nums ={1,2,3,4,5,6};
	int target = 10;
	Solution twoSum_instant; //創建能用twoSum的實例
	vector<int> output = twoSum_instant.twoSum(nums,target); //用來回傳答案
	cout << output[0] << " " << output[1];
	return 0;
	
}