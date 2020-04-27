#include <bits/stdc++.h>

using namespace std;

string toUpperCase(string a)
{
    string out = "";
    for(auto c : a)
    {
        if(c > 64)
        {
            if(c < 91)
                out += c;
            else
            {
                if(c > 96 && c < 123)
                    out += (c - 32);
            }
        }
    }
    return out;
}//switches plaintext to uppercase and throws out any non-letters, including numbers

string vigenere(string pass, string input)
{
    pass = toUpperCase(pass);
    input = toUpperCase(input);
    for(int i = 0; i < input.size(); i++)
    {
        input[i] += pass[i % pass.size()] - 65;//Caesar cipher with a left shift of the corresponding letter in the password's number where a = 0
        if(input[i] > 90)
            input[i] -= 26;
    }
    return input;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b, pass;
    while(1)
    {
        cin >> pass;
        b = "";
        a = "";
        do
        {
            b += a;
            cin >> a;
        } while (a != "endt");
        cout << vigenere(pass, b) << endl;
    }
    return 0;
}