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
		bool setVal(NodeKeyType i, NodeKeyType j, ValueType val) {
			pair<NodeKeyType, NodeKeyType> p = std::make_pair(i, j);
			map_.erase(p);
			map_.insert(table::value_type(std::make_pair(p, val)));
		}
		void clear() {
			map_.clear();
		}
		double eucledeanDistance(const Matrix &other_) const;
		double eucledeanDistance() const;

	private:
		table map_;
};
