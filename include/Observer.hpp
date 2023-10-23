
#ifndef THREEPP_VCPKG_DEMO_OBSERVER_HPP
#define THREEPP_VCPKG_DEMO_OBSERVER_HPP

//forward declaration (needed due to cyclic relationship)
class Car;

class Observer {

public:
    virtual void onChanged(const Car& car) = 0;
};

#endif
