#include <unordered_map>
#include "parser.h"

using namespace std;

int Parser(vector<Token>& tokenGroup, LatestNews& latestNewsJSON) {
    unordered_map<string, string> mmap;

    pair<string, string> elem;
    elem.first = "";
    elem.second = "";

    Story story;
    story.image = "";
    story.type = 0;
    story.id = 0;
    story.ga_prefix = "";
    story.title = "";

    bool isObj = false;
    bool isArray = false;
    //主循环
    for (int i = 0; i < tokenGroup.size(); ) {
        if (tokenGroup[i].GetType() == START_OBJ) {
            isObj = true;
            i++;
        } else if (isObj == true && isArray == false && tokenGroup[i].GetType() == STRING) {
            elem.first = tokenGroup[i].GetValue();
            i++;
        } else if (isObj == true && isArray == false && tokenGroup[i].GetType() == COLON) {
            i++;
        } else if (isObj == true && isArray == false && tokenGroup[i].GetType() == STRING) {
            elem.second = tokenGroup[i].GetValue();
            if (elem.first == "date") {
                latestNewsJSON.SetDate(elem.first);
            }
            i++;
        } else if (isObj == true && isArray == false && tokenGroup[i].GetType() == START_ARRAY) {
            isArray = true;
            isObj = false;
            i++;
        } else if (isObj == true && isArray == true && tokenGroup[i].GetType() == STRING) {
            elem.first = tokenGroup[i].GetValue();
            i++;
        } else if (isObj == true && isArray == true && tokenGroup[i].GetType() == COLON) {
            i++;
        } else if (isObj == true && isArray == true && tokenGroup[i].GetType() == STRING) {
            elem.second = tokenGroup[i].GetValue();
            if (elem.first == "image" || elem.first == "images") {
                story.image = elem.second;
            } else if (elem.first == "type") {
                int res = 0;
                res = StringToInt(elem.second);
                story.type = res;
            } else if (elem.first == "id") {
                int res = 0;
                res = StringToInt(elem.second);
                story.id = res;
            } else if (elem.first == "ga_prefix") {
                story.ga_prefix = elem.second;
            } else if (elem.first == "title") {
                story.title = elem.second;
            }
        } else if (tokenGroup[i].GetType() == COMMA) {
            i++;
        } else if (isObj == true && isArray == true && tokenGroup[i].GetType() == END_OBJ) {
            latestNewsJSON.AddStories(story);
            i++;
        }
    }
}

int StringToInt(string& str) {
    int res = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        res = res * 10 + str[i];
    }
    return res;
}