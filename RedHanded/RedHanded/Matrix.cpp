#include <algorithm>
#include <iomanip>
#include <iostream>
#include "Matrix3D.h"
#include "Matrix4D.h"

//------------------------------------------------------------------------------------------------------
//constructor that sets the identity matrix as a default using =operator function
//------------------------------------------------------------------------------------------------------
Matrix4D::Matrix4D()
{

	*this = IDENTITY;

}
//------------------------------------------------------------------------------------------------------
//second constructor that assigns an array to Matrix object using =operator function
//------------------------------------------------------------------------------------------------------
Matrix4D::Matrix4D(const float* rhs)
{

	*this = rhs;

}
//------------------------------------------------------------------------------------------------------
//getter function that returns internal matrix array  
//------------------------------------------------------------------------------------------------------
float* Matrix4D::GetMatrixArray()
{

	return m_matrix;

}
//------------------------------------------------------------------------------------------------------
//function that returns an index reference of Matrix object's inner array based on index passed
//------------------------------------------------------------------------------------------------------
float& Matrix4D::operator[](const int index)
{

	return m_matrix[index];

}
//------------------------------------------------------------------------------------------------------
//function that assigns an array to Matrix object
//------------------------------------------------------------------------------------------------------
Matrix4D& Matrix4D::operator=(const float* rhs)
{

	//loop through each element in rhs array
	//and assign each to Matrix object's array
	for (int i = 0; i < 16; i++)
	{
		m_matrix[i] = rhs[i];
	}

	//return a reference of the matrix object so that 
	//assignment chaining can be used as well
	return *this;

}
//------------------------------------------------------------------------------------------------------
//function that assigns a value to a Matrix object based on matrix enum type passed
//------------------------------------------------------------------------------------------------------
Matrix4D& Matrix4D::operator=(const MATRIX_TYPE rhs)
{

	switch (rhs)
	{
		//if value passed is IDENTITY, 
		//then make an identity matrix
		case IDENTITY:
		{
			//first set all elements to 0
			for (int i = 0; i < 16; i++)
			{
				m_matrix[i] = 0.0f;
			}

			//then set the major diagonal to 1
			m_matrix[0] = 1.0f;
			m_matrix[5] = 1.0f;
			m_matrix[10] = 1.0f;
			m_matrix[15] = 1.0f;

			break;
		}

	}

	//return a reference of the matrix object so that 
	//assignment chaining can be used as well
	return *this;

}
//------------------------------------------------------------------------------------------------------
//function that multiplies two Matrix objects together
//------------------------------------------------------------------------------------------------------
Matrix4D& Matrix4D::operator*(Matrix4D& rhs)
{

	//variable to keep track of each matrix element of final result
	int count = 0;
	
	//the final matrix result object and two Vector4D objects 
	//are needed to calculate each row and column multiplication
	Matrix4D result;
	glm::vec4 leftRow;
	glm::vec4 topColumn;
	
	//loop through each of the top matrix columns
	for(int i = 0; i < 4; i++)
	{

		//assign the elements from top to bottom 
		topColumn.x = rhs[i * 4];
		topColumn.y = rhs[i * 4 + 1];
		topColumn.z = rhs[i * 4 + 2];
		topColumn.w = rhs[i * 4 + 3];

		//loop through each of the left matrix rows
		for(int j = 0; j < 4; j++)
		{

			//assign the elements from left to right 
			leftRow.x = m_matrix[j];
			leftRow.y = m_matrix[j + 4];
			leftRow.z = m_matrix[j + 8];
			leftRow.w = m_matrix[j + 12];
						
			//use dot product to produce each matrix element result
			result[count++] = glm::dot(leftRow, topColumn);

		}

	}

	//assign result to Matrix object and return reference
	//of lhs matrix to allow for multiplication chaining
	return (*this = result);

}
//------------------------------------------------------------------------------------------------------
//function that multiplies a Matrix object by a value
//------------------------------------------------------------------------------------------------------
Matrix4D& Matrix4D::operator*(const float rhs)
{

	//loop through each element in 
	//inner matrix array and multiply by rhs value
	for (int i = 0; i < 16; i++)
	{
		m_matrix[i] *= rhs;
	}

	//return a reference of the matrix object so that 
	//multiplication chaining can be used as well
	return *this;

}
//------------------------------------------------------------------------------------------------------
//function that multiplies a Matrix object by a Vector2D object
//------------------------------------------------------------------------------------------------------
glm::vec2 Matrix4D::operator*(const glm::vec2& rhs)
{

	//variables for final result 
	//and temp homogeneous vector 
	glm::vec2 result;
	glm::vec4 homogeneous;

	//convert 2D vector to 4D homogeneous vector 
	//so that we can multiply matrix by 4D vector  
	homogeneous.x = rhs.x;
	homogeneous.y = rhs.y;
	homogeneous.z = 0;
	homogeneous.w = 1;

	//multiply Matrix object by Vector4D object 
	homogeneous = (*this) * homogeneous;

	//convert 4D homogeneous vector back to 2D vector
	result.x = homogeneous.x / homogeneous.w;
	result.y = homogeneous.y / homogeneous.w;

	return result;

}
//------------------------------------------------------------------------------------------------------
//function that multiplies a Matrix object by a Vector3D object
//------------------------------------------------------------------------------------------------------
glm::vec3 Matrix4D::operator*(const glm::vec3& rhs)
{

	//variables for final result 
	//and temp homogeneous vector 
	glm::vec3 result;
	glm::vec4 homogeneous;

	//convert 3D vector to 4D homogeneous vector 
	//so that we can multiply matrix by 4D vector  
	homogeneous.x = rhs.x;
	homogeneous.y = rhs.y;
	homogeneous.z = rhs.z;
	homogeneous.w = 1;

	//multiply Matrix object by Vector4D object 
	homogeneous = (*this) * homogeneous;

	//convert 4D homogeneous vector back to 3D vector
	result.x = homogeneous.x / homogeneous.w;
	result.y = homogeneous.y / homogeneous.w;
	result.z = homogeneous.z / homogeneous.w;

	return result;

}
//------------------------------------------------------------------------------------------------------
//function that multiplies a Matrix object by a Vector4D object
//------------------------------------------------------------------------------------------------------
glm::vec4 Matrix4D::operator*(const glm::vec4& rhs)
{

	//temp result to be stored in a float array instead of a 
	//4D vector because the array can then be used inside a loop 
	float tempResult[4]; 
	
	//variables for final result 
	//and temp matrix row 
	glm::vec4 result;
	glm::vec4 matrixRow;
	
	//loop through each of the left matrix rows
	for(int i = 0; i < 4; i++)
	{

		//assign the elements from left to right
		matrixRow.x = m_matrix[i];
		matrixRow.y = m_matrix[i + 4];
		matrixRow.z = m_matrix[i + 8];
		matrixRow.w = m_matrix[i + 12];
						
		//use dot product to produce each vector element result
		tempResult[i] = glm::dot(matrixRow, rhs);

	}

	//assign each temp result array element to Vector4D object 
	result.x = tempResult[0];
	result.y = tempResult[1];
	result.z = tempResult[2];
	result.w = tempResult[3];

	return result;

}
//------------------------------------------------------------------------------------------------------
//function that displays Matrix object on console window
//this is for DEBUG only
//------------------------------------------------------------------------------------------------------
void Matrix4D::Output()
{

	//clear the console window screen
	system("cls");

	//assign flags to left align numbers correctly in their columns, 
	//and display them in floating point format with a two decimal point precision
	std::cout << std::left << std::fixed << std::setprecision(2) << std::endl;

	//loop through all 16 elements of inner array and
	//position and display values on screen
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << std::setw(5) << "[" << std::setw(7)
				      << m_matrix[i + (j * 4)] << "]" << std::setw(5) << " ";
		}

		std::cout << std::endl << std::endl;
	}

}
//------------------------------------------------------------------------------------------------------
//function that calculates the inverse of a Matrix object
//the formula for this has been extracted from this website :
//http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
//------------------------------------------------------------------------------------------------------
Matrix4D Matrix4D::Inverse()
{

	//variables for determinant and temp float array
	float determinant = 0;
	float tempArray[9] = {0};

	//result matrix to store final result and 
	//temp 3x3 matrix to be used to calculate determinant
	Matrix4D result;
	Matrix3D tempMatrix3D;
	
	//temp 3x3 matrices used to store four particular 
	//matrices and calculate final determinant value 
	Matrix3D matrix_1;
	Matrix3D matrix_2;
	Matrix3D matrix_3;
	Matrix3D matrix_4;

	//the first step is to calculate the matrix of minors
	//this is a loooong calculation that basically loops through 
	//each of the 16 matrix elements and calculates the determinant 
	//of the remaining 3x3 matrices formed. The determinant is then 
	//stored in each element of the result matrix
	
	//---------------
	//Matrix Column 1 
	//---------------

	//matrix element 0
	tempArray[0] = m_matrix[5]; tempArray[1] = m_matrix[6]; tempArray[2] = m_matrix[7]; 
	tempArray[3] = m_matrix[9]; tempArray[4] = m_matrix[10]; tempArray[5] = m_matrix[11];
	tempArray[6] = m_matrix[13]; tempArray[7] = m_matrix[14]; tempArray[8] = m_matrix[15];

	tempMatrix3D = tempArray;
	result[0] = tempMatrix3D.Determinant();

	//store this 3x3 matrix for determinant calculation later on
	matrix_1 = tempArray;

	//matrix element 1
	tempArray[0] = m_matrix[4]; tempArray[1] = m_matrix[6]; tempArray[2] = m_matrix[7];
	tempArray[3] = m_matrix[8]; tempArray[4] = m_matrix[10]; tempArray[5] = m_matrix[11];
	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[14]; tempArray[8] = m_matrix[15];

	tempMatrix3D = tempArray;
	result[1] = tempMatrix3D.Determinant();

	//matrix element 2
	tempArray[0] = m_matrix[4]; tempArray[1] = m_matrix[5]; tempArray[2] = m_matrix[7];
	tempArray[3] = m_matrix[8]; tempArray[4] = m_matrix[9]; tempArray[5] = m_matrix[11];
	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[13]; tempArray[8] = m_matrix[15];

	tempMatrix3D = tempArray;
	result[2] = tempMatrix3D.Determinant();

	//matrix element 3
	tempArray[0] = m_matrix[4]; tempArray[1] = m_matrix[5]; tempArray[2] = m_matrix[6];
	tempArray[3] = m_matrix[8]; tempArray[4] = m_matrix[9]; tempArray[5] = m_matrix[10];
	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[13]; tempArray[8] = m_matrix[14];

	tempMatrix3D = tempArray;
	result[3] = tempMatrix3D.Determinant();

	//---------------
	//Matrix Column 2 
	//---------------

	//matrix element 4
	tempArray[0] = m_matrix[1]; tempArray[1] = m_matrix[2]; tempArray[2] = m_matrix[3];
	tempArray[3] = m_matrix[9]; tempArray[4] = m_matrix[10]; tempArray[5] = m_matrix[11];
	tempArray[6] = m_matrix[13]; tempArray[7] = m_matrix[14]; tempArray[8] = m_matrix[15];

	tempMatrix3D = tempArray;
	result[4] = tempMatrix3D.Determinant();

	//store this 3x3 matrix for determinant calculation later on
	matrix_2 = tempArray;

	//matrix element 5
	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[2]; tempArray[2] = m_matrix[3];
	tempArray[3] = m_matrix[8]; tempArray[4] = m_matrix[10]; tempArray[5] = m_matrix[11];
	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[14]; tempArray[8] = m_matrix[15];

	tempMatrix3D = tempArray;
	result[5] = tempMatrix3D.Determinant();

	//matrix element 6
	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[1]; tempArray[2] = m_matrix[3];
	tempArray[3] = m_matrix[8]; tempArray[4] = m_matrix[9]; tempArray[5] = m_matrix[11];
	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[13]; tempArray[8] = m_matrix[15];

	tempMatrix3D = tempArray;
	result[6] = tempMatrix3D.Determinant();

	//matrix element 7
	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[1]; tempArray[2] = m_matrix[2];
	tempArray[3] = m_matrix[8]; tempArray[4] = m_matrix[9]; tempArray[5] = m_matrix[10];
	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[13]; tempArray[8] = m_matrix[14];

	tempMatrix3D = tempArray;
	result[7] = tempMatrix3D.Determinant();

	//---------------
	//Matrix Column 3 
	//---------------

	//matrix element 8
	tempArray[0] = m_matrix[1]; tempArray[1] = m_matrix[2]; tempArray[2] = m_matrix[3];
	tempArray[3] = m_matrix[5]; tempArray[4] = m_matrix[6]; tempArray[5] = m_matrix[7];
	tempArray[6] = m_matrix[13]; tempArray[7] = m_matrix[14]; tempArray[8] = m_matrix[15];

	tempMatrix3D = tempArray;
	result[8] = tempMatrix3D.Determinant();

	//store this 3x3 matrix for determinant calculation later on
	matrix_3 = tempArray;

	//matrix element 9
	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[2]; tempArray[2] = m_matrix[3];
	tempArray[3] = m_matrix[4]; tempArray[4] = m_matrix[6]; tempArray[5] = m_matrix[7];
	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[14]; tempArray[8] = m_matrix[15];

	tempMatrix3D = tempArray;
	result[9] = tempMatrix3D.Determinant();

	//matrix element 10
	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[1]; tempArray[2] = m_matrix[3];
	tempArray[3] = m_matrix[4]; tempArray[4] = m_matrix[5]; tempArray[5] = m_matrix[7];
	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[13]; tempArray[8] = m_matrix[15];

	tempMatrix3D = tempArray;
	result[10] = tempMatrix3D.Determinant();

	//matrix element 11
	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[1]; tempArray[2] = m_matrix[2];
	tempArray[3] = m_matrix[4]; tempArray[4] = m_matrix[5]; tempArray[5] = m_matrix[6];
	tempArray[6] = m_matrix[12]; tempArray[7] = m_matrix[13]; tempArray[8] = m_matrix[14];

	tempMatrix3D = tempArray;
	result[11] = tempMatrix3D.Determinant();

	//---------------
	//Matrix Column 4 
	//---------------

	//matrix element 12
	tempArray[0] = m_matrix[1]; tempArray[1] = m_matrix[2]; tempArray[2] = m_matrix[3];
	tempArray[3] = m_matrix[5]; tempArray[4] = m_matrix[6]; tempArray[5] = m_matrix[7];
	tempArray[6] = m_matrix[9]; tempArray[7] = m_matrix[10]; tempArray[8] = m_matrix[11];

	tempMatrix3D = tempArray;
	result[12] = tempMatrix3D.Determinant();

	//store this 3x3 matrix for determinant calculation later on
	matrix_4 = tempArray;

	//matrix element 13
	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[2]; tempArray[2] = m_matrix[3];
	tempArray[3] = m_matrix[4]; tempArray[4] = m_matrix[6]; tempArray[5] = m_matrix[7];
	tempArray[6] = m_matrix[8]; tempArray[7] = m_matrix[10]; tempArray[8] = m_matrix[11];

	tempMatrix3D = tempArray;
	result[13] = tempMatrix3D.Determinant();

	//matrix element 14
	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[1]; tempArray[2] = m_matrix[3];
	tempArray[3] = m_matrix[4]; tempArray[4] = m_matrix[5]; tempArray[5] = m_matrix[7];
	tempArray[6] = m_matrix[8]; tempArray[7] = m_matrix[9]; tempArray[8] = m_matrix[11];

	tempMatrix3D = tempArray;
	result[14] = tempMatrix3D.Determinant();

	//matrix element 15
	tempArray[0] = m_matrix[0]; tempArray[1] = m_matrix[1]; tempArray[2] = m_matrix[2];
	tempArray[3] = m_matrix[4]; tempArray[4] = m_matrix[5]; tempArray[5] = m_matrix[6];
	tempArray[6] = m_matrix[8]; tempArray[7] = m_matrix[9]; tempArray[8] = m_matrix[10];

	tempMatrix3D = tempArray;
	result[15] = tempMatrix3D.Determinant();

	//the next step is to calculate the matrix of cofactors
	//this applies a checkerboard of + and - symbols in a specific 
	//sequence to each matrix element. All that needs to be done is 
	//apply the - values, as the positive numbers remain the same 
	result[1] *= -1;
	result[3] *= -1;
	result[4] *= -1;
	result[6] *= -1;
	result[9] *= -1;
	result[11] *= -1;
	result[12] *= -1;
	result[14] *= -1;

	//next is to calculate the adjugate
	//this merely means to flip the matrix along the major diagonal
	std::swap(result[4], result[1]);
	std::swap(result[2], result[8]);
	std::swap(result[6], result[9]);
	std::swap(result[12], result[3]);
	std::swap(result[13], result[7]);
	std::swap(result[14], result[11]);
	
	//the final calculation is to find the determinant of the original matrix
	//using a formula that uses the four temporary 3x3 matrices stored earlier
	determinant = m_matrix[0] * matrix_1.Determinant() - m_matrix[4] * matrix_2.Determinant() +
		          m_matrix[8] * matrix_3.Determinant() - m_matrix[12] * matrix_4.Determinant();

	//only if the determinant is not 0
	//then multiply the result matrix by 1/det
	if (determinant != 0)
	{
		return (result * (1.0f / determinant));
	}

	//otherwise return original matrix as we
	//cannot find the inverse
	return *this;

}