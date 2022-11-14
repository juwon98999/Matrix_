//MuSoenMath.header File
#include <iostream>

#pragma once
#define Mat3_Max 3
#define Mat4_Max 4


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

		~Vec3() {

		}

		Vec3 operator+(const Vec3& a) {				//Vector3 더하기
			Vec3 plus_Vec;

			plus_Vec.x = x + a.x;
			plus_Vec.y = y + a.y;
			plus_Vec.z = z + a.z;

			return plus_Vec;
		}

		Vec3 operator-(const Vec3& a) {				//Vector3 빼기
			Vec3 Minus_Vec;

			Minus_Vec.x = x - a.x;
			Minus_Vec.y = y - a.y;
			Minus_Vec.z = z - a.z;

			return Minus_Vec;
		}

		Vec3 operator*(const Vec3& a) {				//Vector3 곱하기
			Vec3 multiple_Vec;

			multiple_Vec.x = x * a.x;
			multiple_Vec.y = y * a.y;
			multiple_Vec.z = z * a.z;

			return multiple_Vec;
		}

		



};



class Vec4 {
	public:

		float x;
		float y;
		float z;
		float w;

		Vec4() {
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}

		Vec4(float _x, float _y, float _z, float _w) {
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}

		~Vec4() {

		}

		Vec4 operator+(const Vec3& a) {				//Vector4 더하기
			Vec4 plus_Vec;

			plus_Vec.x = x + a.x;
			plus_Vec.y = y + a.y;
			plus_Vec.z = z + a.z;

			return plus_Vec;
		}

		Vec4 operator-(const Vec4& a) {				//Vector4 빼기
			Vec4 Minus_Vec;

			Minus_Vec.x = x - a.x;
			Minus_Vec.y = y - a.y;
			Minus_Vec.z = z - a.z;

			return Minus_Vec;
		}

		Vec4 operator*(const Vec4& a) {				//Vector4 곱하기
			Vec4 multiple_Vec;

			multiple_Vec.x = x * a.x;
			multiple_Vec.y = y * a.y;
			multiple_Vec.z = z * a.z;

			return multiple_Vec;
		}

		//Vec4 Multiply(const Mat4& b) {				//Vec3 * Mat4
		//	Vec4 Mulitply_Vec;
		//	Mulitply_Vec.x = (x * b.m4[0][0]) + (y * b.m4[0][1]) + (z * b.m4[0][2]) + (w * b.m4[0][3]);
		//	Mulitply_Vec.y = (x * b.m4[1][0]) + (y * b.m4[1][1]) + (z * b.m4[1][2]) + (w * b.m4[1][3]);;
		//	Mulitply_Vec.z = (x * b.m4[2][0]) + (y * b.m4[2][1]) + (z * b.m4[2][2]) + (w * b.m4[2][3]);;
		//	Mulitply_Vec.w = (x * b.m4[3][0]) + (y * b.m4[3][1]) + (z * b.m4[3][2]) + (w * b.m4[3][3]);;

		//	return Mulitply_Vec;
		//}
};


class Mat3 {

	int row; int col;

	public:
		float m3[3][3];		// 3 x 3 Matrix

		Mat3(float a = 0, float b = 0, float c = 0, float d = 0, float e = 0, float f = 0, float g = 0, float h = 0, float i = 0) {
			m3[0][0] = a;
			m3[0][1] = b;
			m3[0][2] = c;
			m3[1][0] = d;
			m3[1][1] = e;
			m3[1][2] = f;
			m3[2][0] = g;
			m3[2][1] = h;
			m3[2][2] = i;
		}

		~Mat3() {
			
		}
	
		Mat3 Transpose() {
			Mat3 inputMat;
			for (int i = 0; i < Mat3_Max; i++) {		//Mat3 매트릭스 생성
				for (int j = 0; j < Mat3_Max; j++) {
					inputMat.m3[i][j] = m3[i][j];
				}
			}

			for (int i = 0; i < Mat3_Max; i++) {		//Mat3 전치 행렬 변환
				for (int j = 0; j < Mat3_Max; j++) {
					m3[j][i] = inputMat.m3[i][j];
				}
			}

			return *this;
		}

		Mat3 Identity() {
			m3[0][0] = 1.0f; m3[0][1] = 0.0f; m3[0][2] = 0.0f;
			m3[1][0] = 0.0f; m3[1][1] = 1.0f; m3[1][2] = 0.0f;
			m3[2][0] = 0.0f; m3[2][1] = 0.0f; m3[2][2] = 1.0f;

			return *this;
		}

		Mat3 operator+(const Mat3 &a) {				//Matrix3 더하기
			Mat3 plus_Mat;

			for (int i = 0; i < Mat3_Max; i++) {
				for (int j = 0; j < Mat3_Max; j++) {
					plus_Mat.m3[i][j] = m3[i][j] + a.m3[i][j];
				}
			}

			return plus_Mat;
		}

