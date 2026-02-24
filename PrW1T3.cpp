#include <iostream>
#include <cmath>
struct Triangle
{
	double a = 0;
	double b = 0;
	double c = 0;
	double S = 0;
};
namespace TriangleMathematic {
	void FindSize(Triangle& triangle) {
		double halfperimeter = (triangle.a + triangle.b + triangle.c) / 2.00;
		double size = halfperimeter * (halfperimeter - triangle.a) * (halfperimeter - triangle.b) * (halfperimeter - triangle.c);
		triangle.S = sqrt(size);
	}
	Triangle* EnterTriangles(int n) {
		Triangle* triangles = new Triangle[n]{};
		for (int i = 0; i < n; i++) {
			double a, b, c;
			std::cin >> a >> b >> c;
			if (a <= 0 || b <= 0 || c <= 0) {
				i--;
				continue;
			}
			triangles[i].a = a;
			triangles[i].b = b;
			triangles[i].c = c;
			FindSize(triangles[i]);
		}
		return triangles;
	}
	void Sort(Triangle* triangles, int size) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (triangles[j].S > triangles[j + 1].S) {
					Triangle temp = triangles[j + 1];
					triangles[j + 1] = triangles[j];
					triangles[j] = temp;
				}
			}
		}
	}
	void PrintT(const Triangle* triangles, const int size) {
		for (int i = 0; i < size; i++) {
			std::cout << (i + 1) << " S = " << triangles[i].S << std::endl;
		}
	}
}
int main()
{
	int n;
	std::cin >> n;
	Triangle* result = TriangleMathematic::EnterTriangles(n);
	TriangleMathematic::Sort(result, n);
	TriangleMathematic::PrintT(result, n);
	delete[] result;
}