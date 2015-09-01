#ifndef SONGSFACTORY_H
#define SONGSFACTORY_H

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
        virtual ~SongsFactory();

        std::vector<std::unique_ptr<Song>> getSongs(std::string songsFileName);
        Parameters readParamsFromFile(std::string songsFileName);
        std::vector<std::string> readQueriesFromFile(std::string songsFileName);

    protected:
    private:
    SongsFactory();
    std::string getWordList(const std::string line);
    vector<string> split(const string& str, const char& delimiter) const;

};

#endif // SONGSFACTORY_H
