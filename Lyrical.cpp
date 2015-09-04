#include "Lyrical.h"
#include <assert.h>
#include <algorithm>

using namespace std;

/**
 * Lyrical ctor for title artist  tags and lyrics
 */
Lyrical::Lyrical(std::string& title, std::string& artist,
		std::map<std::string, int> tags, std::vector<std::string> lyrics) :
		Song(title, artist, tags), _lyrics(lyrics)
{

}
/**
 * an override for calcScore in 'Song' class
 * @see Song::calcScore(const std::string&)
 */
int Lyrical::calcScore(const std::string& query)
{
	int score = 0;
	score += calcTagScore(query);
	score += calcLyricsMatchScore(query);

	return score;
}
/**
 * returns the lyrics match score for a given query
 */
int Lyrical::calcLyricsMatchScore(string query)
{
	return std::count(_lyrics.begin(), _lyrics.end(), query)
			* s_parameters._lyricsMatchWeight;
}

/**
 * an override for print in Song class
 * @see Song::print(const std::string&)
 */
void Lyrical::print(const std::string& query)
{
	cout << _title << "\t" << calcScore(query) << "\t" << "lyrics by: "
			<< _artist << endl;
}

