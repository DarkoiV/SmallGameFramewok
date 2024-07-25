#include "SmallGameFramework/core/base.hpp"
#include "quill/Backend.h"
#include "quill/Frontend.h"
#include "quill/LogMacros.h"
#include "quill/sinks/ConsoleSink.h"

using SmallGameFramework::Core::Base;

Base::Base()
{
    startLogger();

    LOG_INFO(logger, "Base has been created");
}

Base::~Base()
{
    LOG_INFO(logger, "Base has been destroyed");
}

void Base::startLogger()
{
    quill::Backend::start();

    auto consoleSink = quill::Frontend::create_or_get_sink<quill::ConsoleSink>("console");
    logger           = quill::Frontend::create_or_get_logger(loggerName, consoleSink);

    LOG_INFO(logger, "Logger has started");
}
