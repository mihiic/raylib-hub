#include "state_manager.h"

StateManager* StateManager::_instance = nullptr;

StateManager::StateManager() {
    this->current_state = nullptr;
}

StateManager::~StateManager() {
}

void StateManager::update() {
    if (this->current_state != nullptr) {
        this->current_state->update();
    }
}

void StateManager::render() {
    if (this->current_state != nullptr) {
        this->current_state->render();
    }
}

void StateManager::setState(State* state) {
    this->current_state = state;
}

StateManager* StateManager::getInstance() {
    if (_instance == nullptr) {
        _instance = new StateManager();
    }

    return _instance;
}
