#include "SmallGameFramework/core/base.hpp"
#include "quill/LogMacros.h"
#include "scene.hpp"

struct Sandbox : SmallGameFramework::Base
{
    void onEnter() override
    {
        sceneManager.setNextScene<Scene>();
        LOG_INFO(appLogger, "Entered Sandbox");
    }

    void onExit() override { LOG_INFO(appLogger, "Exited Sandbox"); }
};

Sandbox sandbox;
