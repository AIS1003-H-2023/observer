
#include "threepp/threepp.hpp"

#include "Car.hpp"

using namespace threepp;

namespace {

    struct CarKeyListener: KeyListener {

        explicit CarKeyListener(Car& car): car(car) {}

        void onKeyPressed(KeyEvent evt) override {

            if (evt.key == threepp::Key::W) {
                car.drive(Car::Direction::FORWARD);
            } else if (evt.key == threepp::Key::S) {
                car.drive(Car::Direction::BACKWARDS);
            }
        }

    private:
        Car& car;
    };

    struct CarObserver: Observer {

        explicit CarObserver(Mesh& carMesh): carMesh(carMesh) {}

        void onChanged(const Car& car) override {

            carMesh.position.copy(car.position());
        }

    private:
        Mesh& carMesh;
    };

}// namespace

int main() {

    Canvas canvas("Car demo", {{"aa", 4}});
    GLRenderer renderer(canvas.size());
    renderer.setClearColor(Color::aliceblue);

    auto camera = PerspectiveCamera::create();
    camera->position.z = 5;

    OrbitControls controls{*camera, canvas};

    auto scene = Scene::create();

    Vector3 size{1, 0.5, 2};
    Car car({0, 0, 0}, size, 1);

    CarKeyListener listener(car);
    canvas.addKeyListener(&listener);

    auto geometry = BoxGeometry::create(size.x, size.y, size.z);
    auto material = MeshBasicMaterial::create();
    material->color = Color::red;

    auto carMesh = Mesh::create(geometry, material);
    scene->add(carMesh);

    CarObserver carObserver(*carMesh);
    car.addObserver(&carObserver);

    Clock clock;
    canvas.animate([&] {

        // we could do polling as an alternative to the Observer pattern:
        // carMesh.position.copy(car.position()); // but this updates more often than necessary.

        renderer.render(*scene, *camera);
    });
}
