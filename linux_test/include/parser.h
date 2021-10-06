#ifndef PARSER_H__
#define PARSER_H__

#include <string>
#include <list>
#include <vector>
#include "token.h"

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
	int SetDate(string& date) {
		this->date = date;
	}
	int AddStories(Story& story) {
		this->stories.emplace_back(story);
	}
	int AddTopStories(Story& story) {
		this->top_stories.emplace_back(story);
	}
private:
	std::string date;
	std::list<Story> stories;
	std::list<Story> top_stories; 
};

int Parser(std::vector<Token>& tokenGroup, LatestNews& latestNewsJSON);
#endif