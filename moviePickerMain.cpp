#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "movie.h"
#include <fstream>
#include "movie.cpp"


/*
This short program is for those nights, when you want to watch 
a movie - heck, maybe even pull off a movie marathon, but just 
can't decide what to choose from a vast ocean of movies.

I am well aware, that as of now, this interface could've been designed a little 
bit better, however it has to do for now. Maybe in the future I'll make a GUI.
*/

void pickMovies(Movie movieArr[], Movie pickMovieArr[], int movAmt, int pickMovAmt)
{
    srand(time(NULL));
    for(int i=0;i<pickMovAmt;i++)
    {
        int index = rand()%(movAmt-0+1)+0;
        pickMovieArr[i] = movieArr[index];
        index = 0;
    }
}
void editMovie(Movie movieArr[], int index)
{
    movieArr[(index-1)].setMovie();
}

/*TODO
- maybe load list from a file?
*/

int main()
{
    int movieAmount; //Size of movie list array
    int pickedMoviesAmount; //Size of picked movies array
    int choice=0,choice2=0,choice3=0; //Basically just choices for the switches
    Movie *movieList = new Movie[movieAmount];
    Movie *pickedMoviesList = new Movie[pickedMoviesAmount];
    std::string fileName;

    movieAmount=0;
    pickedMoviesAmount=0;
    while(choice!=6) //Main interface
    {
        std::cout<<"\n\n|=========MOVIE=PICKER=========|";
        std::cout<<"\n|1. Set Movie List.            |";
        std::cout<<"\n|2. Pick Random Movies.        |";
        std::cout<<"\n|3. Show Picked Movies.        |";
        std::cout<<"\n|4. Manage Your Lists          |";
        std::cout<<"\n|5. Save Movie List To File    |";
        std::cout<<"\n|6. Exit                       |";
        std::cout<<"\n|==============================|";
        std::cout<<"\nWhat Do You Want To Do: ";
        std::cin>>choice;
        switch(choice)
        {
            case 1:
            {
                std::cout<<"\nEnter How Many Movies Would You Like To Choose From: ";
                std::cin>>movieAmount;
                for(int i=0;i<movieAmount;i++)
                {
                    movieList[i].setMovie();
                }
                break;
            }
            case 2:
            {
                if(movieAmount==0)
                {
                   std::cout<<"\nThere Are No Movies In Your Movie List. Try Adding Some!";
                } else {
                    std::cout<<"\nEnter How Many Movies Do You Want To Pick: ";
                    std::cin>>pickedMoviesAmount;
                    pickMovies(movieList,pickedMoviesList,movieAmount,pickedMoviesAmount);
                }
                break;
            }
            case 3:
            {
                if(pickedMoviesAmount==0)
                {
                   std::cout<<"\nThere Are No Movies In Your Picked Movie List, Try Picking Some!";
                } else {
                    for(int i=0;i<pickedMoviesAmount;i++)
                    {
                        std::cout<<"\n"<<(i+1)<<". ";
                        pickedMoviesList[i].printMovie();
                    }
                }
                break;
            }
            case 4: //Managing interface
            {
                std::cout<<"\n|========LIST=MANAGER========|";
                std::cout<<"\n|1. Show Movie List.         |";
                std::cout<<"\n|2. Edit Movies.             |";
                std::cout<<"\n|3. Clear Movie List.        |";
                std::cout<<"\n|4. Clear Picked Movie List. |";
                std::cout<<"\n|5. Add/Remove Movie.        |";
                std::cout<<"\n|6. Return.                  |";
                std::cout<<"\n|============================|";
                std::cout<<"\nWhat Do You Want To Do: ";
                std::cin>>choice2;
                switch(choice2)
                {
                    case 1:
                    {
                        if(movieAmount==0)
                        {
                            std::cout<<"\nThere Are No Movies In Your Movie List. Try Adding Some!";
                        } else {
                            for(int i=0;i<movieAmount;i++)
                            {
                                std::cout<<"\n"<<(i+1)<<". ";
                                movieList[i].printMovie();
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        int pos; //movie position to edit
                        if(movieAmount==0)
                        {
                            std::cout<<"\nThere Are No Movies In Your Movie List. Try Adding Some!";
                        } else {
                            for(int i=0;i<movieAmount;i++)
                            {
                                std::cout<<"\n"<<(i+1)<<". ";
                                movieList[i].printMovie();
                            }
                            std::cout<<"\nWhich Movie Position Do You Wish to Edit: ";
                            std::cin>>pos;
                            editMovie(movieList,pos);
                        }
                        break;
                    }
                    case 3:
                    {
                        if(movieAmount==0)
                        {
                            std::cout<<"\nYour Movie List Is Already Empty. Feel Free To Add Some New Titles!";
                        } else {
                            movieAmount=0;
                        }
                        break;
                    }
                    case 4:
                    {
                        if(pickedMoviesAmount==0)
                        {
                            std::cout<<"\nYour Picked Movie List Is Already Empty. Feel Free To Add Some New Titles!";
                        } else {
                            pickedMoviesAmount=0;
                        }
                        break;
                    }
                    case 5:
                    {
                        std::cout<<"\n|========LIST=MANAGER========|";
                        std::cout<<"\n|1. Add Movie.               |";
                        std::cout<<"\n|2. Removie Movie.           |";
                        std::cout<<"\n|3. Return.                  |";
                        std::cout<<"\n|============================|";
                        std::cout<<"\nWhat Do You Want To Do: ";
                        std::cin>>choice3;
                        switch(choice3)
                        {
                            case 1:
                            {
                                movieList->addMovie(movieList,movieAmount);
                                movieAmount++; //Increments the movie list array size
                                break;
                            }
                            case 2:
                            {
                                movieList->removeMovie(movieList,movieAmount);
                                if(movieAmount!=0)
                                {       
                                    movieAmount--; //Decrements the movie list array size
                                }
                                break;
                            }
                            case 3:
                            {
                                break;
                            }
                        }
                        break;
                    }
                    case 6:
                    {
                        break;
                    }
                }
                break;
            }
            case 5:
            {
                std::cin.ignore();
                std::cout<<"How Do You Want to Name Your List: ";
                std::getline(std::cin,fileName);
                std::ofstream movieFile(fileName);
                movieList->saveToFile(movieList,movieAmount,movieFile);
                movieFile.close();
                break;
            }
            case 6:
            {
                std::cout<<"\nThank You For Using My Movie Picker Program - Enjoy Your Show!";
                break;
            }
            default:
            {
                std::cout<<"Err...";
                break;
            }
        }
    }
    delete [] movieList;
    delete [] pickedMoviesList;
}