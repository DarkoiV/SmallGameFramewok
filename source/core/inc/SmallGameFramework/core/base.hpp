#pragma once
#include "SmallGameFramework/common/logger.hpp"
#include "SmallGameFramework/core/scene_manager.hpp"

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

  private:
    Logger logger;

  protected:
    SceneManager sceneManager;

  private:
    void run();
    void createWindow();
    void mainLoop();
    void eventLoop(SceneInterface&);

    bool     isRunning = true;
    uint64_t logicTS   = 0;
    uint32_t logicLag  = 0;

    inline static Base* app = nullptr;
};
} // namespace SmallGameFramework
