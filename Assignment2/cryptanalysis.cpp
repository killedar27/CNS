#include <bits/stdc++.h>
using namespace std;

// https://cryptii.com/pipes/caesar-cipher


set<string> dict;

int main()
{
    dict.insert("the");
    dict.insert("gun");
    dict.insert("is");
    dict.insert("in");
    dict.insert("the");
    dict.insert("drawer");





    string s, org;
    cout << "Enter Cipher text" << endl;
    getline(cin, s);

    string x;
    // for (int i = 0; i < s.length(); i++)
    //     if (s[i] != ' ')
    //         x += s[i];
    // s = x;

    int k = 0;

    cout << "\nCipher text is: " << s << endl << endl;

    org = s;
    for (int k = 0; k < 26; k++)
    {
        cout << "Keep Key as: " << k << endl;
        s = org;
        string word = "";
        int flg = 0;
        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == ' ')
            {

                if (dict.find(word) == dict.end())
                {
                    flg = 1;
                    break;
                }

                word = "";
                continue;
            }
            int val = s[i] - 'a';
            val = (val - k + 26) % 26;
            char ch = 'a' + val;
            word += ch;
            s[i] = ch;



        }

        if (dict.find(word) == dict.end())
        {
            flg = 1;

        }
        if (flg == 0)
            cout << s << endl << endl;
    }

    return 0;
}