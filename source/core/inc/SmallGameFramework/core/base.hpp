#pragma once
#include "SmallGameFramework/core/scene_manager.hpp"
#include "quill/Logger.h"
#include <string>

namespace SmallGameFramework {
struct Base
{
    Base();
    ~Base();

    Base(Base&)  = delete;
    Base(Base&&) = delete;

    void run();

  private:
    void startLogger();
    void mainLoop();

    const std::string loggerName = "Base";
    quill::Logger*    logger;

    bool     isRunning      = true;
    uint64_t logicTimeStamp = 0;
    uint32_t logicLag       = 0;

    SceneManager sceneManager;
};
} // namespace SmallGameFramework
