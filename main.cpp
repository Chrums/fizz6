#include <iostream>
#include "component.h"
#include "dispatcher.h"
#include "scene.h"
#include "system.h"
#include "unique.h"
#include "engine.h"
#include "events.h"

using namespace std;
using namespace strife::common;
using namespace strife::core;

class TestComponent : public Component {
    
    using Component::Component;
    
public:

    static void Subscribe(Dispatcher& dispatcher) {
        
    }
    
    static void Unsubscribe(Dispatcher& dispatcher) {
        
    }
    
private:

    void onInitialize(const InitializeEvent& initializeEvent) {
        cout << "Initialize" << endl;
    }

    void onUpdate(const UpdateEvent& updateEvent) {
        cout << "Update" << endl;
    }
    
    void onRender(const RenderEvent& renderEvent) {
        cout << "Render" << endl;
    }
    
};

class TestSystem : public ISystem {
    
    public:
    
        TestSystem(Dispatcher& dispatcher)
            : ISystem() {
            dispatcher.subscribe<SceneLoadEvent>(bind(&TestSystem::OnSceneLoad, this, placeholders::_1));
            dispatcher.subscribe<SceneUnloadEvent>(bind(&TestSystem::OnSceneUnload, this, placeholders::_1));
        }
        
        void OnSceneLoad(const SceneLoadEvent& sceneLoadEvent) {
            cout << "Scene Load!" << endl;
        }
        
        void OnSceneUnload(const SceneUnloadEvent& sceneUnloadEvent) {
            cout << "Scene Unload!" << endl;
        }
    
};

int main(int argc, char const *argv[]) {
    
    Engine& engine = Engine::Instance();
    engine.systems.add<TestSystem>();
    engine.systems.add<System<TestComponent>>();
    Scene& scene = engine.scenes.load("");
    scene.components.add<TestComponent>();
    Entity e0 = scene.entities.add();
    e0.components.add<TestComponent>();
    Entity e1 = scene.entities.add();
    e1.components.add<TestComponent>();
    engine.dispatcher.emit(UpdateEvent());
    engine.scenes.unload("");
    
    return 0;
    
}