/*
Authors: Jennifer Ai (JenniferAi@my.unt.edu), Cindy Liang (CindyLiang@my.unt.edu), Lisa Lin (LisaLin@my.unt.edu) 
Date: 10/25/2020
Instructor: Dr. Shrestha
Description: Personal Concierge App that displays a personal greeting, provides the weather, and plays a guessing game with the user.
*/

#include <iostream>
#include <string> //access to the string library

//to be able to generate a seeded random
#include <cstdlib>
#include <ctime>

using namespace std;

//declaring a global constant to be the length of the array for the functions setTemp and dispWeather
const int MAX_LENGTH = 15;

//declaring global enumerated data type for the 4 options the user can choose from
enum Options {GREETINGS = 1, WEATHER = 2, GAME = 3, QUIT = 4};

//declaring functions
int getCurrentHours_OR_Month(bool choice);
void fixName(string name);
void setTemp(int tempRange[][MAX_LENGTH], int& numberDays);
void dispWeather();
void dispGreeting(string fullName);
void playGame();

//main
int main()
{

  // intro
  cout << "+----------------------------------------------+" << endl;
  cout << "|        Computer Science and Engineering      |" << endl;
  cout << "|       CSCE 1030.002 - Computer Science I     |" << endl;
  cout << "|   Jennifer Ai jla0325 JenniferAi@my.unt.edu  |" << endl;
  cout << "|   Cindy Liang cl0822 CindyLiang@my.unt.edu   |" << endl;
  cout << "|      Lisa Lin ll0484 LisaLin@my.unt.edu      |" << endl;
  cout << "+----------------------------------------------+" << endl; 
  
  string fullName; //to hold the user's name

  // prompting and reading in user's name
  cout << "Please enter your full name: "; getline(cin, fullName);

  //variable to store the user's choice
  int userChoice; 

  //randomly seeded
  srand(time(NULL));
  
  do 
  {
    // menu display
    cout << "+******************* M E N U ******************+" << endl;
    cout << "| Personal Concierge App: Choose a Service     |" << endl; 
    cout << "| 1. Display Personal Greeting                 |" << endl; 
    cout << "| 2. Display Today's Weather Status            |" << endl; 
    cout << "| 3. Play a Guessing Game                      |" << endl; 
    cout << "| 4. Exit                                      |" << endl; 
    cout << "+**********************************************+" << endl;
    cout << "----> "; cin >> userChoice; //getting the user's choice

    // int userChoice is converted to Options data type to be used for the switch statement
    Options updatedUserChoice = static_cast<Options>(userChoice);
    
    //switch cases to execute the menu option the user chose
    switch (updatedUserChoice)
     {
     // personal greeting option chosen
     case GREETINGS :
     dispGreeting(fullName);
     break;

     // weather status chosen
     case WEATHER:
     dispWeather();   
     break;
    
     // guessing game chosen
     case GAME:
     playGame();
     break;

     //quit is chosen
     case QUIT:
     cout << "Thank you for using the Personal Concierge App." << endl;
     break;
        
     //invalid character is chosen
     default:
     cout << userChoice <<  " is an invalid selection. Please choose option 1 - 4" << endl;
     break;
    } 
  } while(userChoice !=4); //will continue looping until the user chooses 4 which is to quit
  
  return 0;
}

//Defining the functions

/* Function:    getCurrentHours_OR_Month
   Parameters:  a bool representing the choice to return either the month or the year
   Return:      the int value of either the hour or the month
   Description: This function extracts the current time from the computer and parses the string into the hours and months to determine which to return based on which function calls it.
*/

