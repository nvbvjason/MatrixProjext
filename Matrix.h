#pragma once
#include "std_lib_facilities.h"

class Matrix {
private:
	vector<vector<double>> M;

public:
	Matrix(int size, char Matrix_name);
	Matrix(vector<vector<double>> MM);

	vector<vector<double>> Matrix_back() const { return M; }
	void Gauss();
	void Invers();
	void transpose();
	Matrix operator+(Matrix const& other);
	Matrix operator-(Matrix const& other);
	Matrix operator*(Matrix const& other);
};

ostream& operator<<(ostream& os, const Matrix MM);
