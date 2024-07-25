#pragma once
#include "SmallGameFramework/common/scene_interface.hpp"

namespace SmallGameFramework {
struct SceneManager
{
    SceneManager()  = default;
    ~SceneManager() = default;

    SceneManager(SceneManager&)  = delete;
    SceneManager(SceneManager&&) = delete;

    SceneInterface& getScene();

  private:
    ScenePtr nextScene;
    ScenePtr currentScene;
};
} // namespace SmallGameFramework
