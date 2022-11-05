#include <iostream>
#include "MuSoenMath.h"

using namespace std;

int main() {
	//Vec3 test(2, 3, 1);
	//cout << test.x << endl;
	//cout << test.y << endl;
	//cout << test.z << endl;
	//Vec3 test2(1, 1, 1);

	//Vec3 add = test * test2;
	//cout << add.x << endl;
	//cout << add.y << endl;
	//cout << add.z << endl;

	Mat3 mat1(2, 4, 6, 8, 10, 12, 14, 16, 18);
	Mat3 mat2(1, 2, 3, 4, 5, 6, 7, 8, 9);
	mat1.Transpose();
	mat2.Transpose();
	mat1.ShowMat3();
	cout << endl;
	mat2.ShowMat3();

	cout << endl;
	Mat3 mat3 = mat1 * mat2;
	mat3.ShowMat3();

	cout << endl;
	Mat3 mat4 = mat1 + mat2;
	mat4.ShowMat3();

	return 0;
}