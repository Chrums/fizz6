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
        
            ISystem(common::Dispatcher& dispatcher);
            virtual ~ISystem() = default;
            
        protected:
        
            common::Dispatcher& dispatcher_;
            
        };
        
        template <class C>
        class System : public ISystem {
            
        public:
        
            common::Action<void (const UpdateEvent&)> updateAction;
            common::Action<void (const RenderEvent&)> renderAction;
            
            System(common::Dispatcher& dispatcher)
                : ISystem(dispatcher) {
                dispatcher_.on<SceneLoadEvent>(std::bind(&System::onSceneLoad, this, std::placeholders::_1));
                dispatcher_.on<SceneUnloadEvent>(std::bind(&System::onSceneUnload, this, std::placeholders::_1));
                dispatcher_.on<UpdateEvent>(std::bind(&System::onUpdate, this, std::placeholders::_1));
                C::Subscribe(*this);
            }
            
            ~System() {
                C::Unsubscribe(*this);
            }
            
        private:
        
            std::set<Scene*> scenes_;
        
            void onSceneLoad(const SceneLoadEvent& sceneLoadEvent) {
                Scene* const scene = &(sceneLoadEvent.scene);
                scenes_.insert(scene);
            }
            
            void onSceneUnload(const SceneUnloadEvent& sceneUnloadEvent) {
                Scene* const scene = &(sceneUnloadEvent.scene);
                scenes_.erase(scene);
            }
            
            void onUpdate(const UpdateEvent& updateEvent) {
                for (Scene* const scene : scenes_) {
                    Storage<C>& storage = scene->components.get<C>();
                    for (auto [entity, component] : storage) {
                        updateAction(component, updateEvent);
                    }
                }
            }
            
            void onRender(const RenderEvent& renderEvent) {
                for (Scene* const scene : scenes_) {
                    Storage<C>& storage = scene->components.get<C>();
                    for (auto [entity, component] : storage) {
                        renderAction(component, renderEvent);
                    }
                }
            }
            
        };
        
    }
}

#endif

// #ifndef SYSTEM_H
// #define SYSTEM_H

// #include "event.h"

// namespace strife {
//     namespace core {
        
//         class Scene;
        
//         class ISystem {
            
//         public:
            
//             ISystem(Scene& scene);
//             virtual ~ISystem() = default;
            
//         protected:
        
//             Scene& scene_;
            
//         };
        
//         template <class C>
//         class System : public ISystem {
            
//         private:
    
//             template <class E>
//             using Callback = std::function<void(C* const, const E&)>;
            
//             template <class E>
//             class Binding {
                
//             public:
            
//                 Binding(Callback<E> callback)
//                     : callback_(callback) {}
//                 ~Binding() = default;
                
//                 void operator()(C* const component, const Event& event) {
//                     callback_(component, static_cast<const E&>(event));
//                 }
                
//             private:
            
//                 Callback<E> callback_;
                
//             };
            
//         }
        
//         public:
        
//             System(Scene& scene, Dispatcher& dispatcher, IStorage& storage)
//                 : ISystem(scene)
//                 , dispatcher_(dispatcher)
//                 , storage_(storage) {
//                 C::Initialize(*this);
//             }
//             ~System() = default;
            
//             template <class E>
//             void on(Callback<E> callback) {
// 				const std::type_index type(typeid(E));
// 				Binding<E> binding(callback);
// 				callbacks_.insert({type, binding});
// 				dispatcher_.on<E>(std::bind(&System<C>::emit<E>, this, std::placeholders::_1));
//             }
            
//             template <class E>
//             void emit(const Event& event) {
// 				const std::type_index type(typeid(E));
// 				Callback<Event> callback = callbacks_[type];
// 				if (event.target.has_value()) {
// 				    C* component = event.target.value().components.find<C>();
// 				    if (component != nullptr) {
// 				        callback(component, event);
// 				    }
// 				} else {
// 				    for (auto [entity, component] : storage_) {
// 				        callback(static_cast<C*>(&component), event);
// 				    }
// 				}
//             }
                
//         private:
            
//             Dispatcher& dispatcher_;
//             IStorage& storage_;
// 			std::map<const std::type_index, Callback<Event>> callbacks_;
            
//         };
        
//     }
// }

// #endif