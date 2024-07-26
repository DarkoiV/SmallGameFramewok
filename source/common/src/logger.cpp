#include "SmallGameFramework/common/logger.hpp"
#include "quill/Backend.h"
#include "quill/Frontend.h"
#include "quill/sinks/ConsoleSink.h"

using SmallGameFramework::Logger;

Logger::Logger(const std::string& name)
{
    auto consoleSink = quill::Frontend::create_or_get_sink<quill::ConsoleSink>("console");
    qlogger          = quill::Frontend::create_or_get_logger(name, consoleSink);
}

Logger::Logger()
{
    quill::Backend::start();

    auto consoleSink = quill::Frontend::create_or_get_sink<quill::ConsoleSink>("console");
    qlogger          = quill::Frontend::create_or_get_logger("Core", consoleSink);

    LOG_INFO(qlogger, "Quill has started");
}
