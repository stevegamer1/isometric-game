#include "CharController2D.h"

using namespace godot;

void CharController2D::_register_methods() {
    register_method("_physics_process", &CharController2D::_physics_process);
}

CharController2D::CharController2D() {
    // set the behaviour of inherited CharacterBody2D to top-down
    // instead of platformer-like
    set_motion_mode(MOTION_MODE_FLOATING);
}

CharController2D::~CharController2D() {
}

void CharController2D::_init() {
}

Vector2 get_input_direction() {
    Input* input = Input::get_singleton();
    return input->get_vector("ui_left", "ui_right", "ui_up", "ui_down");
}

void CharController2D::_physics_process(float delta) {
    set_velocity(get_input_direction() * speed_);
    move_and_slide();
}