#include "HW4.h" //our own header file

int main() {
// //
   // seeding random
  srand(time(NULL));

  int numAnts; //number of ants in anthony's colony
  int numCap = 0; //counting the added number of ants each time he gets a queen
  int row[3]; //saves the user's input for rows in a 1D static array so that we can check if the user already inputted a row value
  bool repeat = false; //used if the user repeated a guess
  bool lose = false; //used if the user lost
  char letter; //to hold the letter of the column that the user is currently on
  //generating a dynamic integer 3x10 array
  int **antCol; 
  antCol = new int *[3];
  for (int i = 0; i < 3 ;++i)
	{
		antCol[i]=new int[COL]; //use number of columns to allocate memory to each row
	}
  
  //generating a dynamic string 3x10 array
  string **display;
  display = new string *[3];
  for (int i = 0; i < 3 ;++i)
	{
		display[i]=new string[COL]; //use number of columns to allocate memory to each row
	}
  
  // calling function to display student info
  studentInfo();

  

  initArr(antCol); // calling the function initArr to get values for the antCol initial matrix

  //for debugging purposes only
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      cout << antCol[i][j] << " ";
    }
    cout << endl;
  }


  numAnts = rand()%10 + 15; // random number of ants for arny is 15-25

  //initializing the display array which should be full of "--" initially
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      display[i][j] = "--";
    }
  }
  
  //printing out the introductory statement
  cout << "Let's begin! Anthony's army is " << numAnts << " strong!" << endl;
  
 
  for (int i = 0; i < COL; i++) //looping through all the columns
  {
    
    if (lose) //if he lost, then break out of the entire for loop
    {      
      break;
    }

    for (int j = 0; j < 3; j++) //looping through each row
    {
      if (numAnts < 1) // to check if ants is negative
      { 
        lose = true; //sets the lose boolean to true
        break; //breaks out of the inner loop
      }
    
      repeat = false; //resets the repeat boolean to false
      dispArray(display); //calls the display array function

    letter = 'A' + i; // the corresponding letter to each column
    cout << "Enter row position in column " << letter << " to strike: "; //prompting the user to enter a row to strike
      cin >> row[j]; //reading in the user's input in a 1D array 
      for (int p = 0; p < j; p++) //loops through the 1D array of rows
      {
        if (row[j] == row[p]) //checks if there is a repeat
        {

          cout << "You already made that guess. Try again" << endl;
          --j; //decrements the counter so that the user has another try

          repeat = true; //sets the boolean repeat to try
       
        }
      }
      if (repeat) //if the user entered a repeat
      {
      continue; //skip the rest of the code for this loop and continue
      }
      if (row[j] > 2 || row[j] < 0) //if the user entered an invalid number for row then display a message informing them that the row they entered was invalid
      {
        cout << "Invalid row (" << row[j] << ") entered. Try again..." << endl;
      }
      else //if the user entered a valid row number
      {
        if (antCol[row[j]][i] == 'Q') //if the row that the user chose was the locatino of a queen
        {
          numCap = 0; //reset the counter variable for the sum of additional colonies to 0
          display[row[j]][i] = " A"; //change the string at the location that was previously "--" to " A" to indicate that Anthony captrued the queen
          for (int k = 0; k < 3; k++) //loops through all the rows of the given column
          {
            if ((k != row[j]) && (display[k][i]!=" X")) //checks if the value of k is not equal to the row that the queen is in, and if the row has not already been checked earlier and it has already been lost
            {
              numAnts += antCol[k][i]; //adds the number of ant colonies in rows that haven't already been guessed to Anthony's ant colony
              numCap  += antCol[k][i]; //adds the number of ant colonies to a counter variable so that the additional number of ant colonies can be displayed
              display[k][i] = " *"; //replaces the "--" with an " *" to indicate that Anthony has won those colonies
            }
          }
          cout << "Queen found! Anthony's army captured " << numCap << " and is now " << numAnts << " strong!" << endl; //prints out a congraulatory statement
          break; //breaks out of the inner loop and proceeds to the next column
        }
        else  //if the user did not guess the row with the queen in it
        {
          display[row[j]][i] = " X"; //replace the "--" with an " X" to tell the user that they did not win that row, and the Queen was not there
          numAnts -= antCol[row[j]][i]; //subtract the number of colonies that were in that row from the user's total number of colonies
          cout << "Anthony's army has lost " << antCol[row[j]][i] << " and now he has " << numAnts << " ants remaining!" << endl; //prints out an informative statement that indicates the user has lost colonies since they did not find the queen
        }
      }
    }
  }
  
  dispArray(display); //calls the dispArray function to display the array again after the game is over

  if (lose) //if anthony's army lost
  {
    cout << "Sorry, but Anthony's army has been defeated!" << endl; //prints out an informative statement
    loss(display, antCol); //calls the loss function to display the final array with the remaining correct hidden answers
  }
  else
  {
      cout << "Congratulations! Anthony the Ant is victorious with an army of " << numAnts << " remaining!" << endl; //prints out a congraulatory statement
  }
 
  for (int i = 0; i < 3 ;++i)
	{
		delete [] antCol[i]; //delete memory of each row
	}
	
	delete [] antCol; //delete the overall array

  for (int i = 0; i < 3 ;++i)
	{
		delete [] display[i]; //delete memory of each row
	}
	
	delete [] display; //delete the overall array
  
  return 0;
}
