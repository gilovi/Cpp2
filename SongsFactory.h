#ifndef SONGSFACTORY_H
#define SONGSFACTORY_H

#include <fstream>
#include <memory>
#include <string>
#include "Song.h"
#include <vector>
#include "Parameters.h"

/**
 * responsible for creating song objects.
 * also contains additional public parsing helper methods.
 */
class SongsFactory
{
public:
	/**
	 * default dtor
	 */
	virtual ~SongsFactory();
	/**
	 * a function to extract songs from file
	 */
	static std::vector<std::unique_ptr<Song>> getSongs(
			std::string songsFileName);

private:
	/**
	 * default ctor.
	 * it is private because this class shouldnt be instansed .
	 */
	SongsFactory();
	/**
	 * a helper function .
	 * @return a string within {}.
	 */
	static std::string getWordList(const std::string line);

};

#endif // SONGSFACTORY_H
