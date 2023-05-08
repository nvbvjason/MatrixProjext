#include "Matrix.h"

Matrix::Matrix(vector<vector<double>> MM)
{
	for (int i = 0; i < MM.size(); i++) {
		if (MM.size() != MM[i].size()) { error("non quadratic Matrix"); }
	}
	M = MM;
}

Matrix::Matrix(int size, char Matrix_name)
{
	if (size <= 0) { error("Matrix must atleast be size 1"); }
	vector<vector<double>> MM;
	vector<double> VV;
	double temp = 0;
	for (int row = 0; row < size; row++) {
		MM.push_back(VV);
		for (int column = 0; column < size; column++) {
			cout << Matrix_name << '[' << row + 1 << "][" << column + 1 << "]: ";
			cin >> temp;
			MM[row].push_back(temp);
		}
	}
	M = MM;
}

Matrix Matrix::operator+(Matrix const& other)
{
	if (M.size() != other.M.size()) { error("size of Matrix different +"); }
	vector<vector<double>> MM;
	vector<double> VV;
	for (int i = 0; i < other.M.size(); i++) {
		MM.push_back(VV);
		for (int j = 0; j < other.M.size(); j++) {
			MM[i].push_back(0);
		}
	}

	for (int row = 0; row < M.size(); row++) {
		double temp = 0;
		for (int column = 0; column < M.size(); column++) {
			MM[row][column] = M[row][column] + other.Matrix_back()[row][column];
		}
	}

	Matrix back{ MM };
	return back;
}

Matrix Matrix::operator-(Matrix const& other)
{
	if (M.size() != other.M.size()) { error("size of Matrix different +"); }
	vector<vector<double>> MM;
	vector<double> VV;
	for (int i = 0; i < other.M.size(); i++) {
		MM.push_back(VV);
		for (int j = 0; j < other.M.size(); j++) {
			MM[i].push_back(0);
		}
	}

	for (int row = 0; row < M.size(); row++) {
		double temp = 0;
		for (int column = 0; column < M.size(); column++) {
			MM[row][column] = M[row][column] - other.Matrix_back()[row][column];
		}
	}

	Matrix back{ MM };
	return back;
}

Matrix Matrix::operator*(Matrix const& other)
{
	if (M.size() != other.M.size()) { error("size of Matrix different *"); }
	vector<vector<double>> MM;
	vector<double> VV;
	for (int i = 0; i < other.M.size(); i++) {
		MM.push_back(VV);
		for (int j = 0; j < other.M.size(); j++) {
			MM[i].push_back(0);
		}
	}

	for (int i = 0; i < M.size(); i++) {
		for (int j = 0; j < M.size(); j++) {
			double temp = 0;
			for (int k = 0; k < M.size(); k++) {
				if (k != (M.size() - 1)) {
				}
				temp += M[i][k] * other.Matrix_back()[k][j];
			}
			MM[i][j] = temp;
			temp = 0;
		}
	}
	Matrix back{ MM };
	return back;
}

ostream& operator<<(ostream& os, const Matrix MM)
{
	cout.width(8);
	for (vector<double> vd : MM.Matrix_back()) {
		for (double dd : vd) {
			os << fixed << dd << '\t';
		}
		os << '\n';
	}
	os << '\n';
	return os;
}