		Mat3 operator-(const Mat3& a) {				//Matrix3 빼기
			Mat3 minus_Mat;

			for (int i = 0; i < Mat3_Max; i++) {
				for (int j = 0; j < Mat3_Max; j++) {
					minus_Mat.m3[i][j] = m3[i][j] - a.m3[i][j];
				}
			}

			return minus_Mat;
		}

		Mat3 operator*(const Mat3& a) {				//Matrix3 곱셉
			Mat3 multiple_Mat;
			multiple_Mat.row = a.row;
			multiple_Mat.col = multiple_Mat.col;

			for (int i = 0; i < Mat3_Max; i++) {
				for (int j = 0; j < Mat3_Max; j++) {
					for (int z = 0; z < Mat3_Max; z++) {
						multiple_Mat.m3[i][j] = (m3[i][z] * a.m3[z][j]) + multiple_Mat.m3[i][j];
					}
				}
			}

			return multiple_Mat;
		}


		inline Mat3 operator*(const Vec3& a) {				//Vec3 * Mat3
			Mat3 Mulitply_Vec;

			Mulitply_Vec.m3[0][0] = m3[2][2]; Mulitply_Vec.m3[0][1] = 0; Mulitply_Vec.m3[0][2] = (a.x * m3[0][0]) + (a.y * m3[0][1]) + (a.z * m3[0][2]);
			Mulitply_Vec.m3[1][0] = 0; Mulitply_Vec.m3[1][1] = m3[2][2]; Mulitply_Vec.m3[1][2] = (a.x * m3[1][0]) + (a.y * m3[1][1]) + (a.z * m3[1][2]);
			Mulitply_Vec.m3[2][0] = 0; Mulitply_Vec.m3[2][1] = 0; Mulitply_Vec.m3[2][2] = m3[2][2];
			
			return (Mulitply_Vec);
		}


		void ShowMat3() {
			for (int i = 0; i < Mat3_Max; i++) {
				for (int j = 0; j < Mat3_Max; j++) {
					std::cout << m3[i][j] << " ";
				}
				std::cout << std::endl;
			}
		}

		void Show_SinCos() {
			for (int i = 0; i < Mat3_Max; i++) {
				for (int j = 0; j < Mat3_Max; j++) {
					printf("%lf  ", m3[i][j]);
				}
				std::cout << std::endl;
			}
		}


};

Mat3 Mat3_Translate(float a, float b) {
	Mat3 Translate( 1, 0, a,
					0, 1, b,
					0, 0, 1);
	Translate.Transpose();


	return Translate;
}

Mat3 Mat3_Rotation(float a) {
	const float PI = 3.1415926;
	Mat3 Rotation(sin(a * PI / 180), cos(a * PI / 180), 0, -cos(a * PI / 180), sin(a * PI / 180), 0, 0, 0, 1);
	Rotation.Transpose();


	return Rotation;
}


Mat3 Mat3_Scale(float a) {
	Mat3 Scale( a, 0, 0,
				0, a, 0,
				0, 0, 1);
	Scale.Transpose();


	return Scale;
}



class Mat4 {		//수정완료

	int row; int col;

public:
	float m4[4][4];		// 4 x 4 Matrix

	Mat4(float a = 0, float b = 0, float c = 0, float d = 0, float e = 0, float f = 0, float g = 0, float h = 0, float i = 0,
		float j = 0, float k = 0, float l = 0, float m = 0, float n = 0, float o = 0, float p = 0) {
		m4[0][0] = a;
		m4[0][1] = b;
		m4[0][2] = c;
		m4[0][3] = d;
		m4[1][0] = e;
		m4[1][1] = f;
		m4[1][2] = g;
		m4[1][3] = h;
		m4[2][0] = i;
		m4[2][1] = j;
		m4[2][2] = k;
		m4[2][3] = l;
		m4[3][0] = m;
		m4[3][1] = n;
		m4[3][2] = o;
		m4[3][3] = p;
	}

	~Mat4() {

	}

	Mat4 Transpose() {
		Mat4 inputMat;
		for (int i = 0; i < Mat4_Max; i++) {		//Mat4 매트릭스 생성
			for (int j = 0; j < Mat4_Max; j++) {
				inputMat.m4[i][j] = m4[i][j];
			}
		}

		for (int i = 0; i < Mat4_Max; i++) {		//Mat4 전치 행렬 변환
			for (int j = 0; j < Mat4_Max; j++) {
				m4[j][i] = inputMat.m4[i][j];
			}
		}

		return *this;
	}

