#ifndef MOVIE_H_
#define MOVIE_H_
#include <iostream>
#include <string>


class Movie
{
    public:
    void setMovie();
    void printMovie();
    private:
    std::string movieTitle;
};

#endif