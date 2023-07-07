class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left, right;
        int count = 0;
        int ans = -1;

        left = 0;

        for(right = 0; right<answerKey.size(); right++)
        {
            if(answerKey[right] == 'F')
                count++;
            if(count <= k)
                ans = max(ans, right - left + 1);
            
            while(count > k && left < right)
            {
                left++;
                if(answerKey[left-1] == 'F')
                    count--;
            }
        }

        left = 0;
        count = 0;

        for(right = 0; right<answerKey.size(); right++)
        {
            if(answerKey[right] == 'T')
                count++;
            if(count <= k)
                ans = max(ans, right - left + 1);

            while(count > k && left < right)
            {
                left++;
                if(answerKey[left-1] == 'T')
                    count--;
            }
        }

        return ans;
    }
};