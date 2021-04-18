#include "HW4.h"

// function definitions not including main
//
/*  Function: studentInfo
    Parameters: none
    Return: none
    Description: This function displays the information of the students who made the program.
*/
void studentInfo(){
  // intro
  cout << "+----------------------------------------------+" << endl;
  cout << "|        Computer Science and Engineering      |" << endl;
  cout << "|       CSCE 1030.002 - Computer Science I     |" << endl;
  cout << "|   Jennifer Ai jla0325 JenniferAi@my.unt.edu  |" << endl;
  cout << "|   Cindy Liang cl0822 CindyLiang@my.unt.edu   |" << endl;
  cout << "|      Lisa Lin ll0484 LisaLin@my.unt.edu      |" << endl;
  cout << "+----------------------------------------------+" << endl; 
}

/*  Function: initArr
    Parameters: an integer dynamic 2D array antCol representing the locations for the hidden ant colony.
    Return: none
    Description: This function initializes the ant colony array by deciding where the queen will be and how many ants will be guarding the queen.
*/
void initArr(int **antCol)
{
  // for each column
  for (int i = 0; i < COL; i++)
  {
    int num = rand()%3; // generating random row to place queen in
    for (int j = 0; j < 3; j++) // loop through each row
    {
      
      if(num==j) // comparing the random num and row
      {
      antCol[num][i] = 'Q'; // represents queen
      }
      else
      {
        antCol[j][i] = (rand()%10)+1; // guarding ants will be from 1-10
      }
      
    }
  }

}

/*  Function: dispArray
    Parameters: a string dynamic 2D array display representing the locations for the shown ant colony.
    Return: none
    Description: This function displays the initial 2D matrix to the user and the final array before the user either wins or loses.
*/
void dispArray(string **display)
{
  // the top of the game matrix to represent each column
  cout << "     A  B  C  D  E  F  G  H  I  J  " << endl; //36 6 ' ' 2 ' ' in between letters
      cout << "  +-------------------------------+" << endl; //31 '-' 2 '+' 2 ' '
  
      // looping through each row
      for (int m = 0; m < 3; m++)
      {
        cout << m << " |"; // adding the row number from 0-2 and a post |
        for (int n = 0; n < COL; n++) // looping through each coloumn
        {
          cout << right << setw(3) << display[m][n]; // using io manipulators to format the 
        }
        cout << " |" << endl;
      }

    cout << "  +-------------------------------+" << endl;
}

/*  Function: loss
    Parameters: an string dynamic 2D array display representing the locations for the shown ant colony.
                an integer dynamic 2D array antCol representing the locations for the hidden ant colony.
    Return: none  
    Description: This is called when the user loses and displays the values that were already played as well as the values that have not been played yet.
*/
void loss(string **display, int **antCol)
{
  // the top of the game matrix to represent each column
  cout << "     A  B  C  D  E  F  G  H  I  J  " << endl;
  cout << "  +-------------------------------+" << endl;
  
  // looping through each row
  for (int m = 0; m < 3; m++)
    {
      cout << m << " |"; // adding the row number 0-2 and the post |
      for (int n = 0; n < COL; n++) // looping through each column
      {
        if (display[m][n] != "--") // finding values that have been played
        {
          cout << right << setw(3) << display[m][n]; // displaying the values that were already played
        }
        else
        {
          if (antCol[m][n] == 'Q') // finding locations that had the queen in the initial array 
          {
            cout << right << setw(3) << 'Q'; // displaying them as the queen
          }
          else
          {
          cout << right << setw(3) << antCol[m][n]; // displaying the rest as the guarding ant values
          }
        }
        
      }
      cout << " |" << endl; // displaying the right post
     
    }
   
  cout << "  +-------------------------------+" << endl;

}
