class Solution {
	static bool mycompare(vector<int>& a, vector<int>& b)
	{
		return (a[1] < b[1]);
	}
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals)
	{
		sort(intervals.begin(), intervals.end(), mycompare);
		
		int previous_choice = 0;
		int invalid = 0;
		
		for(int i=1; i<intervals.size(); i++)
		{
			if(intervals[i][0] < intervals[previous_choice][1])
			{
				invalid++;
			}
			else
			{
				previous_choice = i;
			}
		}
		
		return invalid;
	}
};