int getCurrentHours_OR_Month(bool choice)
{
  // variables for greeting option
  time_t rawtime; // provided by assignment for the rawtime of the computer
  string time_str; // provided by assignment for the string of the raw time of the computer
  int time_int; // for later string to int conversion
  string month; // holds month string
  int month_int; // holds month as an integer
  int display; // value to be returned

  // receiving the raw time from computer
  rawtime = time(&rawtime);
  time_str = ctime(&rawtime);
  cout << time_str;

  // time_str is copied to month 
  month = time_str;

  time_str = time_str.substr(11, 2); // parsing or taking the string from the exact index of the hour
  month = month.substr(4, 3); // parsing or taking the string from the exact index of the month

  // converting the string to an integer
  time_int = stoi(time_str);
  
  // converting month string to month integer
  // assigns each month to a corresponding integer
  if (month == "Jan")
  {
    month_int = 1;
  } else
  if (month == "Feb")
  {
    month_int = 2;
  } else
  if (month == "Mar")
  {
    month_int = 3;
  } else
  if (month == "Apr")
  {
    month_int = 4;
  } else
  if (month == "May")
  {
    month_int = 5;
  } else
  if (month == "Jun")
  {
    month_int = 6;
  } else
  if (month == "Jul")
  {
    month_int = 7;
  } else
  if (month == "Aug")
  {
    month_int = 8;
  } else
  if (month == "Sep")
  {
    month_int = 9;
  } else
  if (month == "Oct")
  {
    month_int = 10;
  } else
  if (month == "Nov")
  {
    month_int = 11;
  } else
  if (month == "Dec")
  {
    month_int = 12;
  }         

  // deliberating whether to return the hour or month
  if (choice)
  {
    display = time_int;
  } else 
  {
    display = month_int;
  }
  return display;
}


/* Function:    fixName
   Parameters:  a string representing the user's inputted name
   Return:      none
   Description: This function corrects the user's inputted name by capitalizing each initial and making the other characters lowercase.
*/
void fixName(string name) 
{
  int j; //placeholder value
  // makes each character lowercase
  for (int i = 0; i < name.length(); ++i)
  {
    name.at(i) = tolower(name.at(i));
  }

  // the letter after the space becomes capitalized
  for (int i = 0; i < name.length(); ++i)
  {
    if (isspace(name.at(i)))
    {
      j = i + 1;
      name.at(j) = toupper(name.at(j));
    }
  }
  
  // first letter becomes capitalized
  name.at(0) = toupper(name.at(0));

  cout << name; //displaying the fixed name

}

/*
Function: setTemp
Parameters: a two-dimensional array of integers representing the range of tempreatures and an integer passed by reference representing the number of days that need to be calculated
Return: none/void
Description: This function sets up random tempreatures within a given range for each month.
*/
void setTemp(int tempRange[][MAX_LENGTH], int& numberDays) 
{
  //ask user for number of days the temp needs to be generated for.
  do
  {
    cout << "Compare with how many days? Choose a number less than 15:  ";
    cin >> numberDays;

  } while (numberDays >= 15); //repeats if the user chose a number greater than or equal to 15

  //generates random numbers from the specified range to be the temperature for each day and it is stored into the 2d array tempRange
  for (int k = 1; k <= 12 ; k++)
  {
    for (int l = 0; l < numberDays; l++)
    {
    //all temp ranges here stored into array element [k-1][l]:
      if (k==1) 
      {
        tempRange[k-1][l] = 37 + (rand() % 20); //janurary
      }
      if (k==2)
      {
        tempRange[k-1][l] = 41 + (rand() % 21); //feburary
      }
      if (k==3)
      {
        tempRange[k-1][l] = 49 + (rand() % 21); //march
      }
      if (k==4)
      {
        tempRange[k-1][l] = 56 + (rand() % 21); //april
      }
      if (k==5)
      {
        tempRange[k-1][l] = 65 + (rand() % 20); //may
      }
      if (k==6)
      {
        tempRange[k-1][l] = 73 + (rand() % 20); //june
      }
      if (k==7) 
      {
        tempRange[k-1][l] = 77 + (rand() % 20); //july
      }
      if (k==8)
      {
        tempRange[k-1][l] = 77 + (rand() % 20); //august
      }
      if (k==9)
      {
        tempRange[k-1][l] = 69 + (rand() % 21); //september
      }
      if (k==10)
      {
        tempRange[k-1][l] = 58 + (rand() % 22); //october
      }
      if (k==11)
      {
        tempRange[k-1][l] = 47 + (rand() % 21); //november
      }
      if (k==12)
      {
        tempRange[k-1][l] = 39 + (rand() % 20); //december
      }
    }  
  }
}

