class Solution {
public:
    int peak;
    void find_peak(vector<int> arr, int left, int right)
    {
        // cout << "left = " << left << " right = " << right << endl;
        if(right - left == 1)
        {
            if(arr[left] > arr[right])
                peak = left;
            else
                peak = right;
            return;
        }

        int mid = (left + right) / 2;
        if(arr[mid - 1] > arr[mid])
            find_peak(arr, left, mid-1);
        else if(arr[mid] < arr[mid + 1])
            find_peak(arr, mid + 1, right);
        else
        {
            peak = mid;
            cout << "peak = " << peak << endl;
            return;
        }
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        find_peak(arr, 0, arr.size()-1);
        return peak;
    }
};