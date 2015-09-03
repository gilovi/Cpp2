#ifndef INSTRUMENTAL_H
#define INSTRUMENTAL_H


#include "Song.h"
#include "Parameters.h"
#include <string>
#include<vector>
#include <map>

/**
* an instrumental song representation class
*/
class Instrumental : public Song
{
public:
    /**
    * Instrumental ctor for title artist tags and instruments and bpm
    */
	Instrumental(std::string& title, std::string& artist, std::map<std::string, int>
	             tags, std::map<std::string, int> instruments , int bpm = 0);
    /**
	* an override for print in Song class
	* @see Song::print(const std::string&)
	*/
	void print(const std::string& query) override;

private:
	std::map<std::string, int> _instruments;
	int _bpm;
	/**
	* an override for calcScore in 'Song' class
	* @see Song::calcScore(const std::string&)
	*/
	int calcScore(const std::string& input) override;
	/**
	* returns the bpm match score for a given query
	*/
	int _calcBpmScore(std::string query) const;
	/**
	* returns the instrument match score for a given query
	*/
	int _calcInstrumentMatchScore(std::string query);

};

#endif
