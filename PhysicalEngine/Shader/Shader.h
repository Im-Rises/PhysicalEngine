#ifndef SHADER_H
#define SHADER_H

#include <string>

// GLM
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


class Shader {
private:
    const char *vertexShader = "#version 330 core\n"
                               "layout (location = 0) in vec3 aPos;\n"
                               "\n"
                               "uniform mat4 model;\n"
                               "uniform mat4 view;\n"
                               "uniform mat4 projection;\n"
                               "\n"
                               "void main()\n"
                               "{\n"
                               "    gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
                               "}\0";
    
    const char *fragmentShader = "#version 330 core\n"
                                 "out vec4 FragColor;\n"
                                 "\n"
                                 "void main()\n"
                                 "{\n"
                                 "    FragColor = vec4(1.0f, 0.5f, 0.5f, 1.0f);\n"
                                 "}\0";
    unsigned int ID;

public:
    Shader(const char *vertexPath, const char *fragmentPath);

    ~Shader();

    void use();

    void setBool(const std::string &name, bool value) const;

    void setInt(const std::string &name, int value) const;

    void setFloat(const std::string &name, float value) const;

    unsigned int getId() const;

    void setVec2(const std::string &name, float x, float y) const;

    void setVec3(const std::string &name, float x, float y, float z) const;

    void setVec4(const std::string &name, float x, float y, float z, float w) const;

    void setVec2(const std::string &name, const glm::vec2 &value) const;

    void setVec3(const std::string &name, const glm::vec3 &value) const;

    void setVec4(const std::string &name, const glm::vec4 &value) const;

    void setMat2(const std::string &name, const glm::mat2 &mat) const;

    void setMat3(const std::string &name, const glm::mat3 &mat) const;

    void setMat4(const std::string &name, const glm::mat4 &mat) const;
};


#endif //SHADER_H
