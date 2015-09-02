#include "Instrumental.h"
#include <math.h>
#include <assert.h>
#include <algorithm>

using namespace std;
Instrumental::Instrumental(string& title, string& artist,
                           map<string, int> tags,
                           map<string, int> instruments, int bpm):
	Song(title, artist, tags), _instruments(instruments), _bpm(bpm)
{
}

int Instrumental::calcScore(const string& query)
{
	return calcTagScore(query) + _calcBpmScore(query) + _calcInstrumentMatchScore(query);
}

int Instrumental::_calcBpmScore(string query) const
{
	assert(s_parameters._bpmLikelihoodWeight);

	map<string , vector<double>> bmpParams = s_parameters._bmpParams;
	int res = 0;
	if (bmpParams.find(query) != bmpParams.end() && _bpm)
	{
		// the word is known.
		double mean = bmpParams[query][0];
		double stdd = bmpParams[query][1];
		res = exp(pow(_bpm - mean, 2)/(2 * pow(stdd, 2)));
	}
	return (int)res * s_parameters._bpmLikelihoodWeight;
}

int Instrumental::_calcInstrumentMatchScore(string query)
{
	assert (s_parameters._instrumentMatchWeight > 0);
	if(_instruments.find(query) != _instruments.end())
	{
		return s_parameters._instrumentMatchWeight * _instruments[query];
	}
	return 0;
}


void Instrumental::print(const string& query)
{
	cout << _title << "\t" << calcScore(query) << "performed by: " << _artist <<endl;
}
