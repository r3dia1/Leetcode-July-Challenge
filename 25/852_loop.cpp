class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size()-1;
        int mid, peak;

        while(right - left > 1)
        {
            mid = (left + right) / 2;
            if(arr[mid - 1] > arr[mid])
            {
                right = mid - 1;
            }
            else if(arr[mid] < arr[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                peak = mid;
                cout << "peak = " << peak << endl;
                return peak;
            }
        }

        if(arr[left] > arr[right])
            peak = left;
        else
            peak = right;
        return peak;
    }
};