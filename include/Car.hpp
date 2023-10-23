
#ifndef THREEPP_VCPKG_DEMO_CAR_HPP
#define THREEPP_VCPKG_DEMO_CAR_HPP

#include "Observer.hpp"
#include "threepp/math/Vector3.hpp"

#include <vector>

// Just some class demonstrating that the Model can (should be) be decoupled from the visualisation.
class Car {

public:
    enum class Direction {
        FORWARD,
        BACKWARDS
    };

    Car(const threepp::Vector3& initialPos, const threepp::Vector3& size, float maxSpeed)
        : position_(initialPos), size_(size), maxSpeed_(maxSpeed) {}

    threepp::Vector3 size() const {
        return size_;
    }

    threepp::Vector3 position() const {
        return position_;
    }

    void drive(Direction dir) {
        switch (dir) {
            case Direction::FORWARD: {
                position_.z += maxSpeed_;
            } break;
            case Direction::BACKWARDS: {
                position_.z -= maxSpeed_;
            }
        }

        for (auto& observer : observers_) {

            observer->onChanged(*this);
        }
    }

    void addObserver(Observer* observer) {

        observers_.emplace_back(observer);
    }

private:
    float maxSpeed_;
    threepp::Vector3 size_;
    threepp::Vector3 position_;

    std::vector<Observer*> observers_; // non-owning list of observers
};

#endif//THREEPP_VCPKG_DEMO_CAR_HPP
