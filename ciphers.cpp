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

string vigenere(string input, string pass)
{
    input = toUpperCase(input);
    pass = toUpperCase(pass);
    for(int i = 0; i < input.size(); i++)
    {
        input[i] += pass[i % pass.size()] - 65;//Caesar cipher with a left shift of the corresponding letter in the password's number where a = 0
        if(input[i] > 90)
            input[i] -= 26;
    }
    return input;
}

string caesar(string input, short shift = 3)
{
    input = toUpperCase(input);
    for(int i = 0; i < input.size(); i++)
    {
        input[i] += shift;
        if(input[i] > 90)
            input[i] -= 26;
    }
    return input;
}

string a1z26(string input)
{
    input = toUpperCase(input);
    short i;
    string out = "";
    for(auto c : input)
    {
        i = c - 64;
        out += to_string(i);
    }
    return out;
}

string atbash(string input)
{
    input = toUpperCase(input);
    string out = "";
    for(auto c : input)
        out += 155 - c;
    return out;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b, pass;
    short shift;
    while(1)
    {
        cin >> pass;
        cin >> shift;
        b = "";
        a = "";
        do
        {
            b += a;
            cin >> a;
        } while (a != "endt");
        cout << "vigenere: " << vigenere(b, pass) << endl;
        cout << "caesar: " << caesar(a, shift) << endl;
        cout << "a1z26: " << a1z26(b) << endl;
        cout << "atbash: " << atbash(b) << endl;
    }
    return 0;
}