#include <iostream>
#include <stack>
#include <string>

using namespace std;
struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);

    stack <Bracket> opening_brackets_stack;
    bool found=false;

    for (int position = 0; position < text.length(); ++position)
        {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{')
            {
            // Process opening bracket, write your code here
            opening_brackets_stack.push( Bracket( next, position ) );

            }

        if (next == ')' || next == ']' || next == '}')
            {
            // Process closing bracket, write your code here
            if (!opening_brackets_stack.empty())
                {
                auto left=opening_brackets_stack.top();
                if (!left.Matchc(next))
                    {
                    cout << position+1 <<endl;
                    found=true;
                    break;
                    }
                else
                    opening_brackets_stack.pop();
                }
            else
                {
                cout <<position+1 <<endl;
                found=true;
                break;
                }
            }
        }

    // Printing answer, write your code here
    if (opening_brackets_stack.empty() && !found)
        {
        cout <<"Success"<<endl;
        }
    else if (!found)    //if yup
    {
    auto left=opening_brackets_stack.top();
    cout <<left.position+1 <<endl;
    }

    return 0;
}



