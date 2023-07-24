#ifndef CHARCONTROLLER2D_H
#define CHARCONTROLLER2D_H

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <Input.hpp>

namespace godot {

    class CharController2D : public KinematicBody2D {
        GODOT_CLASS(CharController2D, KinematicBody2D)

    private:
        float speed_;

    public:
        static void _register_methods();

        CharController2D();
        ~CharController2D();

        void set_speed(float p_speed);
        float get_speed();

        void _init();

        void _physics_process(float delta);
    };

}

#endif