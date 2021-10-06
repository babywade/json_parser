#include "token.h"
#include <iostream>

using namespace std;

int start(string& str, vector<Token>& tokenGroup) {
    if (str.size() == 0) {
        return start_null;
    }

    // 创建token序列
    cout << "size()" << str.size() << endl;
    Token token;
    bool isString = false;
    bool isNum = false;
    for(int i = 0; i < str.size(); ) {
        if (str[i] == ' ' || str[i] == '\r' || str[i] == '\n') {
            cout << str[i];
            i++;
            continue;
        }
        // 判断
        if (str[i] == ',') {
            cout << str[i];
            token.Set(COMMA, ",");
            tokenGroup.push_back(token);
            i++;
        } else if (str[i] == ':') {
            cout << str[i];
            token.Set(COLON, ":");
            tokenGroup.push_back(token);
            i++;
        } else if (str[i] == '{') {
            cout << str[i];
            token.Set(START_OBJ, "{");
            tokenGroup.push_back(token);
            i++;
        } else if (str[i] == '[') {
            cout << str[i];
            token.Set(START_ARRAY, "[");
            tokenGroup.push_back(token);
            i++;
        } else if (str[i] == ']') {
            cout << str[i];
            token.Set(END_ARRAY, "]");
            tokenGroup.push_back(token);
            i++;
        } else if (str[i] == '}') {
            cout << str[i];
            token.Set(END_OBJ, "}");
            tokenGroup.push_back(token);
            i++;
        } else if (str[i] == true) {
            cout << str[i];
            token.Set(BOOLEAN, "true");
            tokenGroup.push_back(token); //the value of TRUE is not null
            i++;
        } else if (str[i] == false) {
            cout << str[i];
            token.Set(BOOLEAN, "false");
            tokenGroup.push_back(token); //the value of FALSE is null
            i++;
        } else if (str[i] == '"') {
            isString = true;
            string ss;
            while (isString) {
                cout << str[i];
                i++;
                if (str[i] == '"') {
                    token.Set(STRING, ss);
                    tokenGroup.push_back(token);
                    isString = false;
                }
                ss.push_back(str[i]);
            }
        } else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            isString = true;
            string ss;
            while (isString) {
                ss.push_back(str[i]);
                cout << str[i];
                i++;
                if (str[i] < 'A' || str[i] > 'z' || (str[i] >= 'Z' && str[i] <= 'a')) {
                    token.Set(NUMBER, ss);
                    tokenGroup.push_back(token);
                    isString = false;
                }
            }
        } else if (str[i] >= '0' && str[i] <= '9') {
            isNum = true;
            string ssnum;
            while (isNum) {
                cout << str[i];
                ssnum.push_back(str[i]);
                i++;
                if (str[i] < '0' || str[i] > '9') {
                    token.Set(NUMBER, ssnum);
                    tokenGroup.push_back(token);
                    isNum = false;
                }
            }
        } else if (str[i] == '\0') {
            cout << str[i];
            i++;
            token.Set(END_DOC, "EOF");
            tokenGroup.push_back(token);
            break;
        } else {
            cout << "Invalid JSON input." << endl;
            return start_error;
        }
    }
    return start_pass;
}
