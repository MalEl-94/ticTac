#include <stdio.h>
#include <conio.h>
//AHAD MALIK
//ALGO+DS COURSEWORK

char cell[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

char gameArray[10][10];

int MAXSIZE = 9;
int top = -1;
int undoStack[10];
int gameCounter = 0;

//declaration of functions
int status ();
void board ();
int game ();
int menu();
int validEntry (int choice);
void undo ();
void replay ();
int push (int choice);
int pop ();
int peek ();
int isEmpty ();
int isFull ();

//main
int
main ()
{
    menu();
}

int menu()
{

 int option;

  printf ("\n\nWelcome to Tic Tac Toe\n\n");
  printf ("Play a game : Enter 1\n");
  printf ("Replay a game : Enter 2\n");
  printf ("Exit : Enter 3\n");

  scanf ("%d", &option);

  switch (option)
    {
    case 1:
      game ();
      break;

    case 2:
      replay ();
      break;


    case 3:
      return 0;
      break;


    default:
      printf ("Error! Please enter a valid option");
     }

}


int game ()
{

  int player = 1, i, choice;
  char mark;

  //do-while loop runs till a game ends with a player winning or a draw
  do
    {
      board ();
      player = (player % 2) ? 1 : 2;

      printf ("Player %d, enter a number:  ", player);
      scanf ("%d", &choice);

      // check if input is correct
      if (validEntry (choice))
	{

	  mark = (player == 1) ? 'X' : 'O';

	  if (choice == 1 && cell[1] == '1')
	    {
	      cell[1] = mark;
	      push (choice);
	    }
	  else if (choice == 2 && cell[2] == '2')
	    {
	      cell[2] = mark;
	      push (choice);
	    }
	  else if (choice == 3 && cell[3] == '3')
	    {
	      cell[3] = mark;
	      push (choice);
	    }
	  else if (choice == 4 && cell[4] == '4')
	    {
	      cell[4] = mark;
	      push (choice);
	    }
	  else if (choice == 5 && cell[5] == '5')
	    {
	      cell[5] = mark;
	      push (choice);
	    }
	  else if (choice == 6 && cell[6] == '6')
	    {
	      cell[6] = mark;
	      push (choice);
	    }
	  else if (choice == 7 && cell[7] == '7')
	    {
	      cell[7] = mark;
	      push (choice);
	    }
	  else if (choice == 8 && cell[8] == '8')
	    {
	      cell[8] = mark;
	      push (choice);
	    }
	  else if (choice == 9 && cell[9] == '9')
	    {
	      cell[9] = mark;
	      push (choice);
	    }
	  else if (choice == 10)
	    {
	      undo ();
	    }
	  else
	    {
	      printf ("Invalid Move");
	      player--;
	      getch ();
	    }
	}
      else
	{
	  printf ("Invalid Entry!");
	}
      player++;


    }
  while (status () == -1);
  board();

  if (status () == 1)
    {
      printf ("==>\aPlayer %d win ", --player);
      gameCounter++;
    }
  else
    {
      printf ("==>\aGame draw");
      gameCounter++;

    }

  //iterates through undoStack and adds all played moves to a gameArray
  for (i = 0; i < 10; i++)
    {
      gameArray[gameCounter][i] = undoStack[i];
    }

  getch ();
  menu();

}


// function checks for valid entry
int
validEntry (int choice)
{
  if (choice > 0 && choice < 11)
    {
      return 1;
    }
  else
    {
      return 0;
    }

}


int
status ()
{
  //check for a winning combo
  //first row combo
  if (cell[1] == cell[2] && cell[2] == cell[3])
    return 1;
  //second row combo
  else if (cell[4] == cell[5] && cell[5] == cell[6])
    return 1;
  //third row combo
  else if (cell[7] == cell[8] && cell[8] == cell[9])
    return 1;
  //first column combo
  else if (cell[1] == cell[4] && cell[4] == cell[7])
    return 1;
  //second column combo
  else if (cell[2] == cell[5] && cell[5] == cell[8])
    return 1;
  //third column combo
  else if (cell[3] == cell[6] && cell[6] == cell[9])
    return 1;
  //diagonal L to R
  else if (cell[1] == cell[5] && cell[5] == cell[9])
    return 1;
  //diagonal R to L
  else if (cell[3] == cell[5] && cell[5] == cell[7])
    return 1;

  //check if game is a draw
  else if (cell[1] != '1' && cell[2] != '2' && cell[3] != '3' &&
	   cell[4] != '4' && cell[5] != '5' && cell[6] != '6' && cell[7]
	   != '7' && cell[8] != '8' && cell[9] != '9')

    return 0;
  else
    return -1;
}



//funtion clears user screen and draws board
void
board ()
{
  system ("cls");
  printf ("\n\n\tTic Tac Toe\n\n");

  printf ("Player 1 (X)  -  Player 2 (O)\n\n\n");
  printf ("\n\n\nRound %d\n\n\n", gameCounter);

  printf ("     |     |     \n");
  printf ("  %c  |  %c  |  %c \n", cell[1], cell[2], cell[3]);
  printf ("_____|_____|_____\n");
  printf ("     |     |     \n");

  printf ("  %c  |  %c  |  %c \n", cell[4], cell[5], cell[6]);

  printf ("_____|_____|_____\n");
  printf ("     |     |     \n");

  printf ("  %c  |  %c  |  %c \n", cell[7], cell[8], cell[9]);

  printf ("     |     |     \n\n");
    printf ("Enter 10 to undo a move\n\n\n");

}

//Replay function,
void
replay ()
{
  int entry;
  system ("cls");
  printf ("\n\nRe-playyyy!\n\n");
  printf ("Games available to Replay: %d\n", gameCounter);
  printf ("Choose which game to Replay");
  scanf ("%d", &entry);

  if (entry <= gameCounter)
    {
      int i;
      for (i = 0; i < 10; i++)
	{
	  cell[i] = gameArray[entry][i];
    board();
	}
    }
  else
    printf ("Please enter a valid option\n");

    menu();
}

//Undo function: Peeks top of undoStack when called and comapres cells to value, if a cell does not contain
//that value, it is updated. top of undoStack is then popped off.
void
undo ()
{

  int lastMove = pop ();

  if (lastMove == 1 && !(cell[1] == '1'))
    {
      cell[1] = '1';
    }
  else if (lastMove == 2 && !(cell[2] == '2'))
    {
      cell[2] = '2';
    }
  else if (lastMove == 3 && !(cell[3] == '3'))
    {
      cell[3] = '3';
    }
  else if (lastMove == 4 && !(cell[4] == '4'))
    {
      cell[4] = '4';
    }
  else if (lastMove == 5 && !(cell[5] == '5'))
    {
      cell[5] = '5';
    }
  else if (lastMove == 6 && !(cell[6] == '6'))
    {
      cell[6] = '6';
    }
  else if (lastMove == 7 && !(cell[7] == '7'))
    {
      cell[7] = '7';
    }
  else if (lastMove == 8 && !(cell[8] == '8'))
    {
      cell[8] = '8';
    }
  else if (lastMove == 9 && !(cell[7] == '9'))
    {
      cell[9] = '9';
    }
  else
    printf ("Cannot Undo");

}

int
isEmpty ()
{

  if (top == -1)
    return 1;
  else
    return 0;
}

int
isFull ()
{

  if (top == MAXSIZE)
    return 1;
  else
    return 0;
}

int
peek ()
{
  return undoStack[top];
}

int
pop ()
{
  int data;

  if (!isEmpty ())
    {
      data = undoStack[top];
      top = top - 1;
      return data;
    }
  else
    {
      printf ("Could not retrieve data, Stack is empty.\n");
    }
}

int
push (int choice)
{

  if (!isFull ())
    {
      top = top + 1;
      undoStack[top] = choice;
    }
  else
    {
      printf ("Could not insert data, Stack is full.\n");
    }
}
