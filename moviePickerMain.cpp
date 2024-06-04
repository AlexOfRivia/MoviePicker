#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "movie.h"

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

int main()
{
    int movieAmount;
    int pickedMoviesAmount;
    int choice=0,choice2=0;
    Movie *movieList = new Movie[movieAmount];
    Movie *pickedMoviesList = new Movie[pickedMoviesAmount];

    movieAmount=0;
    pickedMoviesAmount=0;
    while(choice!=5)
    {
        std::cout<<"\n\n|=========MOVIE=PICKER=========|";
        std::cout<<"\n|1. Set Movie List.            |";
        std::cout<<"\n|2. Pick Random Movies.        |";
        std::cout<<"\n|3. Show Picked Movies.        |";
        std::cout<<"\n|4. Manage Your Lists          |";
        std::cout<<"\n|5. Exit                       |";
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
            case 4:
            {
                std::cout<<"\n|========LIST=MANAGER========|";
                std::cout<<"\n|1. Show Movie List.         |";
                std::cout<<"\n|2. Clear Movie List.        |";
                std::cout<<"\n|3. Clear Picked Movie List. |";
                std::cout<<"\n|4. Return.                  |";
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
                        if(movieAmount==0)
                        {
                            std::cout<<"\nYour Movie List Is Already Empty. Feel Free To Add Some New Titles!";
                        } else {
                            movieAmount=0;
                        }
                        break;
                    }
                    case 3:
                    {
                        if(pickedMoviesAmount==0)
                        {
                            std::cout<<"\nYour Picked Movie List Is Already Empty. Feel Free To Add Some New Titles!";
                        } else {
                            pickedMoviesAmount=0;
                        }
                        break;
                    }
                    case 4:
                    {
                        break;
                    }
                }
                break;
            }
            case 5:
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