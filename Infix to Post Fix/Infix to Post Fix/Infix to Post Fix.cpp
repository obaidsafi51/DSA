#include <iostream>
#include<stack>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    stack<char> s;
    fstream ifile("input.txt", ios::in);
    fstream ofile("output.txt", ios::app);
    char token;
   
        if (!ifile) {
            cout << "Error ";
            exit(-1);
        }
        else {
            while (ifile) {
                ifile.get(token);
                cout << token;

                if (token >= 0 && token < 9) {
                    ofile << token;
                }
                /*else if(token == '(') {
                    s.push(token);
                }
                else if (token == ')') {
                    while (token != '(') {
                    char p = s.top();
                    ofile << p;
                    s.pop();

                    }
                }
                else {
                    ofile << token;
                }*/
            }
        }

  
    

}
