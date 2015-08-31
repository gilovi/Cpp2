ifndef PARAMETERS_H
define PARAMETERS_H

#include "Instrumental.h"
#include "Lyrical.h"


class Parameters
{
    public:
        Parameters();
        virtual ~Parameters();

        friend class Instrumental ;

        void setTagMatchWeight(int w);
        void setLyricsMatchWeight(int w);
        void setInstrumentMatchWeight(int w);
        void setBpmLikelihoodWeight(int w);
        void addBmpWord( std::string word, int vals[2]);

    private:
            int tagMatchWeight = -1;

            int lyricsMatchWeight = -1;

            int instrumentMatchWeight = -1;
            int bpmLikelihoodWeight[2];
            std::map<std::string, int[2]> bmpWords;


};

endif // PARAMETERS_H
