#include "CharController2D.h"

using namespace godot;

void CharController2D::_register_methods() {
    register_method("_ready", &CharController2D::_ready);
    register_method("_physics_process", &CharController2D::_physics_process);
    register_property<CharController2D, float>("Speed", &CharController2D::set_speed, &CharController2D::get_speed, 200.0);
    register_property<CharController2D, NodePath>("Animated Sprite", &CharController2D::set_sprite, &CharController2D::get_sprite_path, NodePath());
}

CharController2D::CharController2D() {
    speed_ = 200.0;
    sprite_ = nullptr;
}

CharController2D::~CharController2D() {
}

////////////// here setters & getters for properties start //////////////

void CharController2D::set_speed(float p_speed) {
    speed_ = p_speed;
}

float CharController2D::get_speed() {
    return speed_;
}

void CharController2D::set_sprite(NodePath p_path) {
    sprite_path_ = p_path;
}

NodePath CharController2D::get_sprite_path() {
    return sprite_path_;
}

////////////// here setters & getters for properties end //////////////

void CharController2D::_init() {}

void CharController2D::_ready() {
    sprite_ = static_cast<AnimatedSprite*>(get_node(sprite_path_));
    if (sprite_ == nullptr) {
        Godot::print("ERROR: Character controller 2D: please, assign an AnimatedSprite");
    }
}

CharController2D::direction8 CharController2D::vec2_to_dir8(Vector2 vector) {
    int x_index = 0;
    if (vector.abs().x <= 0.1) x_index = 1;
    else if (vector.x > 0) x_index = 2;
    int y_index = 0;
    if (vector.abs().y <= 0.1) y_index = 1;
    else if (vector.y > 0) y_index = 2;

    return direction8(y_index * 3 + x_index);
}

String CharController2D::get_run_anim_name(CharController2D::direction8 direction) {
    // take element from array by index
    return run_anim_name[direction];
}

Vector2 get_input_direction() {
    Input* input = Input::get_singleton();
    return input->get_vector("ui_left", "ui_right", "ui_up", "ui_down");
}

void CharController2D::play_anim(Vector2 p_direction) {
    sprite_->play(get_run_anim_name(vec2_to_dir8(p_direction)));
}

void CharController2D::_physics_process(float delta) {
    Vector2 direction = get_input_direction();
    play_anim(direction);
    move_and_slide(direction * speed_);
}
