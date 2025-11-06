#include "keyDetector.h" 

// change snake direction left
void MoveKeyLeft::doSomething(GameContext& ctx) {
    ctx.direction = Direction::LEFT;
}

// change snake direction right
void MoveKeyRight::doSomething(GameContext& ctx) {
    ctx.direction = Direction::RIGHT;
}

// change snake direction down
void MoveKeyDown::doSomething(GameContext& ctx) {
    ctx.direction = Direction::DOWN;
}

// change snake direction up
void MoveKeyUp::doSomething(GameContext& ctx) {
    ctx.direction = Direction::UP;
}

// close game window
void EscapeKey::doSomething(GameContext& ctx) {
        ctx.window.close();
}

