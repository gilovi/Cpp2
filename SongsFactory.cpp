using namespace std;

#include <string>
#include <map>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <list>
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
const string LYRICS_BY = "lyricsBy";
const string INSTRUMENTS = "instruments";
const string PERFORMED_BY = "performedBy";
const string BPM = "bpm";
const char SPACE = ' ';

SongsFactory::SongsFactory()
{
    //ctor
}

SongsFactory::~SongsFactory()
{
    //dtor
}
vector <std::unique_ptr<Song>> SongsFactory::getSongs(std::string songsFileName)
{
    vector<std::unique_ptr<Song>> songs;

    ifstream instream(songsFileName.c_str());
    if (!instream.is_open())
    {
        cerr << "Error! Can't open file: " << songsFileName << "." << endl;
    }

    string line = "";



    int lastSong = 0;

    while(instream.good() && !lastSong)
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
        vector<string> tagsVec = split(getWordList(line), SPACE);
        map<string, int> tags;
        for (vector<string>::iterator it = tagsVec.begin() ; it != tagsVec.end(); it++)
        {
            assert(it + 1 == tagsVec.end()); // wrong tags. (the tags are odd)
            tags[*it] = stoi(*(++it));
        }

        vector<string> lyrics;
        string lyricsBy = "";
        vector<string> instruments ;
        string performedBy = "";
        string bpmStr = "";

        getline(instream, line);
        // Expect either lyrics or instruments.
        if (line.substr(0, LYRICS.size()).compare(LYRICS) == 0)
        {
            // Then we have a lyric song

            // Lets get the lyrics:
            lyrics = split(getWordList(line), SPACE);

            // Lets get the lyricsBy:
            getline(instream, line);
            pos = LYRICS_BY.size() + 2;
            lyricsBy = line.substr(pos);
            songs.push_back( unique_ptr<Song> (new Lyrical(title, lyricsBy, tags, lyrics)));
        }
        else
        {
            // Then we have an instrumental song

            // Lets get the instruments:
            instruments = split(getWordList(line), SPACE);

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
                bpmStr = line.substr(pos);

                songs.push_back( unique_ptr<Song> (new Instrumental(title, performedBy, tags, instruments, stoi(bpmStr))));
            }
            else
            {
                 assert ( (line.compare(SEPARATOR) == 0) || (line.compare(END_OF_SONGS) == 0));


                 // TODO....
            }
        }
    }

    instream.close();

    // return something


}

Parameters SongsFactory::readParamsFromFile(string songsFileName)
{

}

vector<std::string> SongsFactory::readQueriesFromFile(string songsFileName)
{

}

/**
* return all the line between {}
*/
string SongsFactory::getWordList(const string line)
{

    size_t pos1 = line.find("{");
    size_t pos2 = line.find("}");

    return line.substr(pos1+1,pos2-pos1-1);
}

vector<string> SongsFactory::split(const string& str, const char& delimiter)const {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;

  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }

  return internal;
}

