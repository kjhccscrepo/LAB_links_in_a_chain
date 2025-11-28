#pragma once
#include <string>
class Link {
private:
    std::string material;
public:
    Link(std::string material) {
        this->material = material;
    }
    std::string get_material() {
        return this->material;
    }
    bool operator==(const Link other) const {
        return this->material == other.material;
    }
};
