#ifndef DEFAULTCOMPONENT_H
#define DEFAULTCOMPONENT_H

#include <string>

class DefaultComponent {
public:
    virtual void drawGui() = 0;

    [[nodiscard]] virtual auto getName() const -> std::string = 0;

};


#endif //DEFAULTCOMPONENT_H
