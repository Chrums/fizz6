#ifndef COMPONENT_H
#define COMPONENT_H

#include "entity.h"
#include "unique.h"

namespace strife {
    namespace core {
        
        class Component : public common::Unique {
            
        public:
        
            const Entity entity;
            
            Component(const Entity entity);
			virtual ~Component() = default;
            
        };
        
    }
}

#endif