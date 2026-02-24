#include <iostream>
struct Point
{
    double x;
	double y;
	void Read() {
		std::cin >> x >> y;
	}
	void Print() {
		std::cout << "x = " << x << "\n" << "y = " << y << "\n";
	}
	double DistanceToOrigin() const {
		return sqrt(x * x + y * y);
	}
	double Distance(const Point& other) const {
		return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
	}
	int Quadrant() const {
		if (x > 0 && y > 0) {
			return 1;
		}
		else if (x < 0 && y > 0) {
			return 2;
		}
		else if (x < 0 && y < 0) {
			return 3;
		}
		else if (x > 0 && y < 0) {
			return 4;
		}
		else {
			return 0; // On an axis
		}
	}
};
int main()
{
    std::cout << "Hello World!\n";
}