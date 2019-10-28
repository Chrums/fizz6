#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <functional>
#include <set>
#include "action.h"
#include "dispatcher.h"
#include "events.h"
#include "scene.h"

namespace strife {
    namespace core {
        
        class ISystem {
            
        public:
        
            ISystem() = default;
            virtual ~ISystem() = default;
            
        };
        
        template <class C>
        class System : public ISystem {
            
        public:
            
            System(common::Dispatcher& dispatcher)
                : ISystem() {
                dispatcher.subscribe<SceneLoadEvent>(std::bind(&System::onSceneLoad, this, std::placeholders::_1));
                dispatcher.subscribe<SceneUnloadEvent>(std::bind(&System::onSceneUnload, this, std::placeholders::_1));
                dispatcher.subscribe<InitializeEvent>(std::bind(&System::onInitialize, this, std::placeholders::_1));
                dispatcher.subscribe<UpdateEvent>(std::bind(&System::onUpdate, this, std::placeholders::_1));
                dispatcher.subscribe<RenderEvent>(std::bind(&System::onRender, this, std::placeholders::_1));
                C::Subscribe(dispatcher_);
            }
            
            ~System() {
                C::Unsubscribe(dispatcher_);
            }
            
        private:
        
            common::Dispatcher dispatcher_;
        
            std::set<Scene*> scenes_;
        
            void onSceneLoad(const SceneLoadEvent& sceneLoadEvent) {
                Scene* const scene = &(sceneLoadEvent.scene);
                scenes_.insert(scene);
            }
            
            void onSceneUnload(const SceneUnloadEvent& sceneUnloadEvent) {
                Scene* const scene = &(sceneUnloadEvent.scene);
                scenes_.erase(scene);
            }
            
            void onInitialize(const InitializeEvent& initializeEvent) {
                for (Scene* const scene : scenes_) {
                    Storage<C>& storage = scene->components.get<C>();
                    for (auto [entity, component] : storage) {
                        //dispatcher_.emit(&component, initializeEvent);
                    }
                }
            }
            
            void onUpdate(const UpdateEvent& updateEvent) {
                for (Scene* const scene : scenes_) {
                    Storage<C>& storage = scene->components.get<C>();
                    for (auto [entity, component] : storage) {
                        //updateAction(component, updateEvent);
                    }
                }
            }
            
            void onRender(const RenderEvent& renderEvent) {
                for (Scene* const scene : scenes_) {
                    Storage<C>& storage = scene->components.get<C>();
                    for (auto [entity, component] : storage) {
                        //renderAction(component, renderEvent);
                    }
                }
            }
            
        };
        
    }
}

#endif