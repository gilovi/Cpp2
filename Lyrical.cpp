#include "Lyrical.h"
#include <assert.h>

using namespace std;


Lyrical::Lyrical(std::string& title, std::string& artist, std::map<std::string, int> tags, std::vector<std::string> lyrics):
Song(title, artist, tags), _lyrics(lyrics)
{

}

int Lyrical::calcScore(const std::string input) const
{

}

int Lyrical::calcLyricsMatchScore(string query)
{

}

void Lyrical::_print(std::ostream& where) const
{

}

void Lyrical::_printScore(const std::string& query) const
{

}

