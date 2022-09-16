#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
             
        string substring; 
        int left = 0; //左指針
        string max_substring;
        
        int right = 0; //右指針
        while( right < s.length()){

            
            int repeat_offset =substring.find(s[right]);
            if(repeat_offset == string::npos){ //如果沒重複
                substring += s[right];
                right++;
            }else{ //如果有重複
                left = left+repeat_offset+1; //只取左指針後面的重複 之後
                right=left; //更新右指針為起點
                if(max_substring.length()<substring.length()){
                    max_substring = substring;
                }
                substring.erase(); //清空
            }
                
        }
        if(max_substring.length()<substring.length()){ //避免最後一段為最大字串
             max_substring = substring;
        }
       
        cout << max_substring<<"\n"; //debug用
        return max_substring.length();
    }
};


int main(){
    Solution app;
    string a ="abbcdbbbacdefaklombpe";
    cout << app.lengthOfLongestSubstring(a);

    return 0;

}

/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
