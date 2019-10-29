#ifndef EVENT_H
#define EVENT_H

#include <optional>
#include "entity.h"
#include "message.h"

namespace strife {
    namespace core {
        
        class Event : public common::Message {
            
        public:
        
            const std::optional<Entity> target;
            
            Event();
            Event(const Entity target);
            virtual ~Event() = default;
            
        };
        
    }
}

#endif