#include "ShaderGL.h"

bool ShaderGL::Create(const std::string& shader)
{
	if (m_programID == -1)
	{
		m_programID = glCreateProgram();

		if (m_programID == 0)
		{
			std::cout << "Shader program could not be created." << std::endl;
			std::cout << "===============================================================" << std::endl;
			return false;
		}
	}

	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	
	if (vertexShaderID == 0)
	{
		std::cout << "Vertex shader could not be created." << std::endl;
		std::cout << "===============================================================" << std::endl;
		return false;
	}

	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	if (fragmentShaderID == 0)
	{
		std::cout << "Fragment shader could not be created." << std::endl;
		std::cout << "===============================================================" << std::endl;
		return false;
	}

	CompileShaders(shader, vertexShaderID, fragmentShaderID);
}

bool ShaderGL::Attach(const std::string& shader)
{
	//TODO
	return true;
}

void ShaderGL::Detach()
{
	//TODO
}

void ShaderGL::Destroy()
{
	//TODO
}

GLint ShaderGL::GetUniformID(const std::string& uniform)
{
	auto it = m_uniforms.find(uniform);

	if (it != m_uniforms.end())
		return it->second;
		
	GLint ID = glGetUniformLocation(m_programID, uniform.c_str());

	if (ID != -1)
	{
		m_uniforms[uniform] = ID;
		std::cout << "Shader uniform '" + uniform + "' bound to program." << std::endl;
		std::cout << "===============================================================" << std::endl;
		return ID;		
	}

	std::cout << "Shader uniform '" + uniform + "' not found or inactive." << std::endl;
	std::cout << "===============================================================" << std::endl;
}

GLint ShaderGL::GetAttributeID(const std::string& attribute)
{
	auto it = m_attributes.find(attribute);

	if (it != m_attributes.end())
		return it->second;

	GLint ID = glGetAttribLocation(m_programID, attribute.c_str());

	if (ID != -1)
	{
		m_attributes[attribute] = ID;
		std::cout << "Shader attribute '" + attribute + "' bound to program." << std::endl;
		std::cout << "===============================================================" << std::endl;
		return ID;
	}

	std::cout << "Shader attribute '" + attribute + "' not found or inactive." << std::endl;
	std::cout << "===============================================================" << std::endl;
}

void ShaderGL::SendData(const Mesh& data)
{
	//TODO - Invoke data.Send();
}

void ShaderGL::SendData(const std::string& shaderID, int data)
{
	GLint ID = GetUniformID(shaderID);
	if (ID > -1) glUniform1i(ID, data);
}

void ShaderGL::SendData(const std::string& shaderID, float data)
{
	GLint ID = GetUniformID(shaderID);
	if (ID > -1) glUniform1f(ID, data);
}

void ShaderGL::SendData(const std::string& shaderID, Matrix& data)
{
	GLint ID = GetUniformID(shaderID);
	if (ID > -1) glUniformMatrix4fv(ID, 1, GL_FALSE, &data[0]);
}

void ShaderGL::SendData(const std::string& shaderID, unsigned int data)
{
	GLint ID = GetUniformID(shaderID);
	if (ID > -1) glUniform1ui(ID, data);
}

void ShaderGL::SendData(const std::string& shaderID, const Vector2<float>& data)
{
	GLint ID = GetUniformID(shaderID);
	if (ID > -1) glUniform2f(ID, data.x, data.y);
}

void ShaderGL::SendData(const std::string& shaderID, const Vector3<float>& data)
{
	GLint ID = GetUniformID(shaderID);
	if (ID > -1) glUniform3f(ID, data.x, data.y, data.z);
}

bool ShaderGL::CompileShaders(const std::string& shader, GLuint vertID, GLuint fragID)
{
	const int MAX_EXTENSIONS = 2;
	std::string fileExtensions[MAX_EXTENSIONS] = { "_vert.glsl", "_frag.glsl" };

	for (int i = 0; i < MAX_EXTENSIONS; i++)
	{
		std::fstream file;
		std::string lineText;
		std::string finalString;
		std::string filename = shader + fileExtensions[i];

		std::cout << "Opening and reading shader file '" + filename + "'" << std::endl;
		file.open(filename);

		if (!file)
		{
			std::cout << "Shader file could not be loaded." << std::endl;
			std::cout << "===============================================================" << std::endl;
			return false;
		}

		while (!file.eof())
		{
			getline(file, lineText);
			finalString += lineText + "\n";
		}

		file.close();

		GLint tempShaderID = 0;

		if (fileExtensions[i] == "_vert.glsl")
			tempShaderID = vertID;
		else if (fileExtensions[i] == "_frag.glsl")
			tempShaderID = fragID;
		
		const GLchar* finalCode = (const GLchar*)(finalString.c_str());

		std::cout << "Compiling shader file..." << std::endl;

		glShaderSource(tempShaderID, 1, &finalCode, nullptr);
		glCompileShader(tempShaderID);

		GLint compileResult;
		glGetShaderiv(tempShaderID, GL_COMPILE_STATUS, &compileResult);

		if (compileResult == GL_FALSE)
		{
			GLchar error[1000];
			GLsizei length = 1000;

			std::cout << "Shader file could not be compiled. See error list below." << std::endl;
			std::cout << "---------------------------------------------------------------" << std::endl;

			glGetShaderInfoLog(tempShaderID, 1000, &length, error);
			std::cout << error << std::endl;
			std::cout << "===============================================================" << std::endl;

			return false;
		}

		std::cout << "Shader file compiled successfully." << std::endl;
		std::cout << "===============================================================" << std::endl;
	}

	return true;
}

bool ShaderGL::LinkProgram()
{
	GLint linkResult = 0;

	glLinkProgram(m_programID);
	glUseProgram(m_programID);
	glGetProgramiv(m_programID, GL_LINK_STATUS, &linkResult);

	if (linkResult == GL_FALSE)
	{
		GLchar error[1000];
		GLsizei length = 1000;

		std::cout << "Shader program could not be linked. See error list below." << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;

		glGetProgramInfoLog(m_programID, 1000, &length, error);

		std::cout << error << std::endl;
		std::cout << "===============================================================" << std::endl;

		return false;
	}

	return true;
}