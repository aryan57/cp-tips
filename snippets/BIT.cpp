class BIT {
  public:
	using T = int;
	int _n;
	vector<T> data;

	BIT(int n) : _n(n), data(n) {}

	void add(int p, T x) {
		p++;
		while (p <= _n) {
			data[p - 1] += (x);
			p += p & -p;
		}
	}

	T sum(int r) {
		T s = 0;
		while (r > 0) {
			s += data[r - 1];
			r -= r & -r;
		}
		return s;
	}
};
