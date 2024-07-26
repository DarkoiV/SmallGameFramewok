#pragma once
#include "SmallGameFramework/common/scene_interface.hpp"

struct Scene : SmallGameFramework::SceneInterface
{
    void onEnter() override { }

    void onUpdate() override { }

    void onExit() override { }

    void onQuitRequest() override { isRunning_ = false; }

    bool isRunning() const override { return isRunning_; }

  private:
    bool isRunning_ = true;
};
