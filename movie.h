#ifndef MOVIE_H_
#define MOVIE_H_
#include <iostream>
#include <string>
#include <fstream>


class Movie
{
    public:
    void setMovie();
    void printMovie();
    void addMovie(Movie movieArr[],int size);
    void removeMovie(Movie movieArr[],int size);
    void saveToFile(Movie movieArr[], int size, std::ofstream& file);
    void loadFromFile(Movie movieArr[], int size, std::ofstream& file);
    private:
    std::string movieTitle;
};

#endif