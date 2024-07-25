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
    void            switchToNextScene();

    template <typename T, typename... Args>
        requires std::is_base_of_v<SceneInterface, T>
    void setNextScene(Args&&... args)
    {
        nextScene = std::make_unique<T>(std::forward<Args>(args)...);
    }

  private:
    ScenePtr nextScene;
    ScenePtr currentScene;
};
} // namespace SmallGameFramework
