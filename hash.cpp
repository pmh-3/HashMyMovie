//Heitkemper, Peter
//hash.cpp
//3/15/2021

//******************************************************************************
#include "hash.h"
#include <string>


//Default constuctor
HashTable::HashTable() {
  movieCount = 0; //keeps track of courses in schedule
  i = 0;  //initilization not necessary
  key = 0;
  string title = "";
  //day ="";
  //dynamically create array of courseNode pointers 
  watchList = new MovieNode * [TABLE_SIZE];
  //initialize all pointers to null
  for (int i = 0; i < TABLE_SIZE; i++) {
  watchList[i] = nullptr;
  }
}

HashTable::~HashTable() {
  //delete every linked list at each index 
  for (int i = 0; i < TABLE_SIZE; i++) {
    deleteAll(watchList[i]);
  }
  delete [] watchList;
}

void HashTable::deleteAll(MovieNode* in) {
  if (!in) {  //base case
    delete in;
    in = nullptr;
    return;
  }else {
    deleteAll(in->getNext()); //recursive call
    delete in;
    in = nullptr;
  }
}

int HashTable::hashKey(string title) {
  //calculate index based on key
  //split 4 digit key into 2, two digit components, 
  //sum, divide by size of table, return remainder
  key = 0;
  cout << "Title to hash: " << title << endl;
  for (int i = 0; i <= title.length(); i++) {
    key = key + (int)title[i];
    cout << "key: " << key << endl;
    key = key + 1111; 
  }
  key = key % 10000;
  cout << "key: " << key << endl;
  
  return ((key / 100 + key % 100) % TABLE_SIZE);
}


void HashTable::insert(string title, Movie value) {
  int i = hashKey(title); //get hash table index
  MovieNode* current = watchList[i];
  while (current) {    //loop until nullptr is reached at end of list
    if (current->getTitle() == title) { 
      std::cout << "The movie is already on the watchList." << endl;
      return;
    }
    else if (!(current->getNext())) { //insert node if next is nullptr
      current->setNext(new MovieNode(title, value));//link new node
      movieCount++;
      //calculate and Print load factor
      float loadFactor = (float)movieCount / (float)TABLE_SIZE;
      std::cout << "The load factor is " << loadFactor << endl;
      return;
    } 
    else {
      current = current->getNext();//move forward in list
    }
  }  
  //Create courseNode at first index
  watchList[i] = new MovieNode(title, value);
  movieCount++;
  //calculate and Print load factor
  float loadFactor = (float)movieCount / (float)TABLE_SIZE;
  cout << "The load factor is " << loadFactor << endl;
}

string HashTable::remove(string title) {
  int i = hashKey(title);             //get hash table index
  if (watchList[i] == nullptr) {     //index empty
    return "";
  } else {
    MovieNode* current = watchList[i];
    MovieNode* nxtPtr = watchList[i]->getNext();
    //Occurs if course is head
    if (current->getTitle() == title) {
      string removed = current->getTitle();//store title
      delete current; //remove
      watchList[i] = nxtPtr;
      movieCount--;
      return removed;
    } else {
      while (nxtPtr != nullptr) {    //course is within linked list
        if (nxtPtr->getTitle() == title) {
          string removed = nxtPtr->getTitle();
          current->setNext(nxtPtr->getNext());
          delete nxtPtr;
          nxtPtr = nullptr;
          movieCount--;
          return removed;
        } else {
          nxtPtr = nxtPtr->getNext();
        }
      }
     return "";//course not found
    }
  }
}
//change each function to accept title
void HashTable::movieInfo(string title) {
  int i = hashKey(title);//get hash key
  MovieNode* current = watchList[i];
  while (current) {
    if (current->getTitle() == title) {
      cout<<"Title: "<<current->getTitle()<<endl;
      cout << "Director: " << current->getDirector() << endl;
      cout << "Staring: " << current->getStars() << endl;
      cout << "Rating: " << current->getRating() << endl;
      cout << "Genre: " << current->getGenre() << endl;
      cout << "Year: " << current->getYear() << endl;
      cout << "Plot: " << current->getPlot() << endl;
      cout << "Review: " << current->getReview() << endl;
      return;
    } else {
      current = current->getNext();//move forward in list
    }
  }
  cout<<"That movie is not on the Watch List." << endl;
  return;
}

void HashTable::printAll() {
  for (int i = 0; i < TABLE_SIZE; i++) { //loop through array
    MovieNode* current = watchList[i];
    while (current) {                    //print every node in list
      cout << "Title: " << current->getTitle() << endl;
      cout << "Genre: " << current->getGenre() << endl;
      cout << "Rating: " << current->getRating() << endl;
      cout << "Year: " << current->getYear() << endl;
      current = current->getNext();
      cout << endl;
    }   
  }
  return;
}

void HashTable::printIdx(int i) {
  if (!watchList[i]) {
    cout << "No movies at index " << i << endl;
  }
  MovieNode* current = watchList[i];
  while (current) {
    //cout << "break3";
    cout << "Title: " << current->getTitle() << endl;
    cout << endl;
    current = current->getNext();
  }
  return;
}


void HashTable::printAllGenres() {
  cout << "All Genres:" << endl;
  for (int i = 0; i < TABLE_SIZE; i++) { //loop through array
    MovieNode* current = watchList[i];
    while (current) {                    //print every node in list
      cout  << current->getGenre() << endl;
      current = current->getNext();
    }
  }
  return;
}
 
void HashTable::printGenre(string gIn) {
  cout << gIn << " Movies:" << endl;
  for (int i = 0; i < TABLE_SIZE; i++) { //loop through array
    MovieNode* current = watchList[i];
    while (current) {                    //print every node in list
      if (current->getGenre() == gIn) {
        cout << current->getTitle() << endl;
      }
      current = current->getNext();
    }
  }
  return;
}


void HashTable::sortByRating() {
  Movie sortList[50];
  max
  for (int i = 0; i < TABLE_SIZE; i++) { //loop through array
    MovieNode* current = watchList[i];
    while (current) {                    //print every node in list
      if()
      cout << "Title: " << current->getTitle() << endl;
   
      cout << "Rating: " << current->getRating() << endl;
      current = current->getNext();
      cout << endl;
    }
  }
  return;
}
//int HashTable::taughtOn(string day) {
//  int count = 0;
//  for (int i = 0; i < TABLE_SIZE; i++) {
//    CourseNode* current = schedule[i];
//    while (current) {
//      bool check = true;
//      string date = current->getDate();
//      size_t found = date.find(day);
//      //checks if T is followed by an h, dont confuse Tuesday with Thursday
//      if (day == "T" && current->getDate()[found + 1] == 'h') {
//        check = false;//not Tuesday
//      }//if day found, print info
//      if (found != string::npos && check) {
//        count++;//number of courses on day
//        cout<<"CPSC "<<current->getCourseNo()<<" - "<<current->getTitle()<<endl;
//        cout <<  current->getDate() <<" "<< current->getTime()<< endl;
//        cout << "Instructor: Prof. " << current->getInstructor() << endl;
//      }
//      current = current->getNext();
//    }
//  }
//  return count;
//}
