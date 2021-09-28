#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef struct {
	string image;
	int type;
	int id;
	string ga_prefix;
	string title;
} Story;

class LatestNews {
public:
	LatestNews() {

	}
private:
	string date;
	list<Story> stories;
	list<Story> top_stories; 
};
// token定义enum,值依次为0，1，2，3...
// STRING（字符串字面量）
// NUMBER（数字字面量）
// NULL（null）
// START_ARRAY（[）
// END_ARRAY（]）
// START_OBJ（{）
// END_OBJ（}）
// COMMA（,）
// COLON（:）冒号
// BOOLEAN（true或者false）
// END_DOC（表示JSON数据的结束）
enum TokenType {
	START_OBJ, END_OBJ, START_ARRAY, END_ARRAY, NULL_0, NUMBER, STRING, BOOLEAN, COLON, COMMA, END_DOC
};

typedef struct {
	TokenType type;
	string value;
} Token;

int main(int argc, char *argv[])
{
	TokenType tokenType;
	tokenType = START_OBJ;
	cout << tokenType << endl;
	std::cout << "Hello world!" << std::endl;
}