#include <iostream>
#include <cstring> //提供.length

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
             
        string substring; //容納substring
        substring += s[0];

        for(int i = 1; i < s.length(); i++){ //母字串第一個字不用比較

            int difference_count=0; //計算是否字串全部元素比較完畢
            for(int j=0; j< substring.length(); j++){
               
                if(s[i]!=substring[j]){ 
                    difference_count++; //用以計算比較次數                         
                }              
            }
            if(difference_count == substring.length()){ //當比較完畢才進行
                substring += s[i]; 
                cout << substring << "\n";
            }
            else{
                cout << "same\n";
                break;
            } 
        }
        return substring.length();
    }
};


int main(){
    Solution app;
    string a ("abcdbcefab");
    cout << app.lengthOfLongestSubstring(a);

    return 0;

}

