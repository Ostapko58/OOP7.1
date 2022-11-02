#pragma once
#include<iostream>
#include<string>
using namespace std;
class Matrix
{
private:
	int** matrix;
	int rows;
	int cols;
public:

	Matrix(int);
	Matrix(int**,int );
	Matrix(Matrix&);


	int getRows();
	int getCols();
	double matrixNorm();

	int* operator[] (int);
	Matrix& operator =(Matrix&);
	friend Matrix& operator + (Matrix&, Matrix&);
	friend bool operator ==(Matrix&, Matrix&);
	friend ostream& operator << (ostream&, Matrix&);
	friend istream& operator >> (istream&, Matrix&);
	operator string();

	~Matrix();


};

