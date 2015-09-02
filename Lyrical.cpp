#include "Lyrical.h"
#include <assert.h>
#include <algorithm>

using namespace std;


Lyrical::Lyrical(std::string& title, std::string& artist, std::map<std::string, int> tags, std::vector<std::string> lyrics):
	Song(title, artist, tags), _lyrics(lyrics)
{

}

int Lyrical::calcScore(const std::string& query)
{
	int score = 0;
	score += calcTagScore(query);
	score += calcLyricsMatchScore(query);

	return score;
}

int Lyrical::calcLyricsMatchScore(string query)
{
	return std::count(_lyrics.begin(), _lyrics.end(), query) * s_parameters. _lyricsMatchWeight;
}


void Lyrical::print(const std::string& query)
{
	cout << _title << "\t" << calcScore(query) << "lyrics by: " << _artist <<endl;
}

