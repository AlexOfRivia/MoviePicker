#ifndef MOVIE_H_
#define MOVIE_H_
#include <iostream>
#include <string>


class Movie
{
    public:
    void setMovie()
    {
        std::cout<<"\n\nEnter movie title: ";
        std::cin>>movieTitle;
    }
    void printMovie()
    {
        std::cout<<movieTitle;
    }
    private:
    std::string movieTitle;
};

#endif