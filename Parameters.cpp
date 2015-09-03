#include "Parameters.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const char NUM_SEPARATOR = ',';
const char DESCRIPTION_SEPARATOR = ':';
const string TAG_MATCH_SCORE = "tagMatchScore";
const string LYRICS_MATCH_SCORE = "lyricsMatchScore";
const string INSTRUMENT_MATCH_SCORE = "instrumentMatchScore";
const string BMP_LIKELI_WEIGHT = "bpmLikelihoodWeight";
const int BPM_PARAMS_NUM = 2;
const string LYRICS_BY = "lyricsBy";
const string INSTRUMENTS = "instruments";
const string PERFORMED_BY = "performedBy";
const string BPM = "bpm";

/**
* default ctor
*/
Parameters::Parameters()
{
	//ctor
}
/**
* ctor from file path.
 */
Parameters::Parameters(std::string paramsFile)
{
	std::ifstream instream(paramsFile.c_str());
	if (!instream.is_open())
	{
		cerr << "Error! Can't open file: " << paramsFile << "." << endl;
	}

	string line = "";

	while(instream.good())
	{
		getline(instream, line);
		if (line.empty())
        {
            continue;
        }
		vector<string> splited = split(line, DESCRIPTION_SEPARATOR);

		string param = splited[0];
		string val = splited[1];
		if (param.compare(TAG_MATCH_SCORE) == 0)
		{
			_tagMatchWeight = stoi(val);
		}
		else if (param.compare(LYRICS_MATCH_SCORE) == 0)
		{
			_lyricsMatchWeight = stoi(val);
		}
		else if (param.compare(INSTRUMENT_MATCH_SCORE) == 0)
		{
			_instrumentMatchWeight = (stoi(val));
		}
		else if (param.compare(BMP_LIKELI_WEIGHT) == 0)
		{
			_bpmLikelihoodWeight = (stoi(val));
		}
		else // it's probably bpm rates
		{
		    vector<string> bpmStr = split(val, NUM_SEPARATOR);
			vector<double> bpmParams;

			bpmParams.push_back(stod(bpmStr[0]));
			bpmParams.push_back(stod(bpmStr[1]));

			addBmpWord(splited[0], bpmParams);

		}

	}
}

Parameters::~Parameters()
{
	//dtor
}
/**
* _tagMatchWeight setter
*/
void Parameters::setTagMatchWeight(int w)
{
	_tagMatchWeight = w;
}
/**
* _lyricsMatchWeight setter
*/
void Parameters::setLyricsMatchWeight(int w)
{
	_lyricsMatchWeight = w;
}
/**
* _instrumentMatchWeight setter
*/
void Parameters::setInstrumentMatchWeight(int w)
{
	_instrumentMatchWeight = w ;
}
/**
* _bpmLikelihoodWeight setter
*/
void Parameters::setBpmLikelihoodWeight(int w)
{
	_bpmLikelihoodWeight = w;
}
/**
 * a method to add a bpm word to the parameters. (e.g happy: 3.2 ,2.1)
 */
void Parameters::addBmpWord(std::string word, vector<double> vals)
{
	_bmpParams[word] = vals;
}
/**
* a static helper function to split a string around a given delimeter
 */
vector<string> Parameters::split(const string& str, const char& delimiter)
{
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while(getline(ss, tok, delimiter))
	{
		internal.push_back(tok);
	}

	return internal;
}

