// Use a stack to check if brackets are balanced
// Example: "()[]{}" -> true
// Example: "([)]" -> false

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string& brackets){
    stack<char> s;

    // map closing brackets to their corresponding opening brackets
    char matchingBrackets[128] = {0};
    matchingBrackets[')'] = '(';
    matchingBrackets[']'] = '[';
    matchingBrackets['}'] = '{';

    // We iterate through each character in the input string
    for(char ch: brackets){  // -> is like the 'for in' of Python. SYNTAX: for (declaration : collection) 
        if(ch=='(' || ch == '[' || ch == '{'){
            s.push(ch); // -> Push opening brackets onto the stack.
        }
        else if(ch == ')' || ch == ']' || ch == '}'){
            /*check if the stack is empty or if the top of the stack matches the 
            corresponding opening bracket. If not, return false.*/
            if(s.empty() || s.top() != matchingBrackets[ch]){ 
                return false;
            }
            s.pop();
        }
    }
    return s.empty(); // -> if the stack is empty, then all brackets are balanced
}

int main(){
    string input;
    cout << "Enter a string with brackets: ";
    cin >> input;

    if (isBalanced(input)) {
        cout << "\nThe brackets are balanced." << endl;
    } else {
        cout << "\nThe brackets are not balanced." << endl;
    }

    return 0;
}