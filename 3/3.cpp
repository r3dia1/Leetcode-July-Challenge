#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int head = 0;
        int tail = s.size()-1;

        //重點part: set libaray的應用
        //如果兩string相同，則檢查string中是否存在duplicated element.
        //set個資料結構用來存放unique elements，所以可以檢查s或是goal裡面是否存在duplicated element.
        if(s == goal)
        {
            set<char> duplicate(s.begin(), s.end());
            if(duplicate.size() < s.size())
                return true;
            else 
                return false;
        }

        //此處已知s != goal
        //所以我們分別從頭和尾檢查s與goal counter之第一個不一樣的element
        //接著再對兩個不同處做交換，看看能否讓s == goal
        int flag;
        while(head <= tail)
        {
            flag = 0;
            if(s[head] == goal[head])
                head++;
            else
                flag++;
            
            if(s[tail] == goal[tail])
                tail--;
            else
                flag++;

            if(flag == 2)
                break;
        }

        //element交換處
        //若是head == tail代表只有一處不同，則不用交換必定false
        if(head != tail)
            swap(goal[head], goal[tail]);

        return s == goal;
    }
};

int main()
{
    Solution a;
    string c = "ab";
    string b = "ba";
    bool result = a.buddyStrings(c, b);
    cout << "result = " << result << endl;
}