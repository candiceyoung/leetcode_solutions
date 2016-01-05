#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_string;
        int size = strs.size();
        if (size == 0) return encoded_string;
        for (int i = 0; i < size; ++i) {
            int len = strs[i].length();
            encoded_string = encoded_string + "*" + to_string(len) + "*" + strs[i];
        }
        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int len = s.length();
        if (len == 0) return strs;
        string temp = "";
        int i = 1;
        int start = 0;
        while (i < len) {
            int l = 0, j;
            for (j = i; s[j] != '*' && s[j] >= '0' && s[j] <= '9'; ++j) {
                l = l * 10 + s[j] - '0';
            }
            if (start == 1) strs.push_back(temp);
            temp = "";
            temp = s.substr(j + 1, l);
            i = j + l + 2;
            start = 1;
        }
        strs.push_back(temp);
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
int main(void) {
    Codec codec;
    vector<string> strs = {"63/Rc","h","BmI3FS~J9#vmk","7uBZ?7*/","24h+X","O "};
    string s = codec.encode(strs);
    cout << "haha: " << s << endl;
    vector<string> temp = codec.decode(s);
    for (int i = 0; i < temp.size(); ++i) {
        cout << temp[i] << endl;
    }
    return 0;
}