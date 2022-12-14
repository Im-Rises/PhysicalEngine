#include "Shader.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "glad/glad.h"

// Thanks to:
// https://opengl.developpez.com/tutoriels/apprendre-opengl/?page=les-shaders#L7-1-3

Shader::Shader() {
    const char* vShaderCode = "#version 330 core\n"
                              "layout (location = 0) in vec3 aPos;\n"
                              "\n"
                              "uniform mat4 model;\n"
                              "uniform mat4 view;\n"
                              "uniform mat4 projection;\n"
                              "uniform vec4 color;\n"
                              "out vec4 ourColor;\n"
                              "\n"
                             // "uniform vec3 pos_lumiere;\n"
                              //"varying vec3 _d;\n"
                              //"varying vec3 _n;\n"
                              "void main()\n"
                              "{\n"
                              "    gl_Position = projection * view * model * vec4(aPos, 1.0f);\n" 
                              //"    vec4 tpos = model * vec4(apos, 1.0);\n"
                              //"    vec3 _pos = tpos.xyz / tpos.w;\n"
                              //"    _d = pos_lumiere - _pos;\n" 
                              //"    _n = normalMatrix * normal;\n"
                              "    ourColor = color;\n"
                              "}\0";

    const char* fShaderCode = "#version 330 core\n"
                              "in vec4 ourColor;\n"
                              "out vec4 FragColor;\n"
                              "\n"
                              "void main()\n"
                              "{\n"
                              "    FragColor = ourColor;\n"
                              "}\0";

    create(vShaderCode, fShaderCode);
}

Shader::Shader(const char* vertexPathOrCode, const char* fragmentPathOrCode, const bool isDirectCode) {
    if (!isDirectCode)
    {
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;

        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            vShaderFile.open(vertexPathOrCode);
            fShaderFile.open(fragmentPathOrCode);
            std::stringstream vShaderStream, fShaderStream;

            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();

            vShaderFile.close();
            fShaderFile.close();

            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << e.what() << std::endl;
        }
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();

        create(vShaderCode, fShaderCode);
    }
    else
    {
        create(vertexPathOrCode, fragmentPathOrCode);
    }
}

void Shader::create(const char* vShaderCode, const char* fShaderCode) {
    unsigned int vertex, fragment;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}


void Shader::checkCompileErrors(unsigned int shader, const std::string& type) {
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n"
                      << infoLog
                      << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n"
                      << infoLog
                      << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}

Shader::~Shader() {
    destroy();
}

void Shader::destroy() {
    glDeleteProgram(ID);
}

void Shader::use() {
    glUseProgram(ID);
}

void Shader::setBool(const std::string& name, bool value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setVec2(const std::string& name, const glm::vec2& value) const {
    glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::setVec2(const std::string& name, float x, float y) const {
    glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
}

void Shader::setVec3(const std::string& name, const glm::vec3& value) const {
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::setVec3(const std::string& name, float x, float y, float z) const {
    glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
}

void Shader::setVec4(const std::string& name, const glm::vec4& value) const {
    glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::setVec4(const std::string& name, float x, float y, float z, float w) const {
    glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
}

void Shader::setMat2(const std::string& name, const glm::mat2& mat) const {
    glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat3(const std::string& name, const glm::mat3& mat) const {
    glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat4(const std::string& name, const glm::mat4& mat) const {
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

unsigned int Shader::getId() const {
    return ID;
}
