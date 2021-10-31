#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include "polynomial.h"
using namespace std;

int main(){
    cout << "=============================\n"
            "Polymomial Calculator Ver 1.0\n"
            "     Created by Sky Hong\n"
            "     NTNU CSIE 41047033S\n"
            "=============================\n"
            "Type \"help\" to see the guide.\n";
    string order;
    map<string, polynomial> DB;
    while(true){
        cout << "\n> ";
        getline(cin, order);
        if(order[0] == 'h'){
            cout << "1 to key in a polynomial.\n"
                    "2 to show the whole polynomial.\n"
                    "3 to show the particular coefficent of the polynomial.\n"
                    "4 to edit the particular Non-zero item of the polynomial.\n"
                    "5 to do the add+tion.\n"
                    "6 to do the subtra-tion.\n"
                    "7 to do the multipl*cation.\n"
                    "8 to do the d/vision.\n"
                    "9 to show all the polynomial created.\n"
                    "0 to exit.\n"
                    "Don't forget to press the return butten owo\n";
        }
        else if(order[0] == '1'){
            cout << "Give it a name: \n";
            string tmp_name;
            getline(cin, tmp_name);
            cout << "Great. Now, tell me the detail of " << tmp_name << ":\n";
            polynomial tmp_poly;
            cin >> tmp_poly;
            DB[tmp_name] = tmp_poly;
            cout << "Wonderful. Polynomial " << tmp_name << " has been created.\n";
            getline(cin, tmp_name);
        }
        else if(order[0] == '2'){
            cout << "Which polynomial do you want to see: ";
            string tmp_name;
            getline(cin, tmp_name);
            if(DB.find(tmp_name) == DB.end())
                cout << "404 Not Found :(\n";
            else
                cout << DB[tmp_name];
        }
        else if(order[0] == '3'){
            cout << "Which two polynomial do you want to +: ";
        }
        else if(order[0] == '4'){

        }
        else if(order[0] == '5'){

        }
        else if(order[0] == '6'){

        }
        else if(order[0] == '7'){

        }
        else if(order[0] == '8'){
            cout << "It is under construction qwq\n";
        }
        else if(order[0] == '9'){
            
        }
        else if(order[0] == '0'){
            cout << "Are you sure to quit? (Y/N): ";
            getline(cin, order);
            if(order == "Y")
                break;
        }
    }
    cout << "\\BYE/\n";
}