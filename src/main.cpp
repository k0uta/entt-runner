#include <bits/exception.h>
#include <iostream>
#include "core/app.hpp"

int main() {
    try {
        auto app = new App();
        app->run();
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
        return 1;
    }
    return 0;
}