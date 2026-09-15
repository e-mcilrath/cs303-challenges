// Challenge 03
// Eric McIlrath
// emcilrat

/*
This code reads in a string and determines if it is a 
pallindrome by counting the number each character appears in
the string. If there is a character that appears an odd number
of time which is greater than 1, not a pallindrome.
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {

    string line;

    while (getline(cin, line)) {
        map<char, int> letter_count; // how many times each letter appears

        for (size_t i = 0; i < line.size(); i++) { // ingest letters with count
            char c = line[i];
            if (c >= 'A' && c <= 'Z') { // make lowrcase
                c = c - 'A' + 'a';
            }
            if (c >= 'a' && c <= 'z') { // anything else is punctuation or space
                letter_count[c]++;
            }
        }

        int odds = 0; // letters appearing odd number times
        for (map<char, int>::iterator it = letter_count.begin(); it != letter_count.end(); ++it) {
            if (it->second % 2 != 0) { // check if odd
                odds++;
            }
        }

        cout << "\"" << line << "\" is "; 
        if (odds > 1) { // if there is more than one odd letter, not a pallindrome 
            cout << "not ";
        }
        cout << "a palindrome permutation" << endl;
    }

    return 0;
}
