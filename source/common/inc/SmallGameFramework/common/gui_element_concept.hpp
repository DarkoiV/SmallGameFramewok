#pragma once
#include "SmallGameFramework/common/vector2.hpp" // IWYU pragma: keep
#include <SDL2/SDL_render.h>
#include <type_traits>

namespace SmallGameFramework {
template <typename E>
concept GuiElementConcept = requires(E e, SDL_Renderer* r) {
    requires std::is_move_constructible_v<E>;
    requires std::is_move_assignable_v<E>;
    requires std::is_trivial_v<E>;
    e.size()->Vector2;
    e.pos()->Vector2;
    e.draw(r);
};
} // namespace SmallGameFramework
