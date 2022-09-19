#ifndef DEF_TRIANGLE_H
#define DEF_TRIANGLE_H

#include "../Shader/Shader.h"

namespace drg {

    class Triangle {
    private:
        Shader shader;
        unsigned int VBO, VAO;
    public:
        Triangle();

        ~Triangle();

        void use();

    };
}
#endif //DEF_TRIANGLE_H
