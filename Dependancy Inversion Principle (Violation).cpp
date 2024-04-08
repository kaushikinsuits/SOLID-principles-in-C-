#include <iostream>

class Light {
public:
    void turnOn() { std::cout << "Light turned on.\n"; }
    void turnOff() { std::cout << "Light turned off.\n"; }
};

class Switch {
private:
    Light light;
    bool state;
public:
    Switch() : state(false) {}
    void toggle() {
        state = !state;
        if (state) {
            light.turnOn();
        } else {
            light.turnOff();
        }
    }
};

int main() {
    Switch lightSwitch;
    lightSwitch.toggle();
    lightSwitch.toggle();
    return 0;
}
