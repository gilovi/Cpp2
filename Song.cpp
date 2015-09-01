#include "Song.h"
#include <assert.h>

using namespace std;

//map<string, vector<int>> Song::s_parameters ;

Song::Song():
_title(), _artist(), _tags()
{
}

Song::Song(string& title, string& artist, map<string, int> tags):
_title(title), _artist(artist), _tags(tags)
{
}

Song::~Song()
{
}

Parameters Song::s_parameters;

void Song::init(Parameters parameters)
{
    s_parameters = parameters;
}

std::ostream& operator<<(std::ostream& os, const Song& song)
{
    song._print(os); // call the child print method.
    return os;
}

void Song::_print(ostream& where) const
{
    where << _title ;
}

int Song::calcTagScore(const string& query)
{
    return _tags[query] * s_parameters.tagMatchWeight;
}


