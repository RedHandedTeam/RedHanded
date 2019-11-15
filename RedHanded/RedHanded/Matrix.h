#ifndef MATRIX_H
#define MATRIX_H

#include "Vector3.h"
//#include "Quaternion.h"

class Matrix
{

public:

	static const Matrix Identity;

public:

	Matrix();
	
public:

	float& operator[](int index);
	Matrix operator*(Matrix& second);
	Matrix& operator*=(Matrix& second);

    Vector3<float> operator*(const Vector3<float>& second);
    //Quaternion operator*(const Quaternion& second);

public:

	Matrix Inverse();

private:

	float m_matrix[16];

};

const Matrix Matrix::Identity = Matrix();

//======================================================================================================
Matrix::Matrix()
{

	for (int i = 0; i < 16; i++)
	{
		m_matrix[i] = 0.0f;
	}

	m_matrix[0] = 1.0f;
	m_matrix[5] = 1.0f;
	m_matrix[10] = 1.0f;
	m_matrix[15] = 1.0f;

}
//======================================================================================================
float& Matrix::operator[](int index) 
{
	return m_matrix[index];
}
//======================================================================================================
Matrix Matrix::operator*(Matrix& second)
{
	Matrix result(*this);
	return (result *= second);
}
//======================================================================================================
Matrix& Matrix::operator*=(Matrix& second)
{
	int count = 0;
	float rowFirst[4];
	float colSecond[4];

	for (int i = 0; i < 4; i++)
	{
		colSecond[0] = second[i * 4];
		colSecond[1] = second[i * 4 + 1];
		colSecond[2] = second[i * 4 + 2];
		colSecond[3] = second[i * 4 + 3];

		
		for (int j = 0; j < 4; j++)
		{
			rowFirst[0] = m_matrix[j];
			rowFirst[1] = m_matrix[j + 4];
			rowFirst[2] = m_matrix[j + 8];
			rowFirst[3] = m_matrix[j + 12];


			m_matrix[count++] = rowFirst[0] * colSecond[0] +
								rowFirst[1] * colSecond[1] +
								rowFirst[2] * colSecond[2] +
								rowFirst[3] * colSecond[3];
		}
	}

	return *this;
}
//======================================================================================================
Vector3<float> Matrix::operator*(const Vector3<float>& second)
{
	int count = 0;
	float rowFirst[4];
	float tempResult[3];
	Vector3<float> result;

	for (int i = 0; i < 4; i++)
	{
		rowFirst[0] = m_matrix[i];
		rowFirst[1] = m_matrix[i + 4];
		rowFirst[2] = m_matrix[i + 8];
		rowFirst[3] = m_matrix[i + 12];

		tempResult[count++] = rowFirst[0] * second.x +
							  rowFirst[1] * second.y +
							  rowFirst[2] * second.z;
	}

	result.x = tempResult[0];
	result.y = tempResult[1];
	result.z = tempResult[2];

	return result;
}
//======================================================================================================
//Matrix Matrix::Inverse()
//{
//
//	//variables for determinant and temp float array
//	float determinant = 0;
//	float tempArray[9] = { 0 };
//
//	//result matrix to store final result and 
//	//temp 3x3 matrix to be used to calculate determinant
//	Matrix result;
//	Matrix3D tempMatrix3D;
//
//	//temp 3x3 matrices used to store four particular 
//	//matrices and calculate final determinant value 
//	Matrix3D matrix_1;
//	Matrix3D matrix_2;
//	Matrix3D matrix_3;
//	Matrix3D matrix_4;
//
//	//the first step is to calculate the matrix of minors
//	//this is a loooong calculation that basically loops through 
//	//each of the 16 matrix elements and calculates the determinant 
//	//of the remaining 3x3 matrices formed. The determinant is then 
//	//stored in each element of the result matrix
//
//	//---------------
//	//Matrix Column 1 
//	//---------------
//
//	//matrix element 0
//	tempArray[0] = m_matrix[5]; tempArray[1] = m_matrix[6]; tempArray[2] = m_matrix[7];
//	tempArray[3] = m_matrix[9]; tempArray[4] = m_matrix[10]; tempArray[5] = m_matrix[11];
//	tempArray[6] = m_matrix[13]; tempArray[7] = m_matrix[14]; tempArray[8] = m_matrix[15];
//
//	tempMatrix3D = tempArray;
//	result[0] = tempMatrix3D.Determinant();
//
//	//store this 3x3 matrix for determinant calculation later on
//	matrix_1 = tempArray;
//
//	//matrix element 1
//	tempArray[0] = m_matrix[4]; tempArray[1] = m_matrix[6]; tempArray[2] = m_matrix[7];
//	tempArray[3] = m_matrix[8]; tempArray[4] = m_matrix[10]; tempArray[5] = m_matrix[11];
//	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[14]; tempArray[8] = m_matrix[15];
//
//	tempMatrix3D = tempArray;
//	result[1] = tempMatrix3D.Determinant();
//
//	//matrix element 2
//	tempArray[0] = m_matrix[4]; tempArray[1] = m_matrix[5]; tempArray[2] = m_matrix[7];
//	tempArray[3] = m_matrix[8]; tempArray[4] = m_matrix[9]; tempArray[5] = m_matrix[11];
//	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[13]; tempArray[8] = m_matrix[15];
//
//	tempMatrix3D = tempArray;
//	result[2] = tempMatrix3D.Determinant();
//
//	//matrix element 3
//	tempArray[0] = m_matrix[4]; tempArray[1] = m_matrix[5]; tempArray[2] = m_matrix[6];
//	tempArray[3] = m_matrix[8]; tempArray[4] = m_matrix[9]; tempArray[5] = m_matrix[10];
//	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[13]; tempArray[8] = m_matrix[14];
//
//	tempMatrix3D = tempArray;
//	result[3] = tempMatrix3D.Determinant();
//
//	//---------------
//	//Matrix Column 2 
//	//---------------
//
//	//matrix element 4
//	tempArray[0] = m_matrix[1]; tempArray[1] = m_matrix[2]; tempArray[2] = m_matrix[3];
//	tempArray[3] = m_matrix[9]; tempArray[4] = m_matrix[10]; tempArray[5] = m_matrix[11];
//	tempArray[6] = m_matrix[13]; tempArray[7] = m_matrix[14]; tempArray[8] = m_matrix[15];
//
//	tempMatrix3D = tempArray;
//	result[4] = tempMatrix3D.Determinant();
//
//	//store this 3x3 matrix for determinant calculation later on
//	matrix_2 = tempArray;
//
//	//matrix element 5
//	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[2]; tempArray[2] = m_matrix[3];
//	tempArray[3] = m_matrix[8]; tempArray[4] = m_matrix[10]; tempArray[5] = m_matrix[11];
//	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[14]; tempArray[8] = m_matrix[15];
//
//	tempMatrix3D = tempArray;
//	result[5] = tempMatrix3D.Determinant();
//
//	//matrix element 6
//	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[1]; tempArray[2] = m_matrix[3];
//	tempArray[3] = m_matrix[8]; tempArray[4] = m_matrix[9]; tempArray[5] = m_matrix[11];
//	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[13]; tempArray[8] = m_matrix[15];
//
//	tempMatrix3D = tempArray;
//	result[6] = tempMatrix3D.Determinant();
//
//	//matrix element 7
//	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[1]; tempArray[2] = m_matrix[2];
//	tempArray[3] = m_matrix[8]; tempArray[4] = m_matrix[9]; tempArray[5] = m_matrix[10];
//	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[13]; tempArray[8] = m_matrix[14];
//
//	tempMatrix3D = tempArray;
//	result[7] = tempMatrix3D.Determinant();
//
//	//---------------
//	//Matrix Column 3 
//	//---------------
//
//	//matrix element 8
//	tempArray[0] = m_matrix[1]; tempArray[1] = m_matrix[2]; tempArray[2] = m_matrix[3];
//	tempArray[3] = m_matrix[5]; tempArray[4] = m_matrix[6]; tempArray[5] = m_matrix[7];
//	tempArray[6] = m_matrix[13]; tempArray[7] = m_matrix[14]; tempArray[8] = m_matrix[15];
//
//	tempMatrix3D = tempArray;
//	result[8] = tempMatrix3D.Determinant();
//
//	//store this 3x3 matrix for determinant calculation later on
//	matrix_3 = tempArray;
//
//	//matrix element 9
//	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[2]; tempArray[2] = m_matrix[3];
//	tempArray[3] = m_matrix[4]; tempArray[4] = m_matrix[6]; tempArray[5] = m_matrix[7];
//	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[14]; tempArray[8] = m_matrix[15];
//
//	tempMatrix3D = tempArray;
//	result[9] = tempMatrix3D.Determinant();
//
//	//matrix element 10
//	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[1]; tempArray[2] = m_matrix[3];
//	tempArray[3] = m_matrix[4]; tempArray[4] = m_matrix[5]; tempArray[5] = m_matrix[7];
//	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[13]; tempArray[8] = m_matrix[15];
//
//	tempMatrix3D = tempArray;
//	result[10] = tempMatrix3D.Determinant();
//
//	//matrix element 11
//	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[1]; tempArray[2] = m_matrix[2];
//	tempArray[3] = m_matrix[4]; tempArray[4] = m_matrix[5]; tempArray[5] = m_matrix[6];
//	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[13]; tempArray[8] = m_matrix[14];
//
//	tempMatrix3D = tempArray;
//	result[11] = tempMatrix3D.Determinant();
//
//	//---------------
//	//Matrix Column 4 
//	//---------------
//
//	//matrix element 12
//	tempArray[0] = m_matrix[1]; tempArray[1] = m_matrix[2]; tempArray[2] = m_matrix[3];
//	tempArray[3] = m_matrix[5]; tempArray[4] = m_matrix[6]; tempArray[5] = m_matrix[7];
//	tempArray[6] = m_matrix[9]; tempArray[7] = m_matrix[10]; tempArray[8] = m_matrix[11];
//
//	tempMatrix3D = tempArray;
//	result[12] = tempMatrix3D.Determinant();
//
//	//store this 3x3 matrix for determinant calculation later on
//	matrix_4 = tempArray;
//
//	//matrix element 13
//	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[2]; tempArray[2] = m_matrix[3];
//	tempArray[3] = m_matrix[4]; tempArray[4] = m_matrix[6]; tempArray[5] = m_matrix[7];
//	tempArray[6] = m_matrix[8]; tempArray[7] = m_matrix[10]; tempArray[8] = m_matrix[11];
//
//	tempMatrix3D = tempArray;
//	result[13] = tempMatrix3D.Determinant();
//
//	//matrix element 14
//	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[1]; tempArray[2] = m_matrix[3];
//	tempArray[3] = m_matrix[4]; tempArray[4] = m_matrix[5]; tempArray[5] = m_matrix[7];
//	tempArray[6] = m_matrix[8]; tempArray[7] = m_matrix[9]; tempArray[8] = m_matrix[11];
//
//	tempMatrix3D = tempArray;
//	result[14] = tempMatrix3D.Determinant();
//
//	//matrix element 15
//	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[1]; tempArray[2] = m_matrix[2];
//	tempArray[3] = m_matrix[4]; tempArray[4] = m_matrix[5]; tempArray[5] = m_matrix[6];
//	tempArray[6] = m_matrix[8]; tempArray[7] = m_matrix[9]; tempArray[8] = m_matrix[10];
//
//	tempMatrix3D = tempArray;
//	result[15] = tempMatrix3D.Determinant();
//
//	//the next step is to calculate the matrix of cofactors
//	//this applies a checkerboard of + and - symbols in a specific 
//	//sequence to each matrix element. All that needs to be done is 
//	//apply the - values, as the positive numbers remain the same 
//	result[1] *= -1;
//	result[3] *= -1;
//	result[4] *= -1;
//	result[6] *= -1;
//	result[9] *= -1;
//	result[11] *= -1;
//	result[12] *= -1;
//	result[14] *= -1;
//
//	//next is to calculate the adjugate
//	//this merely means to flip the matrix along the major diagonal
//	std::swap(result[4], result[1]);
//	std::swap(result[2], result[8]);
//	std::swap(result[6], result[9]);
//	std::swap(result[12], result[3]);
//	std::swap(result[13], result[7]);
//	std::swap(result[14], result[11]);
//
//	//the final calculation is to find the determinant of the original matrix
//	//using a formula that uses the four temporary 3x3 matrices stored earlier
//	determinant = m_matrix[0] * matrix_1.Determinant() - m_matrix[4] * matrix_2.Determinant() +
//		m_matrix[8] * matrix_3.Determinant() - m_matrix[12] * matrix_4.Determinant();
//
//	//only if the determinant is not 0
//	//then multiply the result matrix by 1/det
//	if (determinant != 0)
//	{
//		return (result * (1.0f / determinant));
//	}
//
//	//otherwise return original matrix as we
//	//cannot find the inverse
//	return *this;
//
//}

#endif