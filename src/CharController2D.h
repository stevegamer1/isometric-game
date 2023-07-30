#ifndef CHARCONTROLLER2D_H
#define CHARCONTROLLER2D_H

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <Input.hpp>
#include <AnimatedSprite.hpp>

namespace godot {

    class CharController2D : public KinematicBody2D {
        GODOT_CLASS(CharController2D, KinematicBody2D)

    private:
        // this type is used for animation
        enum direction8 {
            UP_LEFT,       UP,       UP_RIGHT, 
            LEFT,         ZERO,         RIGHT,
            BOTTOM_LEFT, BOTTOM, BOTTOM_RIGHT
        };

        String run_anim_name[9] = {
            "run_top_left",    "run_top",       "run_top_right",
            "run_left" ,       "idle_bottom_right" ,"run_right",
            "run_bottom_left", "run_bottom", "run_bottom_right"
        };

        direction8 vec2_to_dir8(Vector2 vector);

        String get_run_anim_name(direction8 direction);

        float speed_;
        AnimatedSprite* sprite_ = nullptr;
        NodePath sprite_path_;

        void play_anim(Vector2 p_direction);

    public:
        static void _register_methods();

        CharController2D();
        ~CharController2D();

        void set_speed(float p_speed);
        float get_speed();

        void set_sprite(NodePath p_sprite);
        NodePath get_sprite_path();

        void _init();

        void _ready();

        void _physics_process(float delta);
    };

}

#endif