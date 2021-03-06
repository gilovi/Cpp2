#include <string>
#include <map>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <sstream>

#include "Song.h"
//#include "Instrumental.h"
//#include "Lyrical.h"
#include "SongsFactory.h"
#include "Parameters.h"
#include "SortHelper.h"

using namespace std;

const string SEPARATOR = "----------------------------------------";

vector<string> readQueriesFromFile(string queriesFileName);
void printQueryBegin(string query);

typedef unique_ptr<Song> uSongPtr;
//void readSongsFromFile(string songsFileName, vector<Song*> );
//Parameters readParamsFromFile(string songsFileName);
//vector<string> readQueriesFromFile(string songsFileName);

/**
 * the main.
 */
int main(int argc, char *argv[])
{

	if (argc != 4)
	{
		cout
				<< "Usage: MIR < songs file name > < parameters file name > < queries file name >"
				<< endl;
		exit(1);
	}
	vector<uSongPtr> songs = SongsFactory::getSongs(string(argv[1]));
	Song::init (Parameters(string (argv[2])));vector
	< string > queries = readQueriesFromFile(string(argv[3]));

	for (auto &query : queries)
	{
		printQueryBegin(query);
		SortHelper s;
		for (auto &song : songs)
		{
			s.addItem(song->calcScore(query));
		}
		vector<int> order = s.getSortedOrderInVector();
		for (auto place : order)
		{
			if (songs[place]->calcScore(query) <= 0)
			{
				break;
			}
			songs[place]->print(query);
		}
	}
}
/**
 * helper func to read queries
 * @return a vector contains the queries.
 */
vector<string> readQueriesFromFile(string queriesFileName)
{
	vector < string > queries;
	ifstream instream(queriesFileName.c_str());
	if (!instream.is_open())
	{
		cerr << "Error! Can't open file: " << queriesFileName << "." << endl;
	}

	string line = "";

	while (instream.good())
	{
		getline(instream, line);
		if (line.empty())
		{
			continue;
		}
		queries.push_back(line);
	}
	return queries;
}
/**
 * helper func to print query opening message
 */
void printQueryBegin(string query)
{
	cout << SEPARATOR << endl;
	cout << "Query word: " << query << endl;
	cout << endl;
}
