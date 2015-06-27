#include <unordered_map>
#include <unordered_set>
#include <utility>

using std::unordered_map;
using std::pair;
using std::make_pair;
 
struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};


typedef int NodeKeyType;
typedef double ValueType;

typedef unordered_map<pair<NodeKeyType, NodeKeyType>, ValueType, pairhash> table;

class Matrix {
	public:
		Matrix(const Matrix& other) : map_(other.map_) {
		}

		void swap(Matrix& other) {
			map_.swap(other.map_);
		}
		bool setValue(NodeKeyType i, NodeKeyType j, ValueType val) {
			pair<NodeKeyType, NodeKeyType> key = std::make_pair(i, j);
			return setValue(key, val);
		}

		bool setValue(const pair<NodeKeyType, NodeKeyType> &key, ValueType val) {
			map_.erase(key);
			return map_.insert(table::value_type(key, val));
		}

		ValueType getValue(const pair<NodeKeyType, NodeKeyType> &key) {
			pair<NodeKeyType, NodeKeyType> key = std::make_pair(i, j);
			table::const_iterator itt = map_.find(key);

			return itt != map_.end() ? itt->second : 0.0;
		}
		void clear() {
			map_.clear();
		}
		void weightedAdd(double weight, const Matrix& ohter);
		double eucledeanDistance(const Matrix &other_) const;
		double eucledeanDistance() const;

	private:
		table map_;
};
