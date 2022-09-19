#ifndef DEF_RECTANGLE
#define DEF_RECTANGLE

#include "../Shader/Shader.h"

namespace drg {

    class Square {
    private:
        unsigned int VBO, VAO, EBO;
        Shader shader;

    public:
        Square();

        ~Square();

        void use();
    };

}

#endif //DEF_RECTANGLE
