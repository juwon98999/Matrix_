#include <iostream>
#include "MuSoenMath.h"

using namespace std;

int main() {
	/*Vec3 test(2, 3, 1);
	cout << test.x << endl;
	cout << test.y << endl;
	cout << test.z << endl;
	Vec3 test2(1, 1, 1);

	Vec3 add = test * test2;
	cout << add.x << endl;
	cout << add.y << endl;
	cout << add.z << endl;*/

	cout << endl;

	cout << "행렬 입력 3 x 3" << endl;
	Mat3 mat2(1, 2, 3, 4, 5, 6, 7, 8, 9);
	mat2.Transpose();
	mat2.ShowMat3();

	cout << endl;

	cout << "Translate 행렬"  << endl;
	Mat3 trans = Translate(3,5);
	trans.ShowMat3();

	cout << endl;

	cout << "Rotation 행렬" << endl;
	Mat3 rotation = Rotation(30.0f);
	rotation.Show_SinCos();

	cout << endl;

	cout << "Scale 행렬" << endl;
	Mat3 scale = Scale(2);
	scale.ShowMat3();

	return 0;
}