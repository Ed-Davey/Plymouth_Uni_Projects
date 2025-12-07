#include <iostream>
using namespace std;
#include <string>

int main() {

    string word1 = "Hello";
    string word2 = " world!";

    string* ptr = &word1;

    *ptr += word2;

    cout << word1 << endl;

    int size = word1.size();

    cout << size << endl;

    if (word1 == word2) {
        cout << "They are the same word";
    }
    else {
        cout << "They are not the same word";
    }


    return 0;
}
