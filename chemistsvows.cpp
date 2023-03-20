#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    unordered_set<string> table = {"h", "he",
    "li", "be", "b", "c", "n", "o", "f", "ne",
    "na", "mg", "al", "si", "p", "s", "cl", "ar",
    "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr",
    "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe",
    "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn",
    "fr", "ra", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl","lv",
    "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu",
    "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr"};
    
    //T(i) takes 1/0 depending s(1..i) forms valid sequence of symbols
    //T(0) = 1. assume valid before start of word
    //T(i) true if either T(i - 1) and curr last char OR T(i - 2) and curr last two char
    /*
    For "clara":
    1. c (first letter case)
    2. l, cl (cl and t(0))
    3. a, la (la and t(1))
    4. r, ar (ar and t(2))
    5. a, ra (ra and t(3))
    */
    for (int i = 0; i < t; i++) {
        string s; cin >> s;
        vector<int> T(s.size() + 1);
        T[0] = 1;
        for (int j = 1; j <= s.size(); j++) {
            string eval = "";
            string eval2 = "";
            if (j == 1) {
                eval += s[j - 1];
                if (table.find(eval) != table.end()) {
                    T[j] = 1;
                }
            }
            else {
                eval += s[j - 1];
                eval2 = s[j - 2] + eval;
                if ((table.find(eval) != table.end() && T[j - 1] == 1) || ((table.find(eval2) != table.end() && T[j - 2] == 1))) {
                    T[j] = 1;
                }
            }
        }
        if (T[s.size()] == 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}