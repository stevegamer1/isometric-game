#ifndef CHARCONTROLLER2D_H
#define CHARCONTROLLER2D_H

#include <Godot.hpp>
#include <character_body2d.hpp>
#include <input.hpp>

namespace godot {

    class CharController2D : public CharacterBody2D {
        GODOT_CLASS(CharController2D, CharacterBody2D)

    private:

    public:
        static void _register_methods();

        CharController2D();
        ~CharController2D();

        void _init();

        void _physics_process(float delta);
    };

}

#endif