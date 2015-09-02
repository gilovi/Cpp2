#ifndef PARAMETERS_H
#define PARAMETERS_H

//#include "Instrumental.h"
//#include "Lyrical.h"
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <cstdio>
/**
 * A class for keeping the learned songs parameters
 */

class Parameters
{
    public:
        /**
         * default ctor
         */
        Parameters();
        /**
         * ctor from file path.
         */
        Parameters(std::string paramsFile);
        /**
         * default dtor
         */
        virtual ~Parameters();
        /**
         * a static helper function to split a string around a given delimeter
         */
        static std::vector<std::string> split(const std::string& str, const char& delimiter) ;
        /**
         * _tagMatchWeight setter
         */
        void setTagMatchWeight(int w);
        /**
         * _lyricsMatchWeight setter
         */
        void setLyricsMatchWeight(int w);
        /**
         * _instrumentMatchWeight setter
         */
        void setInstrumentMatchWeight(int w);
        /**
         * _bpmLikelihoodWeight setter
         */
        void setBpmLikelihoodWeight(int w);
        /**
         * a method to add a bpm word to the parameters. (e.g happy: 3.2 ,2.1)
         */
        void addBmpWord( std::string word, std::vector<double> vals);

        friend class Song;
        friend class Instrumental;
        friend class Lyrical;

    private:
            int _tagMatchWeight = -1;

            int _lyricsMatchWeight = -1;

            int _instrumentMatchWeight = -1;
            int _bpmLikelihoodWeight;
            std::map<std::string, std::vector<double>> _bmpParams;


};

#endif // PARAMETERS_H
