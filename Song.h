#ifndef SONG_H
#define SONG_H

#include "Parameters.h"
#include <string>
#include<vector>
#include <map>
#include <iostream>

/**
 * An abstract song class
 */
class Song
{
public:
	/**
	 *default ctor
	 */
	Song();
	/**
	 * Song ctor for title artist and tags
	 */
	Song(std::string& title, std::string& artist,
			std::map<std::string, int> tags);
	/**
	 *default dtor
	 */
	virtual ~Song();
	/**
	 * caculates the total score of the given query on the song.
	 */
	virtual int calcScore(const std::string& input) = 0;
	/**
	 * A << operator (mostly for debugging, expanding is possible)
	 */
	friend std::ostream& operator<<(std::ostream& os, const Song& song);
	/**
	 * initiates the song class for use (inserts the parameters)
	 */
	static void init(Parameters parameters);
	/**
	 * prints the output for a query
	 */
	virtual void print(const std::string& query) = 0;

protected:
	static Parameters s_parameters;

	std::string _title;
	std::string _artist;
	std::map<std::string, int> _tags;
	/**
	 * calculates the tag score for a query;
	 */
	virtual int calcTagScore(const std::string& query);
	/**
	 * A print to ostream used mainly to supply an option to expand the << operator on inherited classes
	 */
	virtual void print(std::ostream& where) const;
};

#endif
