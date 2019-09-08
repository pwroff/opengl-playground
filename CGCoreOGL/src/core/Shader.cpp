#include "core/Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

Shader::Shader(std::vector<ShaderBit>& shaderBits)
{
	std::vector<uint> compiledBits;
	// shader Program
	ID = glCreateProgram();
	
	for (size_t i = 0; i < shaderBits.size(); i++)
	{
		uint b;
		if (loadSource(shaderBits[i], b))
		{
			glAttachShader(ID, b);
			compiledBits.push_back(b);
		}
	}

	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAM");
	for (size_t i = 0; i < compiledBits.size(); i++)
	{
		glDeleteShader(compiledBits[i]);
	}
}

bool Shader::checkCompileErrors(unsigned int shader, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	return success;
}

bool Shader::loadSource(ShaderBit & sb, uint &id)
{
	static map<string, uint> loadedShaderBits;
	if (loadedShaderBits.find(sb.path) != loadedShaderBits.end())
	{
		id = loadedShaderBits[sb.path];
		return true;
	}
	std::string vertexCode;
	std::ifstream vShaderFile;
	// ensure ifstream objects can throw exceptions:
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files
		vShaderFile.open(sb.path);
		std::stringstream vShaderStream;
		// read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		// close file handlers
		vShaderFile.close();
		// convert stream into string
		vertexCode = vShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ at path: " << sb.path << "\n";
		std::cout << e.what() << std::endl;
		return false;
	}
	const char* vShaderCode = vertexCode.c_str();
	// 2. compile shaders
	// vertex shader
	id = glCreateShader(sb.type);
	glShaderSource(id, 1, &vShaderCode, NULL);
	glCompileShader(id);
	if (checkCompileErrors(id, "Shader bit"))
	{
		cout << "Successfully compiled shader: " << sb.path << "\n";
		loadedShaderBits[sb.path] = id;
		return true;
	}
	return false;
}
