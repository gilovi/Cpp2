#include "Song.h"
#include <string>
#include<vector>


class Lyrical : Song
{
public:
    Lyrical(std::string& title, std::string& artist, std::vector<std::string> tags, std::vector<std::string> lyrics);

private:
    typedef Song super;

    std::vector<std::string> _lyrics;

    int calcScore(const std::string input) const;
    int calcLyricsMatchScore();
    void print(std::ostream& where) const override;

};
