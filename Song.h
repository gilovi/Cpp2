#include <string>
#include<vector>
#include <map>
#include <iostream>

/**
* An abstract song class
*/
class Song
{
public:
    Song();
    Song(std::string& title, std::string& artist, std::vector<std::string> tags);
    virtual ~Song();

    virtual int calcScore(const std::string& input) const = 0 ;
    friend std::ostream& operator<<(std::ostream& os, const Song& song) ;

    static void init(std::map<std::string , std::vector<int>> parameters);

protected:
    static std::map<std::string , std::vector<int>> s_parameters;

    std::string _title;
    std::string _artist;
    std::vector<std::string> _tags;

    int calcTagScore() const;
    virtual void print(std::ostream& where) const;
};
