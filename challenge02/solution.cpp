// Challenge 02: Closest Numbers
// Name:  Eric McIlrath 
// NetID: emcilrat

// Brief description:

/* 
This code finds the pair of integers in a list 
that have the least absolute numerical distance between them
*/
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
        vector<int> nums; // the main vector of ints

        for (int i = 0; i < amt; i++) { // ingest the numbers
            int num;
            cin >> num;
            nums.push_back(num);
        }

        sort(nums.begin(), nums.end()); // sort 'em

        int diff = INT_MAX; // this must be int max so that the first time this code is run, the diff will be the smallest

        for (int i = 0; i < amt - 1; i++) { // go through the list calculating diff, 2 adjacent numbers at a time
            int tmp_diff = nums[i + 1] - nums[i];
            if (tmp_diff < diff) {
                diff = tmp_diff;
            }
        }

        bool first = true; // for proper spacing
        for (int i = 0; i < amt - 1; i++) { // print pairs if diff == smallest diff
            if (nums[i + 1] - nums[i] == diff) {
                if (!first) {
                    cout << " "; // space
                }
                cout << nums[i] << " " << nums[i + 1];
                first = false;
            }
        }
        cout << endl;
    }

}
