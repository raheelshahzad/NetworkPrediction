#include "Matrix.h"

#include <math.h>
#include <string.h>

void Matrix::resize(int n, int m) {
	if (m_ != m || n_ != n) {
		for (int i = 0; i < n_; i++) {
			delete []matrix_[i];
		}
	}
	if (n_ != n) {
		delete []matrix_;
		n_ = n;
		m_ = 0;
		matrix_ = new ValueType *[n_];
	}

	if (m_ != m) {
		m_ = m;
		for (int i = 0; i < n_; i++) {
			matrix_[i] = new ValueType[m_];
		}
	}
}

void Matrix::clear() {
	for (int i = 0; i < n_; i++) {
		memset(matrix_[i], 0, sizeof(ValueType) * m_);
	}
}
void Matrix::init(int n, int m) {
	n_ = m_ = 0;
	matrix_ = NULL;
	resize(n, m);
	clear();
}

void Matrix::deepCopy(const Matrix& other) {
	resize(other.n_, other.m_);
	for (int i = 0; i < n_; i++) {
		memcpy(matrix_[i], other.matrix_[i], sizeof(ValueType) * m_);
	}
}

void Matrix::swap(Matrix& other) {
	int temp = n_;
	n_ = other.n_;
	other.n_ = temp;

	temp = m_;
	m_ = other.m_;
	other.m_ = temp;

	ValueType **x = matrix_;
	matrix_ = other.matrix_;
	other.matrix_ = matrix_;
}

bool Matrix::setVal(int i, int j, ValueType val) {
	if (i < n_ && j < m_) {
		matrix_[i][j] = val;
		return true;
	}
	return false;
}

double Matrix::eucledeanDistance() {
	double distance = 0;
	for (int i = 0; i < n_; i++) {
		for (int j = 0; j < m_; j++) {
			double x = matrix_[i][j];
			distance += (x * x);
		}
	}
	return sqrt(distance);
}

#define min(x, y) \
	(((x) < (y)) ? (x) : (y))


double Matrix::eucledeanDistance(const Matrix &other) {
	double distance = 0;
	for (int i = 0; i < min(n_, other.n_); i++) {
		for (int j = 0; j < min(m_, other.m_); j++) {
			double x = (double)matrix_[i][j] - (double)other.matrix_[i][j];
			distance += (x * x);
		}
	}
	return sqrt(distance);
}
