#include <string>
#include <vector>

#define start_null 0
#define start_pass 1
#define start_error 2
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

class Token {
public:
	Token() {
		this->type = NULL_0;
		this->value = "";
	}
	void Set(const TokenType& type, const std::string& value) {
		this->type = type;
		this->value = value;
	}
private:
	TokenType type;
	std::string value;
};

int start(std::string& str, std::vector<Token>& tokenGroup);
bool isNull(int c);
Token readString();
