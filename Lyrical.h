#ifndef LYRICAL_H
#define LYRICAL_H


#include "Song.h"
#include "Parameters.h"
#include<string>
#include<vector>
#include<map>

/**
* a lyrical song class
*/
class Lyrical : public Song
{
public:
    /**
    * Lyrical ctor for title artist  tags and lyrics
    */
	Lyrical(std::string& title, std::string& artist, std::map<std::string, int> tags, std::vector<std::string> lyrics);
	/**
	* an override for print in Song class
	* @see Song::print(const std::string&)
	*/
	void print(const std::string& query) override;

private:
	std::vector<std::string> _lyrics;
    /**
	* an override for calcScore in 'Song' class
	* @see Song::calcScore(const std::string&)
	*/
	int calcScore(const std::string& input) override;
	/**
	* returns the lyrics match score for a given query
	*/
	int calcLyricsMatchScore(const std::string query);

};

#endif
