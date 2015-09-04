using namespace std;

#include <string>
#include <map>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "SongsFactory.h"
#include "Instrumental.h"
#include "Lyrical.h"

const string SEPARATOR = "=";
const string END_OF_SONGS = "***";
const string TITLE = "title";
const string TAGS = "tags";
const string LYRICS = "lyrics";
const char WORDS_SEPARATOR = ' ';
const std::string LYRICS_BY = "lyricsBy";
const std::string INSTRUMENTS = "instruments";
const std::string PERFORMED_BY = "performedBy";
const std::string BPM = "bpm";

/**
 * a function to extract songs from file
 */
vector<std::unique_ptr<Song>> SongsFactory::getSongs(std::string songsFileName)
{
	vector < std::unique_ptr < Song >> songs;

	ifstream instream(songsFileName.c_str());
	if (!instream.is_open())
	{
		cerr << "Error! Can't open file: " << songsFileName << "." << endl;
	}

	string line = "";

	int lastSong = 0;

	while (instream.good() && !lastSong)
	{
		if (line.compare(SEPARATOR) != 0)
		{
			getline(instream, line);
			// Expect a line of "="
			if (END_OF_SONGS.compare(line) == 0)
			{
				lastSong = 1;
				break;
			}

		}

		getline(instream, line);
		// Expect a line of "title: ..."
		size_t pos = TITLE.size() + 2;
		string title = line.substr(pos);

		getline(instream, line);
		// Expect a line of "tags: {...}"

		vector < string > tagsVec = Parameters::split(getWordList(line),
				WORDS_SEPARATOR);
		map<string, int> tags;
		for (vector<string>::iterator it = tagsVec.begin(); it != tagsVec.end();
				++it)
		{
			assert(it + 1 != tagsVec.end()); // wrong tags. (the tags are odd)
			tags[*it] = stoi(*(++it));
		}

		vector < string > lyrics;
		string lyricsBy = "";
		map<string, int> instruments;
		string performedBy = "";
		int bpm = 0;

		getline(instream, line);
		// Expect either lyrics or instruments.
		if (line.substr(0, LYRICS.size()).compare(LYRICS) == 0)
		{
			// Then we have a lyric song

			// Lets get the lyrics:
			lyrics = Parameters::split(getWordList(line), WORDS_SEPARATOR);

			// Lets get the lyricsBy:
			getline(instream, line);
			pos = LYRICS_BY.size() + 2;
			lyricsBy = line.substr(pos);

			songs.push_back(
					unique_ptr < Song
							> (new Lyrical(title, lyricsBy, tags, lyrics)));
		}
		else
		{
			// Then we have an instrumental song

			// Lets get the instruments:
			vector < string > instrumentsVec = Parameters::split(
					getWordList(line), WORDS_SEPARATOR);
			for (auto instrument : instrumentsVec)
			{
				instruments[instrument] = 1;
			}

			// Lets get the performedBy:
			getline(instream, line);
			pos = PERFORMED_BY.size() + 2;
			performedBy = line.substr(pos);

			// Lets see if we have bpm:
			if (!instream.good())
			{
				break;
			}
			getline(instream, line);
			if (END_OF_SONGS.compare(line) == 0)
			{
				lastSong = 1;
			}

			if (line.substr(0, BPM.size()).compare(BPM) == 0)
			{

				pos = BPM.size() + 2;
				bpm = stoi(line.substr(pos));

			}
			else
			{
				assert(
						(line.compare(SEPARATOR) == 0)
								|| (line.compare(END_OF_SONGS) == 0));
			}
			songs.push_back(
					unique_ptr < Song
							> (new Instrumental(title, performedBy, tags,
									instruments, bpm)));
		}
	}

	instream.close();

	return songs;

}

/**
 * a helper function .
 * @return a string within {}.
 */
string SongsFactory::getWordList(const string line)
{

	size_t pos1 = line.find("{");
	size_t pos2 = line.find("}");

	return line.substr(pos1 + 1, pos2 - pos1 - 1);
}

//ifstream instream openFile(string fileName)
//{
//
//    ifstream instream(fileName.c_str());
//    if (!instream.is_open())
//    {
//        cerr << "Error! Can't open file: " << songsFileName << "." << endl;
//    }
//    return instream
//
//}

