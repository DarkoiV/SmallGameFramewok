#include "SmallGameFramework/core/base.hpp"
#include <SDL2/SDL.h>

using SmallGameFramework::Base;

static SDL_Renderer* RENDERER;
static SDL_Window*   WINDOW;
static const char*   TITLE         = "TITLE";
static int           RENDER_WIDTH  = 640;
static int           RENDER_HEIGHT = 400;
static int           RENDER_SCALE  = 2;
static uint32_t      LOGIC_TICK    = 10;

Base::Base()
{
    app = this;
    createWindow();

    LOG_INFO(logger, "Base has been created");
}

Base::~Base()
{
    LOG_INFO(logger, "Base has been destroyed");
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
    LOG_INFO(logger, "Entering main loop");
    try
    {
        while (isRunning)
        {
            sceneManager.switchToNextScene();
            mainLoop();
        }
    }
    catch (std::logic_error& e)
    {
        LOG_ERROR(logger, "Caught logic error: {}", e.what());
    }
    catch (...)
    {
        LOG_ERROR(logger, "Caught unknown error");
    }
    LOG_INFO(logger, "Exited main loop");
}

void Base::createWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        LOG_ERROR(logger, "Failed to init SDL_Video: {}", SDL_GetError());
        std::abort();
    }

    WINDOW = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              RENDER_WIDTH * RENDER_SCALE, RENDER_HEIGHT * RENDER_SCALE, 0);
    if (not WINDOW)
    {
        LOG_ERROR(logger, "Failed to create SDL_Window: {}", SDL_GetError());
        std::abort();
    }

    RENDERER = SDL_CreateRenderer(WINDOW, -1, 0);
    if (not RENDERER)
    {
        LOG_ERROR(logger, "Failed to create SDL_Renderer: {}", SDL_GetError());
        std::abort();
    }
    if (SDL_RenderSetLogicalSize(RENDERER, RENDER_WIDTH, RENDER_HEIGHT))
    {
        LOG_ERROR(logger, "Failed to set render logical size: {}", SDL_GetError());
        std::abort();
    }

    LOG_INFO(logger, "Created SDL_Window");
}

void Base::mainLoop()
{
    auto& scene = sceneManager.getScene();
    logicTS     = SDL_GetTicks64();
    while (scene.isRunning())
    {
        eventLoop(scene);

        uint64_t currentTS  = SDL_GetTicks64();
        uint32_t elapsed    = currentTS - logicTS;
        logicTS             = currentTS;
        logicLag           += elapsed;

        while (logicLag >= LOGIC_TICK)
        {
            scene.onUpdate();
            logicLag -= LOGIC_TICK;
        }
    }
}

void Base::eventLoop(SceneInterface& scene)
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_QUIT:
            scene.onQuitRequest();
            isRunning = scene.isRunning();
            break;
        }
    }
}
