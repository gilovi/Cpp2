#include "Song.h"
#include <string>
#include<vector>

/**
*
*/
class Instrumental : Song
{
public:
    Instrumental(std::string& title, std::string& artist, std::vector<std::string> tags, std::vector<std::string> instruments , int bpm);

private:
    typedef Song super;

    std::vector<std::string> instruments;
    int _bpm;

    int calcScore(const std::string& input) const override;
    int _calcBpmScore() const;
    int _calcInstrumentMatchScore();
    void print(std::ostream& where) const override;
};

