#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
  int row, col;
  double** A, ** B, ** C;
  cin >> row;
  cin >> col;

  // Ввод элементов первой матрицы
  A = new double* [row];
  for (int i = 0; i < row; i++)
  {
    A[i] = new double[col];
    for (int j = 0; j < col; j++)
    {
      //cout << "A[" << i << "][" << j << "]= ";
      //cin >> A[i][j];
      A[i][j] = rand() / 100000000;
    }
  }

  // Вывод элементов первой матрицы
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << "A[" << i << "][" << j << "]= ";
      cout << A[i][j] << " ";
    }  
    cout << endl;
  }

  // Ввод элементов второй матрицы
  B = new double* [row];
  for (int i = 0; i < row; i++)
  {
    B[i] = new double[col];
    for (int j = 0; j < col; j++)
    {
      //cout << "B[" << i << "][" << j << "]= ";
      //cin >> B[i][j];
      B[i][j] = rand() / 100000000;
    }
  }

  // Вывод элементов второй матрицы
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << "B[" << i << "][" << j << "]= ";
      cout << B[i][j] << " ";
    }
    cout << endl;
  }

  // Умножение матриц
  C = new double* [row];
  for (int i = 0; i < row; i++)
  {
    C[i] = new double[col];
    for (int j = 0; j < col; j++)
    {
      C[i][j] = 0;
      for (int k = 0; k < col; k++)
        C[i][j] += A[i][k] * B[k][j];
    }
  }

  // Вывод произведения матриц
  cout << "Ответ" << endl;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
      cout << C[i][j] << " ";
    cout << endl;
  }
  cin.get(); cin.get();
  return 0;
}
