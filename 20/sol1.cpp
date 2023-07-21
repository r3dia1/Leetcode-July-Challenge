class Solution {
public:
    void start(vector<int>& asteroids, int p1, int p2)
    {
        while(p2 < asteroids.size())
        {
            // cout << "p1 = " << p1 << " p2 = " << p2 << endl;
            while(asteroids[p1] > 0 && asteroids[p2] < 0)
            {
                if(abs(asteroids[p1]) > abs(asteroids[p2]))
                {
                    // cout << "p1>p2" << endl;
                    asteroids.erase(asteroids.begin() + p2);
                }
                else if(abs(asteroids[p1]) < abs(asteroids[p2]))
                {
                    asteroids.erase(asteroids.begin() + p1);
                    p1--;
                    p2--;
                }
                else
                {
                    asteroids.erase(asteroids.begin() + p1, asteroids.begin() + p2 + 1);
                    p2 = p1;
                    p1 = p1 - 1;
                }

                if(p1 < 0 || p2 >= asteroids.size())
                {
                    break;
                }
                // for(auto it: asteroids)
                // {
                //     cout << it << " ";
                // }
            }
            p1++;
            p2++;
        }
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        int p1=0, p2=1;
        if(asteroids.size() >= 2)
        {
            start(asteroids, p1, p2);
            return asteroids;
        }
        else
        {
            return asteroids;
        }
    }
};