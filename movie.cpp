//Heitkemper, Peter
//course.cpp
//3/15/2021

//******************************************************************************
#include "hash.h"

//Default Constructor
Movie::Movie() :title{ "" }, director{ "" }, stars{ "" }, rating{ 0.0 }, year{ 0 }, genre{ "" }, plot{ "" }, review{ "" }, isSorted{ false } {}


//Paramaterized Constuctor
Movie::Movie(string title, string director, string stars, float rating, int year, string genre, string plot, string review) :
  title{ title }, director{ director }, stars{ stars }, rating{ rating }, year{ year }, genre{ genre }, plot{ plot }, review{ review }, isSorted{ false } {}

//getter functions

string Movie::getTitle() { return title; }
string Movie::getDirector() { return director; }
string Movie::getStars() { return stars; }
string Movie::getGenre() { return genre; }
string Movie::getPlot() { return plot; }
string Movie::getReview() { return review; }
float Movie::getRating() { return rating; }
int Movie::getYear() { return year; }
//bool Movie::getSorted() { return isSorted; }
//void Movie::setSorted(Movie M) { M.isSorted = true; }

//Default Constructor
MovieNode::MovieNode() : title{ "" }, value{ Movie() }, next{ nullptr }{}
//Paramaterized Constuctor
MovieNode::MovieNode(string title, Movie in) : title{ title }, value{ in }, next{ nullptr }{}

//getter functions that call other getter functions
//string MovieNode::getTitle() { return value.getTitle(); }
string MovieNode::getDirector() { return value.getDirector(); }
string MovieNode::getStars() { return value.getStars(); }
string MovieNode::getGenre() { return value.getGenre(); }
string MovieNode::getPlot() { return value.getPlot(); }
string MovieNode::getReview() { return value.getReview(); }
int MovieNode::getYear() { return value.getYear(); }
//int MovieNode::getKey() { return key; }
string MovieNode::getTitle() { return title; }
float MovieNode::getRating() { return value.getRating(); }

MovieNode* MovieNode::getNext() { return next; }
void MovieNode::setNext(MovieNode* n) { next = n; }









//
////Default Constructor
//Course::Course():courseNo{-1}, title{""}, date{""}, time{""}, instructor{""}{}
//
////Paramaterized Constuctor
//Course::Course(int coNo,string title, string d, string time, string instrct):
//courseNo{coNo},title{title}, date{d}, time{time},instructor{instrct} {}
//
////getter functions
//int Course::getCourseNo() { return courseNo; }
//string Course::getTitle() { return title;}
//string Course::getDate() { return date; }
//string Course::getTime() { return time; }
//string Course::getInstructor() { return instructor; }
//
////Default Constructor
//CourseNode::CourseNode(): key{ -1 }, value{ Course() }, next{nullptr}{}
////Paramaterized Constuctor
//CourseNode::CourseNode(int k, Course in):key{k}, value{in}, next{nullptr}{}
//
////getter functions that call other getter functions
//string CourseNode::getTitle() { return value.getTitle(); }
//string CourseNode::getDate() { return value.getDate(); }
//string CourseNode::getTime() { return value.getTime(); }
//string CourseNode::getInstructor() { return value.getInstructor(); }
//int CourseNode::getCourseNo() { return value.getCourseNo();}
//int CourseNode::getKey() { return key; }
//CourseNode* CourseNode::getNext() { return next; }
//void CourseNode::setNext(CourseNode* n) { next = n; }
