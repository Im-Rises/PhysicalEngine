#ifndef DEFAULTCOMPONENT_H
#define DEFAULTCOMPONENT_H

#include <string>

class DefaultComponent {
public:
    virtual void drawGui() = 0;

    virtual std::string getName() const = 0;

};


#endif //DEFAULTCOMPONENT_H
