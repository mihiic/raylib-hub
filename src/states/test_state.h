#ifndef TEST_STATE_H
#define TEST_STATE_H

#include "../state_handler/state.h"

class TestState : public State {
public:
    TestState();
    ~TestState();

    void render();
    void update();
};

#endif