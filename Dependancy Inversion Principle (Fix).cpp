#include <iostream>

class Switchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class Light : public Switchable {
public:
    void turnOn() override { std::cout << "Light turned on.\n"; }
    void turnOff() override { std::cout << "Light turned off.\n"; }
};

class Switch {
private:
    Switchable& device;
    bool state;
public:
    Switch(Switchable& dev) : device(dev), state(false) {}
    void toggle() {
        state = !state;
        if (state) {
            device.turnOn();
        } else {
            device.turnOff();
        }
    }
};

int main() {
    Light light;
    Switch lightSwitch(light);
    lightSwitch.toggle();
    lightSwitch.toggle();
    return 0;
}
