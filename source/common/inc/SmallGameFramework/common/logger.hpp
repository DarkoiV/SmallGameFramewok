#pragma once
#include "quill/LogMacros.h" // IWYU pragma: export
#include "quill/Logger.h"

namespace SmallGameFramework {
struct Logger
{
    Logger(const std::string&);

    quill::Logger* operator->() { return qlogger; }

  private:
    Logger();
    friend struct Base;

    quill::Logger* qlogger;
};
} // namespace SmallGameFramework
