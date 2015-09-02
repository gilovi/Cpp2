
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
#include "Instrumental.h"
#include "Lyrical.h"
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

    vector<uSongPtr> songs = SongsFactory::getSongs(string(argv[1]));
    Song::init(Parameters(string(argv[2])));
    vector<string> queries = readQueriesFromFile(string(argv[3]));

    for (auto &query : queries)
    {
        printQueryBegin(query);
        SortHelper s;
		for (auto &song : songs)
        {
            s.addItem((*song).calcScore(query));
        }
        vector<int> order = s.getSortedOrderInVector();
        for (auto place : order)
        {
            if (songs[place] <= 0)
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
    vector<string> queries;
    ifstream instream(queriesFileName.c_str());
    if (!instream.is_open())
    {
        cerr << "Error! Can't open file: " << queriesFileName << "." << endl;
    }

    string line = "" ;

    while (instream.good())
    {
        getline(instream, line);
        if (line.empty())
        {
            continue
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
    cout << "Query word: " << query <<endl;
    cout << endl;
}


//class base
//{
//
//    public:
//
//    struct A
//    {int a = 5;};
//    virtual void boo()
//        {
//            A c;
//            foo(c);
//        }
//protected:
//virtual void foo(A c)
//    {cout<< "base foo(): "<< c.a<<endl;}
//
//
//};
//
//class son : public base
//{
//    struct A
//    {
//        int a = 2;
//        int v = 7;
//    };
//
//public:
//    void boo()
//    {
//        A d;
//        foo(d);
//    }
//    void foo(A c)
//    {cout<< "son foo(): "<<c.v<<endl;}
//
//};
//
//int main ()
//{
//base b;
//son s;
//
//
//
//b.boo();
//s.boo();
//base *c = &s;
//c->boo();
//}

