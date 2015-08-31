#ifndef INSTRUMENTAL_H
#define INSTRUMENTAL_H


#include "Song.h"
#include "Parameters.h"
#include <string>
#include<vector>
#include <map>

/**
*
*/
class Instrumental : Song
{
public:
    Instrumental(std::string& title, std::string& artist, std::map<std::string, int>
                  tags, std::vector<std::string> instruments , int bpm);

private:
    std::vector<std::string> _instruments;
    int _bpm;
    int calcScore(const std::string& input) override;
    int _calcBpmScore(std::string query) const;
    int _calcInstrumentMatchScore(std::string query);
    void _print(std::ostream& where) const override;
    void _printScore(const std::string& query) const;
};

#endif
