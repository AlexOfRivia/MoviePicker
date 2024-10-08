#include "movie.h"

void Movie::setMovie()
{
    std::cin.ignore();
    std::cout<<"\n\nEnter movie title: ";
    std::getline(std::cin, this->movieTitle);
}

void Movie::addMovie(Movie movieArr[],int size)
{
    int a = size;
    movieArr[a].setMovie(); //adds a movie to the last array index
}

void Movie::removeMovie(Movie movieArr[],int size)
{
    int a;
    if(size==0)
    {
        std::cout<<"\nThere Are No Movies In Your Movie List, Try Adding Some!";
        return;
    }
    for(int i=0;i<size;i++)
    {
        std::cout<<"\n"<<(i+1)<<". ";
        movieArr[i].printMovie();
    }
    std::cout<<"\nSelect a Movie to Remove: ";
    std::cin>>a;
    for(int j=(a-1);j<size;j++)
    {
        movieArr[j]=movieArr[j+1];
    }
}

void Movie::saveToFile(Movie movieArr[], int size, std::ofstream& file)
{
    for(int i=0;i<size;i++)
    {
        file <<(i+1)<<". " << movieArr[i].movieTitle<<"\n";
    }
}

void Movie::loadFromFile(Movie movieArr[], int size, std::ofstream& file)
{
    /* PREPPING FOR LOADING MOVIE LIST FROM FILE
    for(int i=0;i<size;i++)
    {

    }*/
}

void Movie::printMovie()
{
    std::cout<<this->movieTitle;
}