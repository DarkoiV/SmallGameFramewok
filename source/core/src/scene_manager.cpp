#include "SmallGameFramework/core/scene_manager.hpp"

using SmallGameFramework::SceneManager;

SmallGameFramework::SceneInterface& SceneManager::getScene()
{
    if (not currentScene) throw std::logic_error("No current scene set");

    return *currentScene;
}
