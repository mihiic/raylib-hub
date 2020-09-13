#pragma once
#include "state.h"

class StateManager {
public:
    ~StateManager();

    void update();
    void render();

    void setState(State* state);
    StateManager* getInstance() {
        if (!_instance) {
            _instance = new StateManager();
        }

        return _instance;
    }

protected:
    StateManager();

    State* current_state;
    static StateManager* _instance;
};
