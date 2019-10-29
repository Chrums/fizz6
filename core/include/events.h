#pragma once

#include "event.h"
#include "scene.h"

namespace strife {
    namespace core {
        
        class SceneLoadEvent : public Event {
            
        public:
        
            Scene& scene;
            
            SceneLoadEvent(Scene& scene)
                : Event()
                , scene(scene) {}
            
        };
        
        class SceneUnloadEvent : public Event {
            
        public:
        
            Scene& scene;
            
            SceneUnloadEvent(Scene& scene)
                : Event()
                , scene(scene) {}
            
        };
        
        class InitializeEvent : public Event {
            
        public:
            
            InitializeEvent()
                : Event() {}
            
        };
        
        class UpdateEvent : public Event {
            
        public:
            
            UpdateEvent()
                : Event() {}
            
        };
        
        class RenderEvent : public Event {
            
        public:
            
            RenderEvent()
                : Event() {}
            
        };
        
    }
}