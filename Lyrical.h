//#ifndef LYRICAL_H
//#define LYRICAL_H


#include "Song.h"
#include "Parameters.h"
#include<string>
#include<vector>
#include<map>


class Lyrical : Song
{
public:
    Lyrical(std::string& title, std::string& artist, std::map<std::string, int> tags, std::vector<std::string> lyrics);

private:
    std::vector<std::string> _lyrics;

    int calcScore(const std::string input) const;
    int calcLyricsMatchScore(const std::string query);
    void _print(std::ostream& where) const override;
    void _printScore(const std::string& query) const;

};

//#endif
