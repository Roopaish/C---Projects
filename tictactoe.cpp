#include <iostream>
 
#include <cmath>

using namespace std;

int i, j;
// Board to draw
void Canvas(char board[3][3]) {
  cout << endl << endl << "---Board---" << endl << endl;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (j == 1 || j == 2) {
        cout << char(179);
      }
      cout << " " << board[i][j] << " ";
    }
    cout << endl;
    for (int k = 0; k < 3 * 3 + 2; k++) {
      cout << char(196);
    }
    cout << endl;
  }
}

bool isWinnerFound(char board[3][3], int index, char icon[2]) {
  int count = 0;
  // checking the row
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[i][j] == icon[index]) {
        count++;
        if (count == 3)
          return true;
      }
    }
    count = 0;
  }

  // checking the column
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[j][i] == icon[index]) {
        count++;
        if (count == 3)
          return true;
      }
    }
    count = 0;
  }

  // checking diagonal 1
  count = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (i == j) {
        if (board[i][j] == icon[index]) {
          count++;
          if (count == 3)
            return true;
        }
      }
    }
  }

  // checking diagonal 2
  count = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (i + j == 2) {
        if (board[i][j] == icon[index]) {
          count++;
          if (count == 3)
            return true;
        }
      }
    }
  }

  // checking tie
  count = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[i][j] != ' ') {
        count++;
        if (count == 9) {
          cout << endl << endl << ">>>>It's a tie!";
          exit(0);
        };
      }
    }
  }

  return false;
}

int main() {
  int index = 0, flag = 0;
  int choice;
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  cout << ">>>>>>>>>>>>>>>>>>>>>>>TICTACTOE<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
       << endl;

  string player[2] = {"X-Player", "O-Player"};
  char icon[2] = {'X', 'O'};
  Canvas(board);

  while (1) {
    // Getting user input
    cout << endl
         << endl
         << player[index] << " turn." << endl
         << "Select from 1 - 9 position (0 to exit) : ";
    cin >> choice;

    if (choice == 0)
      exit(0);
    if (!(choice >= 0 && choice <= 9)) {
      cout << endl << "Wrong input! Try again!" << endl;
      continue;
    }

    // Check and place X or O in defined position
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        if (i == 0 ? choice == i + j + 1 : choice == i + j + pow(2, i) + 1) {
          board[i][j] == ' ' ? board[i][j] = icon[index] : flag = 1;
        }
      }
    }

    // Continue loop if position is already filled
    if (flag) {
      cout << endl << "Position " << choice << " is already filled!";
      flag = 0;
      continue;
    }

    Canvas(board);
    // checking if the game is over
    if (isWinnerFound(board, index, icon)) {
      cout << endl << endl << ">>>Congrats! " << player[index] << " Won!";
      exit(0);
    }

    // Updating the values
    index++;
    index = index > 1 ? 0 : 1;
  }
}