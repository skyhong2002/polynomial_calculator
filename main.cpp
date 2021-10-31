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
                    "9 to list all the polynomial created.\n"
                    "0 to exit.\n"
                    "Don't forget to press the return butten owo\n";
        }
        else if(order[0] == '1'){
            cout << "Give it a name: ";
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
            cout << "Which polynomial do you want to see: ";
            string tmp_name;
            getline(cin, tmp_name);
            if(DB.find(tmp_name) == DB.end()){
                cout << "404 Not Found :(\n";
                continue;
            }
            cout << "Which coefficent do you want to see: ";
            int tmp_pow;
            cin >> tmp_pow;
            int pos = DB[tmp_name].term_find(tmp_pow);
            if(pos != -1) cout << DB[tmp_name].term()[pos].second << "\n";
            else cout << 0 << "\n";
            getline(cin, tmp_name);
        }
        else if(order[0] == '4'){
            cout << "Which polynomial do you want to see: ";
            string tmp_name;
            getline(cin, tmp_name);
            if(DB.find(tmp_name) == DB.end()){
                cout << "404 Not Found :(\n";
                continue;
            }
            cout << "Insert the power and coefficient (eg. 5 3): ";
            int tmp_pow, tmp_coef;
            cin >> tmp_pow >> tmp_coef;
            DB[tmp_name].term_edit(tmp_pow, tmp_coef);
            cout << "Wonderful. Polynomial " << tmp_name << " has been updated.\n";
        }
        else if(order[0] == '5'){
            string tmp_name1, tmp_name2, tmp_name;
            cout << "Insert the 1st polynomial: ";
            getline(cin, tmp_name1);
            if(DB.find(tmp_name1) == DB.end()){
                cout << "404 Not Found :(\n";
                continue;
            }
            cout << "Insert the 2nd polynomial: ";
            getline(cin, tmp_name2);
            if(DB.find(tmp_name2) == DB.end()){
                cout << "404 Not Found :(\n";
                continue;
            }
            cout << "Where do you want to save: ";
            getline(cin, tmp_name);
            if(DB.find(tmp_name) != DB.end()){
                cout << "Are you sure to rewrite \"" << tmp_name << "\"? (Y/N): ";
                getline(cin, order);
                if(order != "Y")
                    break;
            }
            DB[tmp_name] = DB[tmp_name1] + DB[tmp_name2];
            cout << "Wonderful. Polynomial " << tmp_name << " has been created.\n";
        }
        else if(order[0] == '6'){
            string tmp_name1, tmp_name2, tmp_name;
            cout << "Insert the 1st polynomial: ";
            getline(cin, tmp_name1);
            if(DB.find(tmp_name1) == DB.end()){
                cout << "404 Not Found :(\n";
                continue;
            }
            cout << "Insert the 2nd polynomial: ";
            getline(cin, tmp_name2);
            if(DB.find(tmp_name2) == DB.end()){
                cout << "404 Not Found :(\n";
                continue;
            }
            cout << "Where do you want to save: ";
            getline(cin, tmp_name);
            if(DB.find(tmp_name) != DB.end()){
                cout << "Are you sure to rewrite \"" << tmp_name << "\"? (Y/N): ";
                getline(cin, order);
                if(order != "Y")
                    break;
            }
            DB[tmp_name] = DB[tmp_name1] - DB[tmp_name2];
            cout << "Wonderful. Polynomial " << tmp_name << " has been created.\n";
        }
        else if(order[0] == '7'){
            string tmp_name1, tmp_name2, tmp_name;
            cout << "Insert the 1st polynomial: ";
            getline(cin, tmp_name1);
            if(DB.find(tmp_name1) == DB.end()){
                cout << "404 Not Found :(\n";
                continue;
            }
            cout << "Insert the 2nd polynomial: ";
            getline(cin, tmp_name2);
            if(DB.find(tmp_name2) == DB.end()){
                cout << "404 Not Found :(\n";
                continue;
            }
            cout << "Where do you want to save: ";
            getline(cin, tmp_name);
            if(DB.find(tmp_name) != DB.end()){
                cout << "Are you sure to rewrite \"" << tmp_name << "\"? (Y/N): ";
                getline(cin, order);
                if(order != "Y")
                    break;
            }
            DB[tmp_name] = DB[tmp_name1] * DB[tmp_name2];
            cout << "Wonderful. Polynomial " << tmp_name << " has been created.\n";
        }
        else if(order[0] == '8'){
            cout << "It is under construction qwq\n";
        }
        else if(order[0] == '9'){
            for(auto i : DB){
                cout << i.first << " (size: " << i.second.size() << "): ";
                const std::pair<int, int> *tmp_term = i.second.term();
                for(int j = 0; j < i.second.size() - 1; ++j){
                    cout << abs(tmp_term[j].second) << "x^" << tmp_term[j].first << (tmp_term[j+1].second < 0?" - ":" + ");
                }
                if(tmp_term[i.second.size()-1].first!=0) 
                    cout << abs(tmp_term[i.second.size()-1].second) << "x^" << tmp_term[i.second.size()-1].first << "\n";
                else cout << abs(tmp_term[i.second.size()-1].second) << "\n";
            }
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