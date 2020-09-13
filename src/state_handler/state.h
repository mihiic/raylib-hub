#pragma once

class State {
public:
    State();
    ~State();

    virtual void update() = 0;
    virtual void render() = 0;

private:
    int _id;
};
