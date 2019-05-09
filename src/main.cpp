#include <bits/exception.h>
#include <iostream>
#include "core/app.hpp"

int main() {
    auto app = new App();
    try {
        app->run();
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
        return 1;
    }
    delete(app);

    return 0;
}