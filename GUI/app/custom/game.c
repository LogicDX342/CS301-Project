#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "custom.h"

int board[SIZE][SIZE];
lv_obj_t *board_label[16];
int score = 0;
char num_str[10];

void printBoard()
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
      printf("%4d", board[i][j]);
    printf("\n");
  }
}

void show_board()
{
  int num;
  for (int i = 0; i < 16; i++)
  {
    num = board[i / 4][i % 4];
    if (num != 0)
    {
      sprintf(num_str, "%d", num);
      lv_label_set_text(board_label[i], num_str);
    }
    else
      lv_label_set_text(board_label[i], "");
  }
  sprintf(num_str, "%d", score);
  lv_label_set_text(guider_ui.game_2048_score, num_str);
  lv_label_set_text(guider_ui.game_2048_label_end, "");
}

void addRandom()
{
  int n = 0;
  int emptyCells[SIZE * SIZE][2];
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (board[i][j] == 0)
      {
        emptyCells[n][0] = i;
        emptyCells[n][1] = j;
        n++;
      }
    }
  }
  if (n == 0)
    return;
  int r = rand() % n;
  int row = emptyCells[r][0];
  int col = emptyCells[r][1];
  board[row][col] = (rand() % 2 + 1) * 2;
}

bool checkGameOver()
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (board[i][j] == 0)
      {
        return false;
      }
      if (i < SIZE - 1 && board[i][j] == board[i + 1][j])
      {
        return false;
      }
      if (j < SIZE - 1 && board[i][j] == board[i][j + 1])
      {
        return false;
      }
    }
  }
  return true;
}

void update()
{
  if (score < findMax())
    score = findMax();
  if (!checkGameOver())
  {
    addRandom();
    if (checkGameOver())
    {
      show_board();
      lv_label_set_text(guider_ui.game_2048_label_end, "Game Over");
    }
    show_board();
  }
  else
  {
    show_board();
    lv_label_set_text(guider_ui.game_2048_label_end, "Game Over");
  }
}

void moveLeft()
{
  int i, j, k;
  for (i = 0; i < SIZE; i++)
  {
    for (j = 0; j < SIZE; j++)
    {
      if (board[i][j] != 0)
      {
        for (k = j + 1; k < SIZE; k++)
        {
          if (board[i][k] != 0)
          {
            if (board[i][j] == board[i][k])
            {
              board[i][j] *= 2;
              board[i][k] = 0;
            }
            break;
          }
        }
      }
    }
  }

  for (i = 0; i < SIZE; i++)
  {
    int t = 0;
    for (j = 0; j < SIZE; j++)
    {
      if (board[i][j] != 0)
      {
        if (j != t)
        {
          board[i][t] = board[i][j];
          board[i][j] = 0;
        }
        t++;
      }
    }
  }
  update();
}

void moveRight()
{
  int i, j, k;
  for (i = 0; i < SIZE; i++)
  {
    for (j = SIZE - 1; j >= 0; j--)
    {
      if (board[i][j] != 0)
      {
        for (k = j - 1; k >= 0; k--)
        {
          if (board[i][k] != 0)
          {
            if (board[i][j] == board[i][k])
            {
              board[i][j] *= 2;
              board[i][k] = 0;
            }
            break;
          }
        }
      }
    }
  }

  for (i = 0; i < SIZE; i++)
  {
    int t = SIZE - 1;
    for (j = SIZE - 1; j >= 0; j--)
    {
      if (board[i][j] != 0)
      {
        if (j != t)
        {
          board[i][t] = board[i][j];
          board[i][j] = 0;
        }
        t--;
      }
    }
  }
  update();
}

void moveUp()
{
  int i, j, k;
  for (j = 0; j < SIZE; j++)
  {
    for (i = 0; i < SIZE; i++)
    {
      if (board[i][j] != 0)
      {
        for (k = i + 1; k < SIZE; k++)
        {
          if (board[k][j] != 0)
          {
            if (board[i][j] == board[k][j])
            {
              board[i][j] *= 2;
              board[k][j] = 0;
            }
            break;
          }
        }
      }
    }
  }

  for (j = 0; j < SIZE; j++)
  {
    int t = 0;
    for (i = 0; i < SIZE; i++)
    {
      if (board[i][j] != 0)
      {
        if (i != t)
        {
          board[t][j] = board[i][j];
          board[i][j] = 0;
        }
        t++;
      }
    }
  }
  update();
}

void moveDown()
{
  int i, j, k;
  for (j = 0; j < SIZE; j++)
  {
    for (i = SIZE - 1; i >= 0; i--)
    {
      if (board[i][j] != 0)
      {
        for (k = i - 1; k >= 0; k--)
        {
          if (board[k][j] != 0)
          {
            if (board[i][j] == board[k][j])
            {
              board[i][j] *= 2;
              board[k][j] = 0;
            }
            break;
          }
        }
      }
    }
  }

  for (j = 0; j < SIZE; j++)
  {
    int t = SIZE - 1;
    for (i = SIZE - 1; i >= 0; i--)
    {
      if (board[i][j] != 0)
      {
        if (i != t)
        {
          board[t][j] = board[i][j];
          board[i][j] = 0;
        }
        t--;
      }
    }
  }
  update();
}

int findMax()
{
  int max = 0;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (board[i][j] > max)
      {
        max = board[i][j];
      }
    }
  }
  return max;
}

void game_init()
{
  board_label[0] = guider_ui.game_2048_b_0_label;
  board_label[1] = guider_ui.game_2048_b_1_label;
  board_label[2] = guider_ui.game_2048_b_2_label;
  board_label[3] = guider_ui.game_2048_b_3_label;
  board_label[4] = guider_ui.game_2048_b_4_label;
  board_label[5] = guider_ui.game_2048_b_5_label;
  board_label[6] = guider_ui.game_2048_b_6_label;
  board_label[7] = guider_ui.game_2048_b_7_label;
  board_label[8] = guider_ui.game_2048_b_8_label;
  board_label[9] = guider_ui.game_2048_b_9_label;
  board_label[10] = guider_ui.game_2048_b_10_label;
  board_label[11] = guider_ui.game_2048_b_11_label;
  board_label[12] = guider_ui.game_2048_b_12_label;
  board_label[13] = guider_ui.game_2048_b_13_label;
  board_label[14] = guider_ui.game_2048_b_14_label;
  board_label[15] = guider_ui.game_2048_b_15_label;
  memset(board, 0, sizeof(board));
  score = 0;
  addRandom();
  if (score < findMax())
    score = findMax();
  show_board();
}
