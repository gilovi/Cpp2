#include "Song.h"

using namespace std;

Song::Song(string& title, string& artist, vector<string> tags):
_title(title), _artist(artist), _tags(tags)
{
}

void Song::init(std::map<string, vector<int>> parameters)
{
    s_parameters = parameters;
}

std::ostream& operator<<(std::ostream& os, const Song& song)
{
    song.print(os); // call the child print method.
    return os;
}

void Song::print(ostream& where) const
{
    where << _title << "\t" << calcScore() << "\t";
}
