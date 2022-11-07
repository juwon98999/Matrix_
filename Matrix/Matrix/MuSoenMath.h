//MuSoenMath.header File
#include <iostream>

#pragma once
#define Mat3_Max 3

using namespace std;

class Vec3 {
	public:
		float x;
		float y;
		float z;

		Vec3() {
			x = 0;
			y = 0;
			z = 0;
		}

		Vec3(float _x, float _y, float _z) {
			x = _x;
			y = _y;
			z = _z;
		}

		friend Vec3 operator+(const Vec3& a, const Vec3& b) {
			float Vx = a.x + b.x;
			float Vy = a.y + b.y;
			float Vz = a.z + b.z;

			return Vec3(Vx, Vy, Vz);
		}

		friend Vec3 operator-(const Vec3& a, const Vec3& b) {
			float Vx = a.x - b.x;
			float Vy = a.y - b.y;
			float Vz = a.z - b.z;

			return Vec3(Vx, Vy, Vz);
		}

		//friend Vec3 operator*(const Vec3& a, const Mat3& b) { 
		//	float Vx = (a.x * b.m[0][0]) + (a.y * b.m[0][1]) + (a.y * b.m[0][2]);
		//	float Vy = (a.x * b.m[1][0]) + (a.y * b.m[1][1]) + (a.y * b.m[1][2]);
		//	float Vz = (a.x * b.m[2][0]) + (a.y * b.m[2][1]) + (a.y * b.m[2][2]);


		//	return Vec3(Vx, Vy, Vz);
		//}

};



class Mat3 {

	int row; int col;

	public:
		float m[3][3];		// 3 x 3 Matrix

		Mat3(float a = 0, float b = 0, float c = 0, float d = 0, float e = 0, float f = 0, float g = 0, float h = 0, float i = 0) {
			m[0][0] = a;
			m[0][1] = b;
			m[0][2] = c;
			m[1][0] = d;
			m[1][1] = e;
			m[1][2] = f;
			m[2][0] = g;
			m[2][1] = h;
			m[2][2] = i;
		}

		~Mat3() {
			
		}
	
		Mat3 Transpose() {
			Mat3 inputMat;
			for (int i = 0; i < Mat3_Max; i++) {		//매트릭스 생성
				for (int j = 0; j < Mat3_Max; j++) {
					inputMat.m[i][j] = m[i][j];
				}
			}

			for (int i = 0; i < Mat3_Max; i++) {		//전치 행렬 변환
				for (int j = 0; j < Mat3_Max; j++) {
					m[j][i] = inputMat.m[i][j];
				}
			}

			return *this;
		}

		Mat3 operator+(const Mat3 &a) {				//Matrix 더하기
			Mat3 plus_Mat;

			for (int i = 0; i < Mat3_Max; i++) {
				for (int j = 0; j < Mat3_Max; j++) {
					plus_Mat.m[i][j] = m[i][j] + a.m[i][j];
				}
			}

			return plus_Mat;
		}

		Mat3 operator-(const Mat3& a) {				//Matrix 빼기
			Mat3 minus_Mat;

			for (int i = 0; i < Mat3_Max; i++) {
				for (int j = 0; j < Mat3_Max; j++) {
					minus_Mat.m[i][j] = m[i][j] - a.m[i][j];
				}
			}

			return minus_Mat;
		}

		Mat3 operator*(const Mat3& a) {				//Matrix 곱셉
			Mat3 multiple_Mat;
			multiple_Mat.row = a.row;
			multiple_Mat.col = multiple_Mat.col;

			for (int i = 0; i < Mat3_Max; i++) {
				for (int j = 0; j < Mat3_Max; j++) {
					for (int z = 0; z < Mat3_Max; z++) {
						multiple_Mat.m[i][j] = (m[i][z] * a.m[z][j]) + multiple_Mat.m[i][j];
					}
				}
			}

			return multiple_Mat;
		}


		void ShowMat3() {
			for (int i = 0; i < Mat3_Max; i++) {
				for (int j = 0; j < Mat3_Max; j++) {
					std::cout << m[i][j] << " ";
				}
				std::cout << std::endl;
			}
		}

		void Show_SinCos() {
			for (int i = 0; i < Mat3_Max; i++) {
				for (int j = 0; j < Mat3_Max; j++) {
					printf("%lf  ", m[i][j]);
					/*std::cout << m[i][j] << " ";*/
				}
				std::cout << std::endl;
			}
		}

};

Mat3 Translate(float a, float b) {
	Mat3 Translate(1,0,0,0,1,0,a,b,1);
	Translate.Transpose();


	return Translate;
}

Mat3 Rotation(float a) {
	const float PI = 3.1415926;
	Mat3 Rotation(sin(a * PI/180), cos(a * PI / 180), 0, -cos(a * PI / 180), sin(a * PI / 180), 0, 0, 0, 1);
	Rotation.Transpose();


	return Rotation;
}


Mat3 Scale(float a) {
	Mat3 Scale(a, 0, 0, 0, a, 0, 0, 0, 1);
	Scale.Transpose();


	return Scale;
}