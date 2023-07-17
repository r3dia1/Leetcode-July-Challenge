/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_len = 0;
        ListNode* ptr = l1;
        while(ptr != NULL)
        {
            l1_len++;
            ptr = ptr -> next;
        }
        cout << "l1_len = " << l1_len << endl;

        int l2_len = 0;
        ptr = l2;
        while(ptr != NULL)
        {
            l2_len++;
            ptr = ptr -> next;
        }
        cout << "l2_len = " << l2_len << endl;

        vector<int> ret;
        int sum;
        int index = -1;
        
        while(l1_len > 0)
        {
            sum = 0;
            if(l1_len > l2_len)
            {
                ret.push_back(l1->val);
                l1 = l1 -> next;
                l1_len--;
                index++;
            }
            else if(l2_len > l1_len)
            {
                ret.push_back(l2->val);
                l2 = l2 -> next;
                l2_len--;
                index++;
            }
            else
            {
                sum = l1->val + l2->val;
                l1 = l1 -> next;
                l1_len--;
                l2 = l2 -> next;
                l2_len--;
                if(sum >= 10)
                {
                    int backtrack = index;
                    while(1)
                    {
                        if(backtrack < 0)
                        {
                            ret.insert(ret.begin(), 1);
                            index++;
                            sum = sum % 10;
                            ret.push_back(sum);
                            index++;
                            break;
                        }

                        ret[backtrack] += 1;
                        if(ret[backtrack] < 10)
                        {
                            sum = sum % 10;
                            ret.push_back(sum);
                            index++;
                            break;
                        }
                        else
                        {
                            ret[backtrack] = ret[backtrack] % 10;
                            backtrack--;
                        }
                    }
                }
                else
                {
                    ret.push_back(sum);
                    index++;
                }
            }
        }

        ListNode* l_ret = new ListNode(ret[0]);;
        ListNode* prev = l_ret;
        for(int i=1; i<ret.size(); i++)
        {
            ListNode* temp = new ListNode(ret[i]);
            prev -> next = temp;
            prev = temp;
        }

        return l_ret;
    }
};

int main()
{
    vector<int> v1 = {7,2,4,3};
    vector<int> v2 = {5,6,4};

    ListNode* l1 = new ListNode(v1[0]);;
    ListNode* prev = l1;
    for(int i=1; i<v1.size(); i++)
    {
        ListNode* temp = new ListNode(v1[i]);
        prev -> next = temp;
        prev = temp;
    }

    ListNode* l2 = new ListNode(v2[0]);;
    prev = l2;
    for(int i=1; i<v2.size(); i++)
    {
        ListNode* temp = new ListNode(v2[i]);
        prev -> next = temp;
        prev = temp;
    }

    Solution test;
    ListNode* result;
    result = test.addTwoNumbers(l1, l2);

    ListNode* temp = result;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp -> next;
    }
}