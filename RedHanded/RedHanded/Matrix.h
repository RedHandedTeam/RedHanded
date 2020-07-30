#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>

#include "Quaternion.h"

class Matrix
{

public:

	//=============================================================
	static const Matrix Identity() { return Matrix(); };

public:

	//=============================================================
	inline Matrix()
	{
		m_matrix[0] = 1.f; m_matrix[4] = 0.f; m_matrix[8]  = 0.f; m_matrix[12] = 0.f;
		m_matrix[1] = 0.f; m_matrix[5] = 1.f; m_matrix[9]  = 0.f; m_matrix[13] = 0.f;
		m_matrix[2] = 0.f; m_matrix[6] = 0.f; m_matrix[10] = 1.f; m_matrix[14] = 0.f;
		m_matrix[3] = 0.f; m_matrix[7] = 0.f; m_matrix[11] = 0.f; m_matrix[15] = 1.f;
	}
	//=============================================================
	inline Matrix(const Quaternion& quaternion)
	{
		m_matrix[0] = (float)(1.f - 2.f * (quaternion.xyz.y * quaternion.xyz.y + quaternion.xyz.z * quaternion.xyz.z));
		m_matrix[1] = (float)(2.f *		  (quaternion.xyz.x * quaternion.xyz.y + quaternion.xyz.z * quaternion.w));
		m_matrix[2] = (float)(2.f *		  (quaternion.xyz.x * quaternion.xyz.z - quaternion.xyz.y * quaternion.w));
		m_matrix[3] = 0.f;

		m_matrix[4] = (float)(2.f *		  (quaternion.xyz.x * quaternion.xyz.y - quaternion.xyz.z * quaternion.w));
		m_matrix[5] = (float)(1.f - 2.f * (quaternion.xyz.x * quaternion.xyz.x + quaternion.xyz.z * quaternion.xyz.z));
		m_matrix[6] = (float)(2.f *		  (quaternion.xyz.z * quaternion.xyz.y + quaternion.xyz.x * quaternion.w));
		m_matrix[7] = 0.f;

		m_matrix[8]  = (float)(2.f *	   (quaternion.xyz.x * quaternion.xyz.z + quaternion.xyz.y * quaternion.w));
		m_matrix[9]  = (float)(2.f *	   (quaternion.xyz.y * quaternion.xyz.z - quaternion.xyz.x * quaternion.w));
		m_matrix[10] = (float)(1.f - 2.f * (quaternion.xyz.x * quaternion.xyz.x + quaternion.xyz.y * quaternion.xyz.y));
		m_matrix[11] = 0.f;

		m_matrix[12] = 0.f;
		m_matrix[13] = 0.f;
		m_matrix[14] = 0.f;
		m_matrix[15] = 1.f;
	}
	//=============================================================
	inline Matrix(const Vector3<float>& xAxis, 
				  const Vector3<float>& yAxis, 
				  const Vector3<float>& zAxis)
	{
		m_matrix[0] = xAxis.x; m_matrix[4] = xAxis.y; m_matrix[8]  = xAxis.z; m_matrix[12] = 0.f;
		m_matrix[1] = yAxis.x; m_matrix[5] = yAxis.y; m_matrix[9]  = yAxis.z; m_matrix[13] = 0.f;
		m_matrix[2] = zAxis.x; m_matrix[6] = zAxis.y; m_matrix[10] = zAxis.z; m_matrix[14] = 0.f;
		m_matrix[3] = 0.f;	   m_matrix[7] = 0.f;	  m_matrix[11] = 0.f;	  m_matrix[15] = 1.f;
	}

public:

