#include<iostream> //cout語法需要
#include <vector> //vector語法需要
using namespace std; //vector語法需要


struct ListNode {
    int val = 0;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {} ;
    ListNode(int x): val(x), next(nullptr) {};
    ListNode(int x, ListNode *next): val(x), next(next){}; 
};


class Solution { 
public:
    ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) { 
        ListNode dummy ;
        int carry =0;
        ListNode *ListHead = &dummy;
        int sum =0;
        
        while (l1 || l2 || carry){
            sum = (l1 ? l1->val : 0) + (l2 ?  l2->val : 0 ) + carry;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            ListNode *store = new ListNode(sum%10);
            ListHead->next = store;
            carry = sum/10;
            ListHead = ListHead->next;
        }

        return dummy.next;

    }
};

int main(){ //實際測試
	vector<int> nums ={1,2,3,4,5,6};
	int target = 10;
	Solution twoSum_instant; //創建能用twoSum的實例
	vector<int> output = twoSum_instant.twoSum(nums,target);
	cout << output[0] << " " << output[1];
	return 0;
	
}