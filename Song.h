//#ifndef SONG_H
//#define SONG_H

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
    Song();
    Song(std::string& title, std::string& artist, std::map<std::string, int> tags);
    virtual ~Song();

    virtual int calcScore(const std::string& input) = 0 ;
    friend std::ostream& operator<<(std::ostream& os, const Song& song) ;

    static void init(Parameters parameters);


protected:
    static Parameters s_parameters;

    std::string _title;
    std::string _artist;
    std::map<std::string, int> _tags;

    int calcTagScore(const std::string& query) ;
    virtual void _print(std::ostream& where) const;
};

//#endif
