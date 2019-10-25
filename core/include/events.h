#ifndef EVENTS_H
#define EVENTS_H

#include "event.h"
#include "scene.h"

namespace strife {
    namespace core {
        
        class SceneLoadEvent : public common::Event {
            
        public:
        
            Scene& scene;
            
            SceneLoadEvent(Scene& scene)
                : common::Event()
                , scene(scene) {}
            
        };
        
        class SceneUnloadEvent : public common::Event {
            
        public:
        
            Scene& scene;
            
            SceneUnloadEvent(Scene& scene)
                : common::Event()
                , scene(scene) {}
            
        };
        
        class UpdateEvent : public common::Event {
            
        public:
            
            UpdateEvent()
                : common::Event() {}
            
        };
        
        class RenderEvent : public common::Event {
            
        public:
            
            RenderEvent()
                : common::Event() {}
            
        };
        
    }
}

#endif