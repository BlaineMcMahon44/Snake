#include "keyDetector.h" 

/**
 * @breif abstract method that will detect the LEFT key and change the direction of the snake
 *
 * @param ctx - reference to the GameContext direction
 */
void MoveKeyLeft::doSomething(GameContext& ctx) {
    ctx.direction = Direction::LEFT;
}

/**
 * @breif abstract method that will detect the RIGHT key and change the direction of the snake
 *
 * @param ctx - reference to the GameContext direction
 */
void MoveKeyRight::doSomething(GameContext& ctx) {
    ctx.direction = Direction::RIGHT;
}

/**
 * @breif abstract method that will detect the DOWN key and change the direction of the snake
 *
 * @param ctx - reference to the GameContext direction
 */
void MoveKeyDown::doSomething(GameContext& ctx) {
    ctx.direction = Direction::DOWN;
}

/**
 * @breif abstract method that will detect the UP key and change the direction of the snake
 *
 * @param ctx - reference to the GameContext direction
 */
void MoveKeyUp::doSomething(GameContext& ctx) {
    ctx.direction = Direction::UP;
}

/**
 * @breif abstract method that will detect the ESC key and change the direction of the snake
 *
 * @param ctx - reference to the GameContext direction
 */
void EscapeKey::doSomething(GameContext& ctx) {
        ctx.window.close();
}

