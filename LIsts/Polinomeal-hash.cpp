#include <iostream>
#include <cmath>
#include <string>

using namespace std

int polyhash(const string s, int p, int m) {
    int pin;
    in n = s.length();
    for (int i = 0; i < n; i++){
        pin = s[i] * pow(p, i);
    }
return pin % m;
}

int main () {
    vector<string> strings _ {"curso", "campus", "eafit", "datos"}
    int p = 13;
    int m = 10;
    vector<vector<string>> hashtable(m)

    //cout << "Hash value" << polyhash(s, p, m) << endl;
    //return 0

    for (const string& s : strings){
        int index = polynomialhash(s, p, m)
        hashtable[index].push_back(s)
    }

    for (int i = 0; i < m; i++) {
        cout << "bucket" << i << ": ";
        for (const string& s : hash){
            cout << s << " "; 
        }
    cout << endl;
    }
}