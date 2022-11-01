#ifndef PARTICLEGENERATOR_H
#define PARTICLEGENERATOR_H

#define PARTICLES_COUNT 500

// https://learnopengl.com/Advanced-OpenGL/Instancing
// Not usefully here, but maybe later

class ParticleGenerator {
private:
    //    static unsigned int idCounter;
    unsigned int instanceVBO;

public:
    ParticleGenerator();
    ~ParticleGenerator();
};



#endif // PARTICLEGENERATOR_H
