#include "SmallGameFramework/core/base.hpp"
#include "quill/Backend.h"
#include "quill/Frontend.h"
#include "quill/LogMacros.h"
#include "quill/sinks/ConsoleSink.h"
#include <SDL2/SDL.h>

using SmallGameFramework::Base;

static SDL_Renderer* RENDERER;
static SDL_Window*   WINDOW;
static const char*   TITLE         = "TITLE";
static int           RENDER_WIDTH  = 640;
static int           RENDER_HEIGHT = 400;
static int           RENDER_SCALE  = 2;

Base::Base()
{
    app = this;
    startLogger();
    createWindow();

    LOG_INFO(coreLogger, "Base has been created");
}

Base::~Base()
{
    LOG_INFO(coreLogger, "Base has been destroyed");
}

void Base::exec()
{
    if (not app) std::abort();

    app->onEnter();
    app->run();
    app->onExit();
}

void Base::run()
{
    LOG_INFO(coreLogger, "Entering main loop");
    try
    {
        sceneManager.switchToNextScene();
        while (isRunning)
        {
            mainLoop();
        }
    }
    catch (std::logic_error& e)
    {
        LOG_ERROR(coreLogger, "Caught logic error: {}", e.what());
    }
    catch (...)
    {
        LOG_ERROR(coreLogger, "Caught unknown error");
    }
    LOG_INFO(coreLogger, "Exited main loop");
}

void Base::startLogger()
{
    quill::Backend::start();

    auto consoleSink = quill::Frontend::create_or_get_sink<quill::ConsoleSink>("console");
    coreLogger       = quill::Frontend::create_or_get_logger(coreLoggerName, consoleSink);
    appLogger        = quill::Frontend::create_or_get_logger(appLoggerName, consoleSink);

    LOG_INFO(coreLogger, "Logger has started");
}

void Base::createWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        LOG_ERROR(coreLogger, "Failed to init SDL_Video: {}", SDL_GetError());
        std::abort();
    }

    WINDOW = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              RENDER_WIDTH * RENDER_SCALE, RENDER_HEIGHT * RENDER_SCALE, 0);
    if (not WINDOW)
    {
        LOG_ERROR(coreLogger, "Failed to create SDL_Window: {}", SDL_GetError());
        std::abort();
    }

    RENDERER = SDL_CreateRenderer(WINDOW, -1, 0);
    if (not RENDERER)
    {
        LOG_ERROR(coreLogger, "Failed to create SDL_Renderer: {}", SDL_GetError());
        std::abort();
    }
    if (SDL_RenderSetLogicalSize(RENDERER, RENDER_WIDTH, RENDER_HEIGHT))
    {
        LOG_ERROR(coreLogger, "Failed to set render logical size: {}", SDL_GetError());
        std::abort();
    }

    LOG_INFO(coreLogger, "Created SDL_Window");
}

void Base::mainLoop()
{
    auto& scene = sceneManager.getScene();
    while (scene.isRunning())
    {
        scene.onUpdate();
    }
    sceneManager.switchToNextScene();
}
