#include "Matrix.h"
#include <math.h>

double Matrix::eucledeanDistance() const {
	double distance = 0.0;

	for (table::const_iterator it = map_.begin();
		 it != map_.end(); ++it) {
		const double &x = it->second;
		distance += (x* x);
	}
	return sqrt(distance);
}

double Matrix::eucledeanDistance(const Matrix &other) const {
	double distance = 0.0;
	for (table::const_iterator it = map_.begin(); it != map_.end(); ++it) {
		const auto& key = it->first;
		double x = it->second;
		table::const_iterator itt = other.map_.find(key);
		if (itt != other.map_.end()) {
			x -= itt->second;
		}
		distance += (x* x);
	}

	// For keys only present in other.
	for (table::const_iterator it = other.map_.begin(); it != map_.end(); ++it) {
		const auto& key = it->first;
		const double x = it->second;
		table::const_iterator itt = map_.find(key);
		if (itt == map_.end()) {
			const double &x = it->second;
			distance += (x* x);
		}
	}
	return sqrt(distance);
}
