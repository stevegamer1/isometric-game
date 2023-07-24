#include "CharController2D.h"

using namespace godot;

void CharController2D::_register_methods() {
    register_method("_physics_process", &CharController2D::_physics_process);
    register_property<CharController2D, float>("Speed", &CharController2D::set_speed, &CharController2D::get_speed, 200.0);
}

CharController2D::CharController2D() {
    speed_ = 200.0;
}

CharController2D::~CharController2D() {
}

void CharController2D::set_speed(float p_speed) {
    speed_ = p_speed;
}

float CharController2D::get_speed() {
    return speed_;
}

void CharController2D::_init() {
}

Vector2 get_input_direction() {
    Input* input = Input::get_singleton();
    return input->get_vector("ui_left", "ui_right", "ui_up", "ui_down");
}

void CharController2D::_physics_process(float delta) {
    move_and_slide(get_input_direction() * speed_);
}