#include<bits/stdc++.h>
using namespace std;

map<string, string> encoder;
map<string, string> decoder;

string cipherText(string &str, int block_size)
{
    string cipher, temp;

    for (int i=0;i<str.size();i++)
    {
        // char ch=str[i];
        temp += str[i];
        if (temp.size() == block_size)
        {
            if (encoder.find(temp) != encoder.end())
            {
                cipher += encoder[temp];
                temp = "";
            }
            else
            {
                cipher += temp;
                temp = "";
            }
            }        
    }
    if (encoder.find(temp) != encoder.end())
    {
        cipher += encoder[temp];
        temp = "";
    }
    else
    {
        cipher += temp;
        temp = "";
    }

    return cipher;
}

string decipherText(string &str, int block_size)
{
    string decipher, temp;

    for (int i = 0; i < str.size(); i++)
    {
        // char ch=str[i];
        temp += str[i];
        if (temp.size() == block_size)
        {
            if (decoder.find(temp) != decoder.end())
            {
                decipher += decoder[temp];
                temp = "";
            }
            else
            {
                decipher += temp;
                temp = "";
            }
        }
    }
    if (decoder.find(temp) != decoder.end())
    {
        decipher += decoder[temp];
        temp = "";
    }
    else
    {
        decipher += temp;
        temp = "";
    }

    
    return decipher;
}

int main()
{
    freopen("polygon.txt","r",stdin);

    string str;
    getline(cin, str); // Read the first line of the file
    cin.clear();
    freopen("dictionary.txt","r",stdin);
    string s1, s2,text;
    while (cin >> s1 >> s2)
    {
        encoder[s1] = s2;
        decoder[s2] = s1;
    }
    int block_size=3;
    // Perform encryption and decryption
    string cipher = cipherText(str, block_size);
    string decipher = decipherText(cipher, block_size);

    // Output the results
    cout << "Plain-Text: " << str << endl;
    cout << "Cipher-Text: " << cipher << endl;
    cout << "Decipher-Text: " << decipher << endl;

    return 0;
}
