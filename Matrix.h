typedef unsigned long long ValueType;
class Matrix {
	private:
		int n_;
		int m_;
		ValueType **matrix_;
		Matrix() {}
		void resize(int n, int m);
		void clear();
		void deepCopy(const Matrix& other);
		void init(int n, int m);
	public:
		Matrix(int n, int m) {
			init(n, m);
		}
		Matrix(int n) {
			init(n, n);
		}
		Matrix(const Matrix& other) : n_(0), m_(0), matrix_(0) {
			deepCopy(other);
		}
		Matrix& operator = (const Matrix& other) {
			deepCopy(other);
			return *this;
		}

		void swap(Matrix& other);
		bool setVal(int i, int j, ValueType val);
		double eucledeanDistance(const Matrix &other_);
		double eucledeanDistance();
		~Matrix() {
			for (int i = 0; i < n_; i++) {
				delete []matrix_[i];
			}
			delete []matrix_;
		}
};
