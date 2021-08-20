//Heitkemper, Peter
//hashMyMovie.cpp
//7/15/2021

//write drama categories with hyphen: drama-commedy
//******************************************************************************
#include "hash.h"

int main(){
  //Default constructor
  HashTable h;

  string fileName = "MovieList.csv";
  string first, title, director, stars, genre,titleIn,plot, ratingIn, yearIn, review, genreIN;
  float rating;
  int year, option, index, x, key;
  bool exit = false;
  char userIn[256];

  cout << "Welcome! Processing the " << fileName << " file..." << endl;
  cout << endl;

  //reading in file
  ifstream file(fileName);
  if (!file.is_open()) {
    cout << "ERROR";
    return -1;
  }
  //first line discarded
  getline(file, first);
  //extract all data
  while (file.good())
  {
    getline(file, title, ',');
    cout << title << endl;
    //title = stoi(titleIn.erase(0, 5));
    //cout << courseNo << endl;
    getline(file, director, ',');
    cout << director << endl;
    getline(file, stars, ',');
    cout << stars << endl;
    getline(file, ratingIn, ',');
    rating = stof(ratingIn);
    cout << rating << endl;
    getline(file, yearIn, ',');
    year = stoi(yearIn);
    cout << year << endl;
    getline(file,genre, ',');
    cout << genre << endl;
    getline(file, plot, ',');
    cout << plot << endl;
    getline(file, review, '\n');
    cout << review << endl;


    h.insert(title, Movie(title, director, stars, rating, year, genre, plot, review));
    // cout << "inserted " << courseIn << endl;
  }
  cout << endl;
  cout << endl;
  cout << "Hello! What would you like to do with the SQ21 schedule? " << endl;
  cout << endl;
  while(!exit) {
    cout << "1. Print Watch List, 2. Remove a movie," << endl;
    cout << "3. View movie info, 4. Sort By Rating," << endl;
    cout << "5. Choose Genre 6. Print index, 7. Exit program : ";
    cin >> option;
    cout << endl;
    cout << endl;
    if (option == 1) {
      cout << endl;
      cout << endl;
      h.printAll();
      cout << endl;
      cout << "*************************" << endl;
    } 
    else if (option == 2) {
      cin.ignore(256, '\n');
    tryAgain:
      cout << "Enter the title of the movie you want to remove: ";  
      cin.getline(userIn, 256);
      //while(!cin.fail()) {                                                 //check for valid input
      //  cout << "Please enter a valid course number: " << endl;
      //  cin.clear();
      //  cin.ignore(256, '\n');
      //  cin >> title;
      //}
      title = h.remove(userIn);
      if(title == "") {     //check if course in schedule
        cin.clear();
        cout << "That movie is not on the Watch List. Try Again?(y/n)" << endl;
        cin.getline(userIn, 256);
        if (userIn[0] == 'y') {
          goto tryAgain;
        }
        //cin.ignore(256, '\n');

      } else {
        cout << "Removing \"" << title << "\" from the Watch List." << endl;
      }
      cout << endl;
      cout << "*************************" << endl;
    }
    else if (option == 3) {
      cin.ignore(256, '\n');
      cout << "Enter the title of the movie: ";
      cin.getline(userIn, 256);

      cout << endl;
      h.movieInfo(userIn);
      cout << endl;
      cout << "*************************" << endl;
    }
    else if (option == 4) {
      cout << "Movies sorted by rating:";
     /* cin >> day;
      x = h.taughtOn(day);
      cout << endl;
      cout << x << " course(s) taught on " << day;
      cout << endl;
      cout << "*************************" << endl;*/
    }
    else if (option == 5) {

      h.printAllGenres();
      cout << "Enter a genre from the list above." << endl;
      
      cin >> genreIN;

      h.printGenre(genreIN);

      /* cin >> day;
       x = h.taughtOn(day);
       cout << endl;
       cout << x << " course(s) taught on " << day;
       cout << endl;
       cout << "*************************" << endl;*/
    }
    else if (option == 6) {
      cout << "Which index do you want to print? ";
      cin >> index;   //check for valid idex within table
      while ( index < 0 || index > TABLE_SIZE - 1||cin.fail()) {
        cout << "Please enter an index from 0 to " << TABLE_SIZE - 1 
        << ": ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> index;
      }
      cout << endl;
      h.printIdx(index);
      cout << endl;
      cout << "*************************" << endl;
    }
    else if (option == 7) {
      cout << "GoodBye!" << endl;
      exit = true;
    }
    else {
      cout << "Please enter a valid option. " << endl;
      cout << endl;
    }
  }

  /*Begin Testing*************************
  Course k;
  CourseNode p;
  cout << "Default Course constuctor " << endl;
  cout << k.getTime() << endl;
  cout << k.getDate() << endl;
  cout << k.getCourseNo() << endl;
  cout << "Default CourseNode constuctor " << endl;
  cout << p.getKey() << endl;
  cout << p.getInstructor() << endl;
  *************************End Testing*/
  return 0;
}