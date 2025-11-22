#pragma once
#include "utils.h"
#include "gameContext.h"
#include <SFML/Graphics.hpp>

/**
 * @class DetectKey
 * @brief DetectKey is a base class used to different derived key classes
 * used to implement the stragety pattern
 */
class DetectKey {
public:
    /**
    * @brief defines a virtual function doSomething
    *
    * takes in a reference to some gameContext to change a direction of snake
    */
    virtual ~DetectKey() = default;
    virtual void doSomething(GameContext& ctx) = 0;
};

/**
 * @class MoveKeyLeft
 *
 * @brief MoveKeyLeft is a derived class used to change the direction of the snake left 
 */
class MoveKeyLeft: public DetectKey {
public:
    void doSomething(GameContext& ctx) override; 
};

/**
 * @class MoveKeyRight
 *
 * @brief MoveKeyRight is a derived class used to change the direction of the snake right 
 */
class MoveKeyRight: public DetectKey {
    public:
        void doSomething(GameContext& ctx) override; 
    };

/**
 * @class MoveKeyDown
 *
 * @brief MoveKeyDown is a derived class used to change the direction of the snake down
 */
class MoveKeyDown: public DetectKey {
    public:
        void doSomething(GameContext& ctx) override; 
    };

/**
 * @class MoveKeyUp
 *
 * @brief MoveKeyUp is a derived class used to change the direction of the snake up
 */
class MoveKeyUp: public DetectKey {
    public:
        void doSomething(GameContext& ctx) override; 
    };
    
/**
 * @class EscapeKey
 *
 * @brief EscapeKey is a derived class used to close the game window
 */
class EscapeKey: public DetectKey {
public:
    void doSomething(GameContext& ctx) override; 
};
