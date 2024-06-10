#ifndef MOVIE_H_
#define MOVIE_H_
#include <iostream>
#include <string>


class Movie
{
    /*TODO 
    - Think about method to load and save lists*/
    public:
    void setMovie();
    void printMovie();
    void addMovie(Movie movieArr[],int size);
    void removeMovie(Movie movieArr[],int size);
    private:
    std::string movieTitle;
};

#endif