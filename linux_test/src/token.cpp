#include "token.h"
#include <iostream>

using namespace std;

int start(string& str, vector<Token>& tokenGroup) {
    if (str.size() == 0) {
        return start_null;
    }

    // 创建token序列
    Token token;
    bool isString = false;
    bool isNum = false;
    bool isChar = false;
    for(int i = 0; i < str.size(); i++) {
        if (str[i] == ' ' || str[i] == '\r') {
            continue;
        }
        // 判断
        if (str[i] == ',') {
            token.Set(COMMA, ",");
            tokenGroup.push_back(token);
        } else if (str[i] == ':') {
            token.Set(COLON, ":");
            tokenGroup.push_back(token);
        } else if (str[i] == '{') {
            token.Set(START_OBJ, "{");
            tokenGroup.push_back(token);
        } else if (str[i] == '[') {
            token.Set(START_ARRAY, "[");
            tokenGroup.push_back(token);
        } else if (str[i] == ']') {
            token.Set(END_ARRAY, "]");
            tokenGroup.push_back(token);
        } else if (str[i] == '}') {
            token.Set(END_OBJ, "}");
            tokenGroup.push_back(token);
        } else if (str[i] == true) {
            token.Set(BOOLEAN, "true");
            tokenGroup.push_back(token); //the value of TRUE is not null
        } else if (str[i] == false) {
            token.Set(BOOLEAN, "false");
            tokenGroup.push_back(token); //the value of FALSE is null
        } else if (str[i] == '"') {
            isString = true;
            string ss;
            while (isString) {
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
                i++;
                if (str[i] < 'A' || str[i] > 'z' || (str[i] >= 'Z' && str[i] <= 'a')) {
                    token.Set(NUMBER, ss);
                    tokenGroup.push_back(token);
                    isNum = false;
                }
            }
        } else if (str[i] >= '0' && str[i] <= '9') {
            isNum = true;
            string ssnum;
            while (isNum) {
                ssnum.push_back(str[i]);
                i++;
                if (str[i] < '0' || str[i] > '9') {
                    token.Set(NUMBER, ssnum);
                    tokenGroup.push_back(token);
                    isNum = false;
                }
            }
        } else if (str[i] == '\0') {
            token.Set(END_DOC, "EOF");
            tokenGroup.push_back(token);
        } else {
            cout << "Invalid JSON input." << endl;
            return start_error;
        }
    }
    return start_pass;
}