/*
Function: dispWeather
Parameters: none
Return: none
Description: Displays the relationship of the current temperature and average tempreature using the functions setTemp and getCurrentHours_OR_Month
*/
void dispWeather()
{
  int k, l; //placeholder and counter variables
  float average = 0; //used to hold the average of the temeperatures
  int todayTemp; //to hold today's temperature

  int tempRange [12][MAX_LENGTH]; //the temperature array
  int numberDays = 0; //to hold the number of days

  //prompting and reading in the today's temperature from the user
  cout << "Enter today's temperature: "; cin >> todayTemp;

  setTemp(tempRange, numberDays); //calls setTemp to generate a random 2d array of the temperatures for each month

  //computing average of selected month

  k = getCurrentHours_OR_Month(0); //to hold the current month

  //summing the individual elements in the array for the appropriate current month
  for (l = 0; l < numberDays; l++)
  {
    average += tempRange[k-1][l]; 
  }
  average /= numberDays; //dividing the sum by the number of days to get the average

  //displaying the avergae to the user
  cout << "Random " << numberDays << " days average: " << average << endl;

  //printing out the relationship of today's temperature to the average temperature of the current month
  if (todayTemp < average - 5) 
  {
    cout << "Today is colder than usual." << endl;
  }
  else if (todayTemp > average + 5)
  {
    cout << "Today is hotter than usual." << endl;
  }
  else
  {
    cout << "The temperature is normal." << endl;
  }
}

/* Function:    dispGreeting
   Parameters:  a string representing the user's full name
   Return:      none
   Description: This function greets the user with the time of the day based on the getCurrentHours_OR_Month function and fixName function.
*/
void dispGreeting(string fullName) 
{
  // declaring variables
  string timeOfDay; // stores the time of day
  
  // assigning the current hour from calling the function getCurrentHours_OR_Month to time_int variable
  int time_int = getCurrentHours_OR_Month(1);

  // determining which greeting to display based on time of day
  if ((time_int >= 0) && (time_int <= 11)) // between 12 am and 11:59 am
  {  
    timeOfDay = "Morning";
  } 
  else if ((time_int >= 12) && (time_int <= 17)) // between 12 pm and 5:59 pm
  {
    timeOfDay = "Afternoon";
  } 
  else if ((time_int >= 18) && (time_int <= 23)) // between 6 pm and 11:59 pm
  { 
    timeOfDay = "Evening";
  }

  // displaying the time of day and greeting
  cout << "Good " << timeOfDay << ", ";
  fixName(fullName); // calling fixName function for proper name
  cout << ". I hope you're having a nice day!" << endl;

}

/*
Function: playGame
Parameters: none
Return: none
Description: This function leads the user through a guessing game
*/
void playGame() 
{

  int my_num = (rand()%20)+1; //declaring and initializing the number that is to be guessed
  bool correct = false; //boolean that will be used later to decide whether or not to print the statement displaying the correct number
  int guess; //user's guess
  int guesses[5]; //array to store the user's guess
  guesses[0] = 0; //initializing the first value of the array to 0 so that it can be used later in the program
  bool repeat; //boolean that initializes to true if the user repeated a number

  //displaying directions to the game
  cout << "You have 5 chances to guess my number from 1 to 20!" << endl;

  for (int i = 1; i <= 5; ++i) //loops through the array of guesses
  {
    repeat = false; //to avoid errors later on

   //prompting for and reading in the user's guess
    cout << "Guess #" << i <<": "; cin>>guess;

    //checking if the guess is out of bounds
    if (guess > 20 || guess < 1)
    {
      cout <<"You are guessing out of range. You lose a chance." << endl;
      guesses[i-1] = 0; //initialzing a placeholder value in the array for the user's lost guess
    }
    else //the guess is in bounds
    {
      //checking for repeats
      for (int j = 1; j <i; j++) //loops through the most current array
      {
        if (guess == guesses[j-1]) //checks if there is a repeat
        {
         repeat = true;

        }
      }

      if (repeat)
      {
        cout << "You already made that guess. Try again" << endl;
        i--; //decrements the i value so that one of the guesses isn't used up and the user is able to try again
      }
      else if (guess > my_num) //if the guess is too big
      {
        cout << "Your guess ("<<guess<<") is too high! Guess a lower number" << endl;
        guesses[i-1] = guess; //initializes one of the elements in array guesses to the user's guess

      }
      else if (guess < my_num) 
      {
       cout << "You guess (" <<guess<<") is too low! Guess a higher number" << endl;
       guesses[i-1] = guess; //initializes one of the elements in array guesses to the user's guess
      }
      else
      {
        cout << "Correct in "<< i <<" guesses! Nice job!!" << endl;
        correct = true; //so that the sorry statement won't have to print
        break; //breaking out of the loop since the correct value had been guessed
      }
   }
  }

  if (!correct) //if the user did not choose the correct number out of their 5 attempts, the computer will display the correct number
  {
    cout << "Sorry, my number was " << my_num <<" !" << endl;
  }

}
