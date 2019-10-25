#include "system.h"

using namespace strife::core;

ISystem::ISystem(common::Dispatcher& dispatcher)
    : dispatcher_(dispatcher) {}