/*
//
Authors: Jennifer Ai (JenniferAi@my.unt.edu), Cindy Liang (CindyLiang@my.unt.edu), Lisa Lin (LisaLin@my.unt.edu) 
Date: 11/24/2020
Instructor: Dr. Shrestha
Description: Anthony the Ant game
*/

#include <iostream>
#include <ctime>//to generate a seeded random
#include <cstdlib> //to generate a seeded random
#include <iomanip> //so that we can use IO manipulators
using namespace std;

const int COL = 10; //global constant for the number of columns

//function declarations
void studentInfo(); 
void initArr(int **antCol);
void dispArray(string **display);
void loss (string **display, int **antCol);
