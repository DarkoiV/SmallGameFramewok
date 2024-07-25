#pragma once
#include "SmallGameFramework/common/scene_interface.hpp"

struct Scene : SmallGameFramework::SceneInterface
{
    void onEnter() override { }

    void onUpdate() override { }

    void onExit() override { }

    bool isRunning() override { return false; }
};
