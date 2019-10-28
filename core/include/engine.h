#pragma once

#include <map>
#include <string>
#include <typeindex>
#include "dispatcher.h"
#include "event.h"
#include "scene.h"
#include "system.h"

namespace strife {
    namespace core {
        
        class Engine {
            
        public:
            
            class Scenes {
                
            public:
            
                Scenes(Engine& engine);
                ~Scenes() = default;
                
                Scene& load(const std::string path);
                void unload(const std::string path);
                
            private:
            
                Engine& engine_;
                
                std::map<const std::string, Scene> scenes_;
                
            };
        
            class Systems {
                
            public:
            
                Systems(Engine& engine);
                ~Systems();
                
                template <class S>
                S& add() {
                    std::type_index type(typeid(S));
                    S* const system = new S(engine_.dispatcher);
                    systems_.insert({type, system});
                    return *system;
                }
                
                template <class S>
                void remove() {
                    std::type_index type(typeid(S));
                    systems_.erase(type);
                }
                
                template <class S>
                S& get() {
                    std::type_index type(typeid(S));
                    return systems_.at(type);
                }
                
            private:
            
                Engine& engine_;
                
                std::map<const std::type_index, ISystem* const> systems_;
                
            };
        
        public:
            
            static Engine& Instance();
            
            common::Dispatcher dispatcher;
            
            Scenes scenes;
            Systems systems;
            
            ~Engine() = default;
            
        private:
            
			static Engine* instance_;
			
			Engine();
            
        };
        
    }
}