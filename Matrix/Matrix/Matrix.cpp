#include <iostream>
#include "MuSoenMath.h"

using namespace std;

int main() {
	Vec3 v(2, 3, 1);
	cout << "입력한 Vec값 출력"<< endl;
	cout << v.x << " " << v.y << " " << v.z << endl;

	cout << endl;

	cout << "행렬 입력 3 x 3" << endl;
	Mat3 mat3(1, 2, 3, 4, 5, 6, 7, 8, 9);
	mat3.Transpose();
	mat3.ShowMat3();

	cout << endl;

	cout << "Mat3 * Vec3 연산 행렬" << endl;
	Mat3 Mat3_Vec3 = mat3 * v;
	Mat3_Vec3.ShowMat3();

	cout << endl;

	cout << "Mat3_Translate 행렬"  << endl;
	Mat3 Mat3_trans = Mat3_Translate(3,5);
	Mat3_trans.ShowMat3();

	cout << endl;

	cout << "Mat3_Rotation 행렬" << endl;
	Mat3 Mat3_rotation = Mat3_Rotation(30.0f);
	Mat3_rotation.Show_SinCos();

	cout << endl;

	cout << "Mat3_Scale 행렬" << endl;
	Mat3 Mat3_scale = Mat3_Scale(2);
	Mat3_scale.ShowMat3();

	cout << endl;
	cout << "Mat3_Identity 행렬" << endl;
	mat3.Identity();
	mat3.ShowMat3();

	cout << endl;

	Vec4 v4(2, 3, 4, 1);
	cout << "입력한 Vec값 출력" << endl;
	cout << v4.x << " " << v4.y << " " << v4.z << " " << v4.w << endl;

	cout << endl;

	cout << endl;
	cout << "행렬 입력 4 x 4" << endl;
	Mat4 mat4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	mat4.Transpose();
	mat4.ShowMat4();

	cout << endl;

	cout << "Mat4_Translate 행렬" << endl;
	Mat4 Mat4_trans = Mat4_Translate(3, 5, 2);
	Mat4_trans.ShowMat4();

	cout << endl;

	cout << "Mat4_Translate 행렬 연산 결과" << endl;
	Mat4 multiplyTest = mat4 * Mat4_trans;
	multiplyTest.ShowMat4();

	cout << endl;

	cout << "Mat4_Rotation 행렬" << endl;
	Mat4 Mat4_rotation = Mat4_Rotation(30.0f);
	Mat4_rotation.Show_SinCos();

	cout << endl;

	cout << "Mat4_Scale 행렬" << endl;
	Mat4 Mat4_scale = Mat4_Scale(2);
	Mat4_scale.ShowMat4();

	cout << endl;

	cout << "Mat4_Vec4 연산 행렬" << endl;
	Mat4 Mat4_Vec4 = mat4 * v4;
	Mat4_Vec4.ShowMat4();

	cout << endl;

	return 0;
}