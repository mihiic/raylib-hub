#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "state.h"

class StateManager {
public:
    ~StateManager();

    void update();
    void render();

    void setState(State* state);
    static StateManager* getInstance();

protected:
    StateManager();

    State* current_state;
    static StateManager* _instance;
};

#endif