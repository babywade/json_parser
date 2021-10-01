#include <string>
#include <list>

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
private:
	std::string date;
	std::list<Story> stories;
	std::list<Story> top_stories; 
};