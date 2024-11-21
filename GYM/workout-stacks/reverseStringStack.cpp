// Use a stack to reverse the characters of a given string

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reverseString(string word){
    stack <char> st;
    int wordLen = word.length();

    for(int i=0; i<wordLen; i++){
        st.push(word[i]);
    }

    string newWord= "";
    for(int x=0; x<wordLen; x++){
        newWord += st.top();
        st.pop();
    }

    return newWord;
}

int main(){
    string word;
    cout << "Enter a word: ";
    getline(cin, word);
    /*
    - cin >>: Reads input until whitespace, useful for single words or tokens.
    - getline(): Reads an entire line of input, including spaces, making it suitable for full sentences or phrases.
    */

    string reversed = reverseString(word);
    cout << "\nReversed string: " << reversed << endl;

    return 0;
}