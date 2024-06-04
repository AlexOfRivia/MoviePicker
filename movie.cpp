#include "movie.h"

void Movie::setMovie()
{
    std::cout<<"\n\nEnter movie title: ";
    std::cin>>this->movieTitle;
}

void Movie::printMovie()
{
    std::cout<<this->movieTitle;
}