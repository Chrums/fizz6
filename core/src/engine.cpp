#include "engine.h"

#include "events.h"

using namespace strife::core;
using namespace std;

Engine::Scenes::Scenes(Engine& engine)
	: engine_(engine) {}

Scene& Engine::Scenes::load(const string path) {
	Scene& scene = scenes_.try_emplace(path).first->second;
	
	SceneLoadEvent sceneLoadEvent(scene);
	engine_.dispatcher.emit(sceneLoadEvent);
	
	return scene;
}

void Engine::Scenes::unload(const string path) {
	Scene& scene = scenes_.find(path)->second;
	
	SceneUnloadEvent sceneUnloadEvent(scene);
	engine_.dispatcher.emit(sceneUnloadEvent);
	
	scenes_.erase(path);
}

Engine::Systems::Systems(Engine& engine)
	: engine_(engine) {}

Engine::Systems::~Systems() {
	for (auto [type, system] : systems_) {
        delete system;
    }
}

Engine& Engine::Instance() {
	if (Engine::instance_ == nullptr) {
		Engine::instance_ = new Engine();
	}
	
	return *Engine::instance_;
}

Engine* Engine::instance_ = nullptr;

Engine::Engine()
    : scenes(*this)
    , systems(*this) {}