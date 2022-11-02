#include "Matrix.h"
#include <sstream>
#include <algorithm>

Matrix::Matrix(int rows) {
	matrix = new int* [rows];
	this->rows = rows;
	this->cols = rows;
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(int** matrix,int rows)
{
	this->matrix = matrix;
	this->rows = rows;
	this->cols = rows;
}

Matrix::Matrix(Matrix& m)
{
	this->rows = m.getRows();
	this->cols = m.getCols();
	matrix=new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
}

int Matrix::getRows()
{
	return rows;
}

int Matrix::getCols()
{
	return cols;
}

double Matrix::matrixNorm()
{
	double result=0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			result += matrix[i][j] * matrix[i][j];
		}
	}
	return sqrt(result);
}

int* Matrix::operator[](int row)
{
	return matrix[row];
}

Matrix& Matrix::operator=(Matrix& m)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	this->rows = m.getRows();
	this->cols = m.getCols();
	matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
	return *this;
}



Matrix::operator string()
{

	stringstream stream;

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			stream << this->matrix[i][j] << '\t';
		}
		stream << '\n';
	}
	return stream.str();


}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

Matrix& operator+(Matrix& m1, Matrix& m2)
{
	Matrix* a = new Matrix(m1.rows);
	for (int i = 0; i < m1.rows; i++)
	{
		for (int j = 0; j < m1.cols; j++)
		{
			a->matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
		}
		
	}
	return *a;

}

bool operator==(Matrix& m1, Matrix& m2)
{
	if (m1.rows != m2.rows) return false;
	for (int i = 0; i < m1.rows; i++)
	{
		for (int j = 0; j < m1.cols; j++)
		{
			if (m1.matrix[i][j] != m2.matrix[i][j]) return false;
		}
	}
	return true;
}

ostream& operator<<(ostream& out, Matrix& m)
{
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++) {
			out << m.matrix[i][j] << "\t";
		}
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Matrix& m)
{
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++) {
			printf("data[%i][%i] : ", i, j); in >> m.matrix[i][j];
		}
	}
	return in;

}
