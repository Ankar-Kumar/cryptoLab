// both 3 and 4 in this code

#include <bits/stdc++.h>
using namespace std;
//width means total number of column
string transposeCipher(string text, int width)
{
    string result = "";
    int col = 0, i = 0;
    for(col=0;col<width;col++){
        for(i=col;i<text.size();i+=width){
            result+=text[i];
        }
    }
    return result;
}

string decrypt(string text, int width)
{
    string result=text;
    int col = 0, j = 0;
    for (int i = 0; i < text.size(); i++)
    {
        result[j] = text[i];
        j += width;
        if (j >= text.length())
        {
            col++;
            j = col;
        }
    }
    return result;
}

int main()
{
    freopen("transpose.txt", "r", stdin);

    string text;
    getline(cin, text);

    int width = 4;

    string enc = transposeCipher(text, width);
    // string enc2 = transposeCipher(enc,  width);

    cout<<"Original Text : "<<text<<endl;
    cout << "First Transposition Cipher: " << enc << endl;
    // cout << "Double Transposition Cipher: " << enc2 << endl;

    string dec = decrypt(enc,  width);
    // string dec2 = decrypt(dec, width);

    cout << "Decrypted Text: " << dec << endl;

    return 0;
}
