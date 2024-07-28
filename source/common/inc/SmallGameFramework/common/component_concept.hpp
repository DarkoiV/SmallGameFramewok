#pragma once
#include <entt/fwd.hpp>
#include <type_traits>

namespace SmallGameFramework {
template <typename C>
concept ComponentConcept = requires {
    requires std::is_move_constructible_v<C>;
    requires std::is_move_assignable_v<C>;
};

template <ComponentConcept C>
constexpr bool HasOnCreateHook =
    requires(entt::registry& reg, entt::entity e) { C::onCreate(reg, e); };

template <ComponentConcept C>
constexpr bool HasOnUpdateHook =
    requires(entt::registry& reg, entt::entity e) { C::onUpdate(reg, e); };

template <ComponentConcept C>
constexpr bool HasOnDeleteHook =
    requires(entt::registry& reg, entt::entity e) { C::onDelete(reg, e); };

} // namespace SmallGameFramework