	Mat4 Identity() {
		m4[0][0] = 1.0f; m4[0][1] = 0.0f; m4[0][2] = 0.0f; m4[0][3] = 0.0f;
		m4[1][0] = 0.0f; m4[1][1] = 1.0f; m4[1][2] = 0.0f; m4[1][3] = 0.0f;
		m4[2][0] = 0.0f; m4[2][1] = 0.0f; m4[2][2] = 1.0f; m4[2][3] = 0.0f;
		m4[3][0] = 0.0f; m4[3][1] = 0.0f; m4[3][2] = 0.0f; m4[3][3] = 1.0f;

		return *this;
	}

	Mat4 operator+(const Mat4& a) {				//Matrix4 더하기
		Mat4 plus_Mat;

		for (int i = 0; i < Mat4_Max; i++) {
			for (int j = 0; j < Mat4_Max; j++) {
				plus_Mat.m4[i][j] = m4[i][j] + a.m4[i][j];
			}
		}

		return plus_Mat;
	}

	Mat4 operator-(const Mat4& a) {				//Matrix4 빼기
		Mat4 minus_Mat;

		for (int i = 0; i < Mat4_Max; i++) {
			for (int j = 0; j < Mat4_Max; j++) {
				minus_Mat.m4[i][j] = m4[i][j] - a.m4[i][j];
			}
		}

		return minus_Mat;
	}

	Mat4 operator*(const Mat4& a) {				//Matrix4 곱셉
		Mat4 multiple_Mat;

		for (int i = 0; i < Mat4_Max; i++) {
			for (int j = 0; j < Mat4_Max; j++) {
				for (int z = 0; z < Mat4_Max; z++) {
					multiple_Mat.m4[i][j] = (m4[i][z] * a.m4[z][j]) + multiple_Mat.m4[i][j];
				}
			}
		}

		return multiple_Mat;
	}

	inline Mat4 operator*(const Vec4& a) {				//Vec4 * Mat4  
		Mat4 Mulitply_Vec;

		Mulitply_Vec.m4[0][0] = m4[3][3]; Mulitply_Vec.m4[0][1] = 0; Mulitply_Vec.m4[0][2] = 0; Mulitply_Vec.m4[0][3] = (a.x * m4[0][0]) + (a.y * m4[0][1]) + (a.z * m4[0][2]) + (a.w * m4[0][3]);
		Mulitply_Vec.m4[1][0] = 0; Mulitply_Vec.m4[1][1] = m4[3][3]; Mulitply_Vec.m4[0][2] = 0; Mulitply_Vec.m4[1][3] = (a.x * m4[1][0]) + (a.y * m4[1][1]) + (a.z * m4[1][2]) + (a.w * m4[0][3]);
		Mulitply_Vec.m4[2][0] = 0; Mulitply_Vec.m4[2][1] = 0; Mulitply_Vec.m4[2][2] = m4[3][3]; Mulitply_Vec.m4[2][3] = (a.x * m4[1][0]) + (a.y * m4[1][1]) + (a.z * m4[1][2]) + (a.w * m4[0][3]);
		Mulitply_Vec.m4[3][0] = 0; Mulitply_Vec.m4[3][1] = 0; Mulitply_Vec.m4[3][2] = 0; Mulitply_Vec.m4[3][3] = m4[3][3];

		return (Mulitply_Vec);
	}

	Mat4 Multiply(const Mat4 &m4, const Vec3 &v3) {
		Mat4 multiple_Mat;


		return multiple_Mat;
	}

	Mat4 Multiply(const Mat4& m4, const Mat3& m3) {
		Mat4 multiple_Mat;


		return multiple_Mat;
	}



	void ShowMat4() {
		for (int i = 0; i < Mat4_Max; i++) {
			for (int j = 0; j < Mat4_Max; j++) {
				std::cout << m4[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	void Show_SinCos() {
		for (int i = 0; i < Mat4_Max; i++) {
			for (int j = 0; j < Mat4_Max; j++) {
				printf("%lf  ", m4[i][j]);
				/*std::cout << m[i][j] << " ";*/
			}
			std::cout << std::endl;
		}
	}

};

Mat4 Mat4_Translate(float a, float b, float c) {
	Mat4 Translate( 1, 0, 0, a,
					0, 1, 0, b,
					0, 0, 1, c,
					0, 0, 0, 1);
	Translate.Transpose();


	return Translate;
}

Mat4 Mat4_Rotation(float a) {  //Rotation 부분 수정 필요
	const float PI = 3.1415926;
	Mat4 Rotation(sin(a * PI / 180), cos(a * PI / 180), 0, -cos(a * PI / 180), sin(a * PI / 180), 0, 0, 0, 1);
	Rotation.Transpose();


	return Rotation;
}


Mat4 Mat4_Scale(float a) {
	Mat4 Scale( a, 0, 0, 0,
				0, a, 0, 0,
				0, 0, a, 0,
				0, 0, 0, 1);

	Scale.Transpose();


	return Scale;
}


