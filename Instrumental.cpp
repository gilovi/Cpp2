#include "Instrumental.h"
#include <math.h>
#include <assert.h>

Instrumental::Instrumental(std::string& title, std::string& artist,
                            std::map<std::string, int> tags,
                             std::vector<std::string> instruments, int bpm):
Song(title, artist, tags), _instruments(instruments), _bpm(bpm)
{
}

int Instrumental::calcScore(const std::string& query)
{
return calcTagScore(query) + _calcBpmScore(query) + _calcInstrumentMatchScore(query);
}

int Instrumental::_calcBpmScore(std::string query) const
{
    assert(s_parameters.bpmLikelihoodWeight);

    return _bpm ? exp((_bpm - 1)/ (double)(2 * pow(1, 2))) : 0; //TODO
}

int Instrumental::_calcInstrumentMatchScore(std::string query)
{
    assert (s_parameters.instrumentMatchWeight > 0);
    return s_parameters.instrumentMatchWeight * 1; //TODO
}

void Instrumental::_print(std::ostream& where) const
{

}

void Instrumental::_printScore(const std::string& query) const
{

}
