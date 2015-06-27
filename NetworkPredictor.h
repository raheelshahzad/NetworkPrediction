#include "Matrix.h"

class NetworkPredictor {
	public:
		NetworkPredictor(int num_of_experts) : num_of_experts_(num_of_experts), iondex_(0) {
			weights_ = new double[num_of_experts_];
			experts_ = new Matrix[num_of_experts_];
			predictions_ = new Matrix[num_of_experts_];

			double w = (double)1.0 / (double)(num_of_experts_);

			for (int i = 0; i < num_of_experts_; i++) {
				weights_[i] = w;
			}
		}

		const Matrix& moveNext() {
			double normalizer = 0.0;
			
			for (int i = 0 ; i < num_of_experts_; i++) {
				weights_[i] *= 	exp(LoseRatio(i));
				normalizer += weights_[i];
			}

			prediction_.clear();
			for (int i = 0 ; i < num_of_experts_; i++) {
				weights_[i] /= normalizer;
				prediction_.weightedAdd(weights_[i], experts_[i]); 
			}

			index_ = (index_ + 1) % num_of_experts_;
			experts_.clear();	
			return prediction_;
		}

		bool setValue(int i, int j, double val) {
			experts_[index_].setValue(ui, j, val);
		}
	private:
		double LoseRatio(int i) {
			return experts_[i].eucledeanDistance(experts_[index_]) /
				experts_[i].eucledeanDistance();
		}

	private:
		int num_of_experts_;
		int index_;
		double *weights_;
		Matrix *experts_;
		Matrix prediction_;	
};
