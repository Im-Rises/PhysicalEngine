#ifndef DEF_SHADER
#define DEF_SHADER

#include <glad/glad.h>
#include <string>

class Shader {
private:
    unsigned int ID;

public:
    Shader(const GLchar *vertexPath, const GLchar *fragmentPath);

    ~Shader();

    void use();

    void setFloat(const std::string &name, float value) const;
};


#endif //DEF_SHADER
