#include <iostream>
#include <fstream>
#include <vector>
#include "token.h"
#include "parser.h"

using namespace std;

int main(int argc, char *argv[])
{
	fstream fs;
	string line;
	string str;
	// 文件读取，运行在WSL上，此处为linux路径
	fs.open("zhihu.txt");
	if (!fs) {
		cout << "cannot open the file" << endl;
		return -1;
	}
	
	while (getline(fs, line)) {
		line += '\n';
		str += line;
	}
	cout << str << endl;

	// 首先将输入文件转化为token序列
	vector<Token> tokenGroup;
	int res = start(str, tokenGroup);
	cout << res << endl;

	LatestNews latestNewsJSON;
	Parser(tokenGroup, latestNewsJSON);
}

void test1() {
	//测试enum类型的输出
	TokenType tokenType;
	tokenType = START_OBJ;
	cout << tokenType << endl;  //输出0
}