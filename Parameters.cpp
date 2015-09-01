#include "Parameters.h"
#include <iostream>
#include <fstream>
#include <string>

Parameters::Parameters()
{
    //ctor
}

Parameters::Parameters(std::ifstream paramsFile)
{

}

Parameters::~Parameters()
{
    //dtor
}

void Parameters::setTagMatchWeight(int w)
{

}

void Parameters::setLyricsMatchWeight(int w)
{

}

void Parameters::setInstrumentMatchWeight(int w)
{

}

void Parameters::setBpmLikelihoodWeight(int w)
{

}

void Parameters::addBmpWord(std::string word, int vals[2])
{

}
