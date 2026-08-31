// Challenge 02: Closest Numbers
// Name:  Eric McIlrath

// Brief description:

// This code solves yyyy based on the following idea/implementation...

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {

    int amt;

    while (cin >> amt) {
        vector<int> nums;

        for (int i = 0; i < amt; i++) {
            int num;
            cin >> num;
            nums.push_back(num);
        }

        sort(nums.begin(), nums.end());

        int diff = INT_MAX;

        for (int i = 0; i < amt - 1; i++) {
            int tmp_diff = nums[i + 1] - nums[i];
            if (tmp_diff < diff) {
                diff = tmp_diff;
            }
        }

        bool first = true;
        for (int i = 0; i < amt - 1; i++) {
            if (nums[i + 1] - nums[i] == diff) {
                if (!first) {
                    cout << " ";
                }
                cout << nums[i] << " " << nums[i + 1];
                first = false;
            }
        }
        cout << endl;
    }

}
