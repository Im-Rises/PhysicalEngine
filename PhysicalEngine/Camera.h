#ifndef DEF_CAMERA
#define DEF_CAMERA


class Camera {
private:
    float x, y, z;
    float rotationX, rotationY, rotationZ;
    float scaleX, scaleY, scaleZ;
    float colorR, colorG, colorB, colorA;

public:
    Camera();

    ~Camera();

    void update();

    void rotate();

    void translate();
};


#endif //DEF_CAMERA
