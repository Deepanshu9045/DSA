#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    string ans = "";

    for (char ch : s) {
        if (ch != ' ') {
            ans += ch;
        }
    }

    cout << ans << endl;

    return 0;
}