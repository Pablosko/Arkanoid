#ifndef SDLPROJECT_COLLISIONS_HELPER_H
#define SDLPROJECT_COLLISIONS_HELPER_H
#include <SDL.h>
#include "Vector2D.h"
class CollisionsHelper {
public:
    static bool IsPointInsideRect(const SDL_Rect* rect, const Vector2D<int>* vector){
        return vector->X < (rect->x + rect->w)
        && vector->X > rect->x
        && vector->Y < (rect->y + rect->h)
        && vector->Y > rect->y;
    }

    static bool IsRectInsideRect(const SDL_Rect* rect1, const SDL_Rect* rect2){
        return rect1->x + rect1->w >= rect2->x
            && rect1->x <= rect2->x + rect2->w
            && rect1->y + rect1->h >= rect2->y
            && rect1->y <= rect2->y + rect2->h;
    }
};
#endif //SDLPROJECT_COLLISIONS_HELPER_H
