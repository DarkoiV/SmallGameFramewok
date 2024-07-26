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

    virtual void onEnter() = 0;
    virtual void onExit()  = 0;

    static void exec();

  protected:
    SceneManager sceneManager;

    const std::string appLoggerName = "App";
    quill::Logger*    appLogger;

  private:
    void run();
    void startLogger();
    void createWindow();
    void mainLoop();
    void eventLoop(SceneInterface&);

    const std::string coreLoggerName = "Core";
    quill::Logger*    coreLogger;

    bool     isRunning = true;
    uint64_t logicTS   = 0;
    uint32_t logicLag  = 0;

    inline static Base* app = nullptr;
};
} // namespace SmallGameFramework
