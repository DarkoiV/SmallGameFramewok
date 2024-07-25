#pragma once
#include "quill/Logger.h"
#include <string>

namespace SmallGameFramework::Core {
struct Base
{
    Base();
    ~Base();

    Base(Base&)  = delete;
    Base(Base&&) = delete;

  private:
    void startLogger();

    const std::string loggerName = "Base";
    quill::Logger*    logger;
};
} // namespace SmallGameFramework::Core
