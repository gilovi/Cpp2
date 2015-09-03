#include "Song.h"
#include <assert.h>

using namespace std;

//map<string, vector<int>> Song::s_parameters ;
/**
    *default ctor
    */
Song::Song():
	_title(), _artist(), _tags()
{
}
    /**
    * Song ctor for title artist and tags
    */
Song::Song(string& title, string& artist, map<string, int> tags):
	_title(title), _artist(artist), _tags(tags)
{
}

Song::~Song()
{
}

Parameters Song::s_parameters;
/**
    * initiates the song class for use (inserts the parameters)
    */
void Song::init(Parameters parameters)
{
	s_parameters = parameters;
}
/**
    * A << operator (mostly for debugging, expanding is possible)
    */
std::ostream& operator<<(std::ostream& os, const Song& song)
{
	song.print(os); // call the child print method.
	return os;
}

    /**
    * A print to ostream used mainly to supply an option to expand the << operator on inherited classes
    */
void Song::print(ostream& where) const
{
	where << _title ;
}
/**
    * calculates the tag score for a query;
    */
int Song::calcTagScore(const string& query)
{
	return _tags[query] * s_parameters._tagMatchWeight;
}


