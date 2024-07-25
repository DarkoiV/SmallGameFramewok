#pragma once
#include <memory>

namespace SmallGameFramework {
struct SceneInterface
{
    SceneInterface()          = default;
    virtual ~SceneInterface() = default;

    SceneInterface(SceneInterface&)  = delete;
    SceneInterface(SceneInterface&&) = delete;

    virtual void onEnter()  = 0;
    virtual void onUpdate() = 0;
    virtual void onExit()   = 0;

    virtual bool isRunning() { return isRunning_; }

  protected:
    bool isRunning_ = true;
};

using ScenePtr = std::unique_ptr<SceneInterface>;

} // namespace SmallGameFramework
