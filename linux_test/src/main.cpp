#include <iostream>
#include <fstream>
#include <vector>
#include "token.h"
#include "parser.h"

using namespace std;

void test1();
void test2_checkCPU();
int test3_jsonParser();

int main(int argc, char *argv[])
{
	// test1();
	test2_checkCPU();
	// test3_jsonParser();
}

void test1() {
	//测试enum类型的输出
	TokenType tokenType;
	tokenType = START_OBJ;
	cout << tokenType << endl;  //输出0
	return;
}

void test2_checkCPU() {
	//测试 AMD Ryzen 5 1400 Quad-Core Processor 小端
    union MyUnion{
        int a; //暂且认为16位，可能short更好
        char c; //8位
    }test;
    test.a = 1; //0x0001
    if (test.c == 1)
        cout << "little endian" <<endl;
    else cout << "big endian" <<endl;
	return;
}

int test3_jsonParser() {
	fstream fs;
	string line;
	string str;
	// 文件读取，运行在WSL上，此处为linux路径
	fs.open("zhihu.txt");
	if (!fs) {
		cout << "cannot open the file" << endl;
		return 0;
	}
	
	while (getline(fs, line)) {
		line += '\n';
		str += line;
	}
	cout << str << endl;

	// 首先将输入文件转化为token序列
	vector<Token> tokenGroup;
	cout << "start" << endl;
	int res = start(str, tokenGroup);
	cout << "res:" << res << endl;

	LatestNews latestNewsJSON;
	Parser(tokenGroup, latestNewsJSON);
	cout << "finish" << endl;
	return 1;
}