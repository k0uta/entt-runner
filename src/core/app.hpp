#ifndef ENTT_RUNNER_APP_HPP
#define ENTT_RUNNER_APP_HPP


class App {
public:
    const char*appName = "EnTT Runner";

    int width = 1280;

    int height = 720;

    float fps = 60.f;

    void run();
};


#endif //ENTT_RUNNER_APP_HPP