	//=============================================================
	inline float& operator[](const int index)
	{
		return m_matrix[index];
	}
	//=============================================================
	inline Matrix operator*(Matrix& second) const
	{
		Matrix result(*this);
		return (result *= second);
	}
	inline Matrix& operator*=(Matrix& second)
	{
		int count = 0;
		float rowFirst[4];
		float colSecond[4];
		Matrix result;

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

				result[count++] = rowFirst[0] * colSecond[0] +
								  rowFirst[1] * colSecond[1] +
								  rowFirst[2] * colSecond[2] +
								  rowFirst[3] * colSecond[3];
			}
		}
		*this = result;
		return *this;
	}
	//=============================================================
	inline Vector3<float> operator*(const Vector3<float>& second) const
	{
		int count = 0;
		float rowFirst[4];
		float tempResult[4];
		Vector3<float> result;

		for (int i = 0; i < 4; i++)
		{
			rowFirst[0] = m_matrix[i];
			rowFirst[1] = m_matrix[i + 4];
			rowFirst[2] = m_matrix[i + 8];
			rowFirst[3] = m_matrix[i + 12];

			tempResult[count++] = rowFirst[0] * second.x +
								  rowFirst[1] * second.y +
								  rowFirst[2] * second.z +
								  rowFirst[3];
		}

		result.x = tempResult[0];
		result.y = tempResult[1];
		result.z = tempResult[2];

		return result;
	}
  
private:

	//=============================================================
	inline float Minor(int row0, int row1, int row2, int col0, int col1, int col2)
	{
		return m_matrix[4 * row0 + col0] *
			  (m_matrix[4 * row1 + col1] * m_matrix[4 * row2 + col2] - m_matrix[4 * row2 + col1] * m_matrix[4 * row1 + col2]) -
			   m_matrix[4 * row0 + col1] *
			  (m_matrix[4 * row1 + col0] * m_matrix[4 * row2 + col2] - m_matrix[4 * row2 + col0] * m_matrix[4 * row1 + col2]) +
			   m_matrix[4 * row0 + col2] *
			  (m_matrix[4 * row1 + col0] * m_matrix[4 * row2 + col1] - m_matrix[4 * row2 + col0] * m_matrix[4 * row1 + col1]);
	}

public:

	//=============================================================
	inline Matrix Inverse()
	{
		const float determinant = 1.f / (m_matrix[0] * Minor(1, 2, 3, 1, 2, 3) - m_matrix[1] * Minor(1, 2, 3, 0, 2, 3) +
										 m_matrix[2] * Minor(1, 2, 3, 0, 1, 3) - m_matrix[3] * Minor(1, 2, 3, 0, 1, 2));
		Matrix result;

		result[0]  =  Minor(1, 2, 3, 1, 2, 3) * determinant;
		result[1]  = -Minor(0, 2, 3, 1, 2, 3) * determinant;
		result[2]  =  Minor(0, 1, 3, 1, 2, 3) * determinant;
		result[3]  = -Minor(0, 1, 2, 1, 2, 3) * determinant;
		result[4]  = -Minor(1, 2, 3, 0, 2, 3) * determinant;
		result[5]  =  Minor(0, 2, 3, 0, 2, 3) * determinant;
		result[6]  = -Minor(0, 1, 3, 0, 2, 3) * determinant;
		result[7]  =  Minor(0, 1, 2, 0, 2, 3) * determinant;
		result[8]  =  Minor(1, 2, 3, 0, 1, 3) * determinant;
		result[9]  = -Minor(0, 2, 3, 0, 1, 3) * determinant;
		result[10] =  Minor(0, 1, 3, 0, 1, 3) * determinant;
		result[11] = -Minor(0, 1, 2, 0, 1, 3) * determinant;
		result[12] = -Minor(1, 2, 3, 0, 1, 2) * determinant;
		result[13] =  Minor(0, 2, 3, 0, 1, 2) * determinant;
		result[14] = -Minor(0, 1, 3, 0, 1, 2) * determinant;
		result[15] =  Minor(0, 1, 2, 0, 1, 2) * determinant;

		return result;
	}
	inline Matrix Transpose()
	{
		Matrix result;

		result[0] = m_matrix[0];  result[4] = m_matrix[1];  result[8]  = m_matrix[2];  result[12] = m_matrix[3];
		result[1] = m_matrix[4];  result[5] = m_matrix[5];  result[9]  = m_matrix[6];  result[13] = m_matrix[7];
		result[2] = m_matrix[8];  result[6] = m_matrix[9];  result[10] = m_matrix[10]; result[14] = m_matrix[11];
		result[3] = m_matrix[12]; result[7] = m_matrix[13]; result[11] = m_matrix[14]; result[15] = m_matrix[15];

		return result;
	}

private:

	float m_matrix[16];
};

#endif