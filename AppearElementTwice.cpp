#include <iostream>
#include <vector>
using namespace std;

int findSingleElement(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int singleElement = findSingleElement(nums);
    cout << "The single element is: " << singleElement << endl;

    return 0;
}
