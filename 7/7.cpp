#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t_left, t_right, f_left, f_right;
        int f_count = 0;
        int t_count = 0;
        int ans = -1;

        t_left = 0;
        t_right = 0;
        f_left = 0;
        f_right = 0;

        while( t_right<answerKey.size() && f_right<answerKey.size())
        {
            if(answerKey[t_right] == 'F')
                f_count++;

            if(answerKey[f_right] == 'T')
                t_count++;
            
            if(t_count <= k)
                ans = max(ans, f_right - f_left + 1);
            
            if(f_count <= k)
                ans = max(ans, t_right - t_left + 1);
            
            while(f_count > k && t_left < t_right)
            {
                t_left++;
                if(answerKey[t_left-1] == 'F')
                    f_count--;
            }

            while(t_count > k && f_left < f_right)
            {
                f_left++;
                if(answerKey[f_left-1] == 'T')
                    t_count--;
            }

            t_right++;
            f_right++;
        }

        return ans;
    }
};

int main()
{
    Solution test;
    string answerKey = "TTFTTFTT";
    int ans = test.maxConsecutiveAnswers(answerKey, 1);
    cout << "ans = " << ans << endl;
}