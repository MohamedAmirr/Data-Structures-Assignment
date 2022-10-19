#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>

using namespace std;


void RecPermute(string soFar, string rest, set<string> &Permutations) {
    if (rest == "") // No more characters
        Permutations.insert(soFar); // store the word
    else // Still more chars
// For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i) + rest.substr(i + 1);
            RecPermute(next, remaining, Permutations);
        }
}


// "wrapper" function

set<string> ListPermutations(string s) {
    set<string> Permutations;
    RecPermute("", s, Permutations);
    return Permutations;
}

int main() {
    string s;
    cin >> s;
    auto st = ListPermutations(s);
    for (auto &ss: st)cout << ss << endl;
    return 0;
}
