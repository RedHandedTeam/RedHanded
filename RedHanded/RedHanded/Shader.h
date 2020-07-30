#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader
{

public:

	virtual ~Shader() = 0 {}

public:

	virtual bool Create(const std::string filename) = 0;
	virtual bool Attach() = 0;
	virtual void Detach() = 0;
	virtual void Destroy() = 0;

public:

	//virtual void SendData(const Mesh& data) = 0;
	//virtual void SendData(const std::string& shaderID, int data) = 0;
	//virtual void SendData(const std::string& shaderID, float data) = 0;
	//virtual void SendData(const std::string& shaderID, unsigned int data) = 0;
	////virtual void SendData(const std::string& shaderID, const Matrix& data) = 0;
	//virtual void SendData(const std::string& shaderID, const Vector2<float>& data) = 0;
	//virtual void SendData(const std::string& shaderID, const Vector3<float>& data) = 0;
	//TODO - add a function to send a Texture object

};

#endif