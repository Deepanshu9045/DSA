#include <iostream>
#include <string>
using namespace std;

string URLify(string &s) {
    string ans = "";
    
    for (char ch : s) {
        if (ch == ' ')
            ans += "%20";
        else
            ans += ch;
    }
    
    return ans;
}

int main() {
    string s;
    getline(cin, s);

    cout << URLify(s) << endl;

    return 0;
}