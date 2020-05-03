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
        input[i] += pass[i % pass.size()] - 65;//Caesar cipher with a left key of the corresponding letter in the password's number where a = 0
        if(input[i] > 90)
            input[i] -= 26;
    }
    return input;
}

string caesar(string input, short key = 3)
{
    input = toUpperCase(input);
    for(auto c : input)
    {
        c += key;
        if(c > 90)
            c -= 26;
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
        out += "-";
    }
    out.pop_back();
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

string polybius(string input)
{
    input = toUpperCase(input);
    string out = "";
    for(auto c : input)
    {
        if(c < 73)
        {
            out += ((c - 65) / 5) + 1 ? ((c - 65) / 5) + 49 : '5';
            out += (c + 1) % 5 == 0 ? '5' : ((c - 64) % 5) + 48;
            out += " ";
        }
        else if(c > 74)
        {
            out += ((c - 66) / 5) + 1 ? ((c - 66) / 5) + 49 : '5';
            out += c % 5 == 0 ? '5' : (c % 5) + 48;
            out += " ";
        }
        else
            out += "24 ";
    }
    out.pop_back();
    return out;
}

string affine(string input, int key1 = 1, int key2 = 3)
{
    input = toUpperCase(input);
    string out = "";
    for(auto c : input)
        out += ((c - 64) * key1 + key2) % 26 == 0 ? 'Z' : ((c - 64) * key1 + key2) % 26 + 64;
    return out;
}

string rail_fence(string input, int key = 3)
{
    input = toUpperCase(input);
    int tick = 0;
    string out[key];
    for(int i = 0; i < key; i++)
        out[i] = "";
    bool direction = false;
    for(int i = 0; tick < input.size(); tick++)
    {
        out[i] += input[tick];
        i += direction ? -1 : 1;
        if(i == key - 1 || !i)
            direction = !direction;
    }
    for(int i = 1; i < key; i++)
        out[0] += out[i];
    return out[0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b, pass;
    short key;
    while(1)
    {
        cin >> pass;
        cin >> key;
        b = "";
        a = "";
        do
        {
            b += a;
            cin >> a;
        } while (a != "endt");
        cout << "vigenere: " << vigenere(b, pass) << endl;
        cout << "caesar: " << caesar(b, key) << endl;
        cout << "a1z26: " << a1z26(b) << endl;
        cout << "atbash: " << atbash(b) << endl;
        cout << "polybius: " << polybius(b) << endl;
        cout << "affine: " << affine(b, key, key) << endl;
        cout << "rail fence: " << rail_fence(b, key) << endl;
    }
    return 0;
}