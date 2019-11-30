#ifndef SHADER_GL_H
#define SHADER_GL_H

#include "Shader.h"

class ShaderGL : public Shader
{

public:

	virtual bool Create(const std::string& shader);
	virtual bool Attach(const std::string& shader);
	virtual void Detach();
	virtual void Destroy();

private:

	GLint GetUniformID(const std::string& uniform);
	GLint GetAttributeID(const std::string& attribute);

public:

	virtual void SendData(const Mesh& data);
	virtual void SendData(const std::string& shaderID, int data);
	virtual void SendData(const std::string& shaderID, float data);
	virtual void SendData(const std::string& shaderID, Matrix& data);
	virtual void SendData(const std::string& shaderID, unsigned int data);
	virtual void SendData(const std::string& shaderID, const Vector2<float>& data);
	virtual void SendData(const std::string& shaderID, const Vector3<float>& data);

private:

	bool CompileShaders(const std::string& shader, GLuint vertID, GLuint fragID);
	bool LinkProgram();

private:

	GLuint m_programID;

	std::map<std::string, GLuint> m_uniforms;
	std::map<std::string, GLuint> m_attributes;
	std::map<std::string, std::pair<GLuint, GLuint>> m_shaders;

};

#endif