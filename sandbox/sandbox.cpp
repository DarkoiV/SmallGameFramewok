#include "SmallGameFramework/core/base.hpp"
#include "quill/LogMacros.h"
#include "scene.hpp"

struct Sandbox : SmallGameFramework::Base
{
    void onEnter() override
    {
        sceneManager.setNextScene<Scene>();
        LOG_INFO(logger, "Entered Sandbox");
    }

    void onExit() override { LOG_INFO(logger, "Exited Sandbox"); }

  private:
    SmallGameFramework::Logger logger{"Sandbox"};
};

Sandbox sandbox;
