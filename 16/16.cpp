class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int ppl_size = people.size(); //people人數
        int req_size = req_skills.size(); //req_skill數量
        
        //把each req_skills轉成數字表示
        unordered_map<string, int> skill2num;
        for(int i=0; i<req_size; i++)
        {
            skill2num[req_skills[i]] = i;
        }

        //把每個ppl的掌握的skill轉換成一組skill set
        vector<int> ppl_s(ppl_size);
        for(int i=0; i<ppl_size; i++)
        {
            int skillset = 0;
            for(auto it: people[i])
            {
                // 找到存在於req_skill裡面的ppl skill，就把他加入該ppl的skill set
                // e.g. (0000) -> (0001) 0代表不存在 1代表存在
                if(skill2num.find(it) != skill2num.end())
                {
                    int skill = skill2num[it];
                    skillset = skillset | (1 << skill);
                }
            }
            ppl_s[i] = skillset;
        }

        //紀錄所有skill set被那些ppl組合而成
        vector<vector<int>> record(1 << req_size);

        //初始化dp
        vector<int> dp((1 << req_size), req_size+1);
        dp[0] = 0;
        
        for(int i = 0; i < ppl_size; i++)
        {
            auto dp1 = dp;
            //遍歷所有可能的skill set O(2^req_size)
            for(int skill = 0; skill < (1 << req_size); skill++)
            {
                //對於當前ppl & skill set，更新含ppl之後的skill set
                int new_skill = skill | ppl_s[i];

                //比較new skill set的原始人數和origin skill set + 1
                //If origin set + 1較小則更新new skill set的人數，並且把ppl[i]加入record中
                if(dp1[new_skill] > dp[skill] + 1)
                {
                    dp1[new_skill] = dp[skill] + 1;
                    record[new_skill] = record[skill];
                    record[new_skill].push_back(i);
                }
            }
            dp = dp1; //把dp table更新
        }

        return record[(1<<req_size) - 1];
    }
};