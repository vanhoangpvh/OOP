#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

class Point {
private:
	double x;
	double y;
	int cluster;
	double minDist;
public:
	Point() {
		x = 0.0;
		y = 0.0;
		cluster = -1;
		minDist = DBL_MAX;
	}

	Point(double X, double Y) {
		x = X;
		y = Y;
		cluster = -1;
		minDist = DBL_MAX;
	}

	double distance(Point P) {
		return ((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
	}
};

vector<Point> readcsv() {
	vector<Point> points;
	string line;
	ifstream file("D:\\Mall_Customers.csv");

	while (getline(file, line)) {
		stringstream lineStream(line);
		string bit;
		double x, y;
		getline(lineStream, bit, ',');
		x = stof(bit);
		getline(lineStream, bit, '\n');
		y = stof(bit);

		points.push_back(Point(x, y));
	}
	return points;
}

void kMeansClustering(vector<Point>* points, int epochs, int k) {
	//Initializing the clusters
	vector<Point>centroids;
	srand(time(0));
	for (int i = 0; i < k; i++) {
		centroids.push_back(points->at(rand() % points->size()));
	}
}

int main() {
	Point A(1.0, 1.0);
	Point B(2.0, 2.0);
	cout << A.distance(B);

	for()
}

