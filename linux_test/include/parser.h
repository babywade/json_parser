#ifndef PARSER_H__
#define PARSER_H__

#include <string>
#include <list>
#include <vector>
#include "token.h"

#define parser_null 0
#define parser_pass 1
#define parser_error 2

typedef struct {
	std::string image;
	int type;
	int id;
	std::string ga_prefix;
	std::string title;
} Story;

class LatestNews {
public:
	LatestNews() {

	}
	void SetDate(std::string& date) {
		this->date = date;

	}
	void AddStories(Story& story) {
		this->stories.emplace_back(story);
	}
	void AddTopStories(Story& story) {
		this->top_stories.emplace_back(story);
	}
private:
	std::string date;
	std::list<Story> stories;
	std::list<Story> top_stories; 
};

int Parser(std::vector<Token>& tokenGroup, LatestNews& latestNewsJSON);
int StringToInt(std::string& str);
#endif