/*
Author: Jennifer Ai (JenniferAi@my.unt.edu), Cindy Liang (CindyLiang@my.unt.edu), Lisa Lin (LisaLin@my.unt.edu) 
Date: 09/27/2020
Instructor: Dr. Shrestha
Description: Personal Concierge App that displays a personal greeting, provides the weather, and plays a guessing game with the user.
*/

#include <iostream>
#include <string>
using namespace std;

  //declaring enumerated data type for the 4 options the user can choose from
  enum Options {GREETINGS = 1, FORECAST = 2, GAME = 3, QUIT = 4};

int main() {

  // intro
  cout << "+----------------------------------------------+" << endl;
  cout << "|        Computer Science and Engineering      |" << endl;
  cout << "|       CSCE 1030.002 - Computer Science I     |" << endl;
  cout << "|   Jennifer Ai jla0325 JenniferAi@my.unt.edu  |" << endl;
  cout << "|   Cindy Liang cl0822 CindyLiang@my.unt.edu   |" << endl;
  cout << "|      Lisa Lin ll0484 LisaLin@my.unt.edu      |" << endl;
  cout << "+----------------------------------------------+" << endl; 
  
  string fullName;

  // prompting user to enter name
  cout << "Please enter your full name: "; getline(cin, fullName);

  //variable to store the user's choice
  int userChoice; 
  
  //variables for greeting option
  // obtaining current time from system
  time_t rawtime;
  string time_str;
  int time_int; // for later string to int conversion
  string timeOfDay;
  string temp; // place holder to modify time_str

  //variables for weather
  int randTemp;
  int randWeather; //random number to determine weather
  string weather;

  //randomly seeded
  srand(time(NULL));

  //variables for guessing game
   int guess;
   int my_num;
   bool correct;

  do
  {
    // menu display
    cout << "+******************* M E N U ******************+" << endl;
    cout << "| Personal Concierge App: Choose a Service     |" << endl; 
    cout << "| 1. Display Personal Greeting                 |" << endl; 
    cout << "| 2. Display Today's Weather Forecast          |" << endl; 
    cout << "| 3. Play a Guessing Game                      |" << endl; 
    cout << "| 4. Exit                                      |" << endl; 
    cout << "+**********************************************+" << endl;
    cout << "----> "; cin >> userChoice;

    Options updatedUserChoice = static_cast<Options>(userChoice);

    switch (updatedUserChoice) {

      // personal greeting option chosen
      case GREETINGS :
 
        // receiving the raw time when greeting is chosen
        rawtime = time(&rawtime);
        time_str = ctime(&rawtime);

        // displaying time of day
        cout << time_str;
        temp = time_str;

        temp = temp.substr(11, 5); // taking the string from the exact index of hour and minute
        temp.replace(2, 1, ""); // removing the colon

        // converting the string to an integer
        time_int = stoi(temp);
        if ((time_int >= 0) && (time_int <= 1159)){ // between 12 am and 11:59 am
          timeOfDay = "Morning";
        } else
        if ((time_int >= 1200) && (time_int <= 1759)){ // between 12 pm and 5:59 pm
          timeOfDay = "Afternoon";
        } else
        if ((time_int >= 1800) && (time_int <= 2359)){ // between 6 pm and 11:59 pm
          timeOfDay = "Evening";
        }

        // displaying the time of day and greeting
        cout << "Good " << timeOfDay << ", " << fullName << ". I hope you're having a nice day!" << endl;

        break;

      // weather forecast chosen
      case FORECAST:

        randTemp = rand() % (95 + 10); //between 10 and 105

        randWeather = rand() % (1+1); //rand between 0 and 1

        if (randWeather == 0){ 
          weather = "sunny";
        }

        else if (randWeather == 1){
          weather = "rainy";
        }

        cout << "Today's forecast high of " << randTemp << " degrees Fahrenheit and it is " << weather << "." << endl;

        break;

      // guessing game chosen
      case GAME:
      // if the user chooses the guessing game

        //displaying directions to the game
        cout << "You have 3 chances to guess my number from 1 to 10!" << endl;

        my_num = (rand()%10)+1; //intializing the number that is to be guessed
        correct = false; //boolean that will be used later to decide whether or not to print the statement displaying the correct number

        //looping for 3 times for the user to guess the number
        for (int i = 1; i <= 3; ++i)
        {
          cout << "Guess #" << i <<": "; cin>>guess;
          if (my_num == guess) 
          {
            cout << "Correct in "<< i <<" guesses! Nice job!!" << endl;
            correct = true;
            break;
          }
          else if (my_num > guess)
          {
            cout << "You guess (" <<guess<<") is too low! Guess a higher number" << endl;
          }
          else 
          {
            cout << "Your guess ("<<guess<<") is too high! Guess a lower number" << endl;
          }
        }
        if (!correct) //if the user did not choose the correct number out of their 3 attempts, the computer will display the correct number
        {
          cout << "Sorry, my number was " << my_num <<" !" << endl;
        }
        break;

      case QUIT:
        cout << "Thank you for using the Personal Concierge App." << endl;
        break;

      default:
          cout << userChoice <<  " is an invalid selection. Please choose option 1 - 4" << endl;
          break;
    }
  }
  // exit
  while(userChoice !=4);
  return 0;
}