void Matrix::Gauss()
{
	int Size = M.size();
	if (Size == 0) { error("Gauss of empty matrix"); }

	for (int k = 0; k < M.size(); k++) {

		// count how many 0 start each row
		vector<vector<int>> to_sort;
		vector<int> temp_vi;
		for (int i = k; i < Size; i++) {
			int counter = 0;
			for (int j = 0; j < Size; j++) {
				if (M[i][j] == 0) {
					counter++;
				}
				else { break; }
			}
			temp_vi.push_back(i);
			temp_vi.push_back(counter);
			to_sort.push_back(temp_vi);
			temp_vi.clear();
		}

		// swap
		for (int i = k; i < to_sort.size(); i++) {
			bool swap = false;
			int temp_int = to_sort[i][1];
			int row_index_to_swap = 0;
			vector<double> to_swap;
			for (int j = i; j < to_sort.size(); j++) {
				if (to_sort[j][1] < temp_int) {
					cout << "here";
					to_swap = M[j];
					swap = true;
					temp_int = to_sort[j][1];
					row_index_to_swap = j;
				}
			}
			if (swap) {
				M[i].swap(M[row_index_to_swap]);
				to_sort[i].swap(to_sort[row_index_to_swap]);
			}
			to_swap.clear();
		}
		to_sort.clear();


		// elimination
		for (int i = k; i < Size; i++) {
			if (M[k][i] != 0) {
				for (int j = i + 1; j < Size; j++) {
					double temp = M[j][i] / M[k][i];
					for (int l = k; l < Size; l++) {
						M[j][l] -= M[k][l] * temp;
					}
				}
				break; // stop after one columm
			}
		}
	}
	return;
}

void Matrix::Invers()
{
	int Size = M.size();
	if (Size == 0) { error("Gauss of empty matrix"); }
	vector<vector<double>> MM;
	vector<double> VV;
	for (int i = 0; i < Size; i++) {
		MM.push_back(VV);
		for (int j = 0; j < Size; j++) {
			if (j == i) { MM[i].push_back(1); }
			else { MM[i].push_back(0); }
		}
	}

	for (int k = 0; k < Size; k++) {

		// count how many 0 start each row
		vector<vector<int>> to_sort;
		vector<int> temp_vi;
		for (int i = k; i < Size; i++) {
			int counter = 0;
			for (int j = 0; j < Size; j++) {
				if (M[i][j] == 0) {
					counter++;
				}
				else { break; }
			}
			temp_vi.push_back(i);
			temp_vi.push_back(counter);
			to_sort.push_back(temp_vi);
			temp_vi.clear();
		}

		double pivo = M[k][k];
		for (int j = 0; j < Size; j++) {
			M[k][j] /= pivo;
			MM[k][j] /= pivo;
		}

		// swap
		for (int i = k; i < to_sort.size(); i++) {
			bool swap = false;
			int temp_int = to_sort[i][1];
			int row_index_to_swap = 0;
			vector<double> to_swap;
			for (int j = i; j < to_sort.size(); j++) {
				if (to_sort[j][1] < temp_int) {
					to_swap = M[j];
					swap = true;
					temp_int = to_sort[j][1];
					row_index_to_swap = j;
				}
			}
			if (swap) {
				M[i].swap(M[row_index_to_swap]);
				to_sort[i].swap(to_sort[row_index_to_swap]);
				MM[i].swap(MM[row_index_to_swap]);
			}
			to_swap.clear();
		}
		to_sort.clear();

		// elimination
		for (int i = k; i < Size - 1; i++) {
			double temp = M[i + 1][k];
			for (int j = 0; j < Size; j++) {
				M[i + 1][j] += M[k][j] * -temp;
				MM[i + 1][j] += MM[k][j] * -temp;
			}
		}
	}

	if (M[Size - 1][Size - 1] == 0) { error("Matrix rank too small to invert"); }

	// set rest upper to zero
	for (int i = Size - 1; i >= 1; i--) {
		for (int j = i - 1; j >= 0; j--) { // columm
			double temp2 = M[j][i];
			for (int k = 0; k < Size; k++) {
				M[j][k] -= M[i][k] * temp2;
				MM[j][k] -= MM[i][k] * temp2;
			}
		}
	}
	M = MM;
	return;
}

void Matrix::transpose()
{
	if (M.size() == 1)return;
	for (int i = 0; i < M.size(); i++) {
		for (int j = i + 1; j < M.size(); j++) {
			double temp = M[i][j];
			M[i][j] = M[j][i];
			M[j][i] = temp;
		}
	}
}
