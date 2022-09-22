#ifndef DEF_MESH
#define DEF_MESH


#include <vector>

class Mesh {

private:
    unsigned int VAO, VBO, EBO;
    std::vector<float> vertices;
//    struct {
//        float x, y, z;
//    } position;

public:
    Mesh();

    ~Mesh();

};


#endif //DEF_MESH
