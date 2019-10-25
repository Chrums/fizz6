{"filter":false,"title":"component_system.h","tooltip":"/core/include/component_system.h","undoManager":{"mark":15,"position":15,"stack":[[{"start":{"row":0,"column":0},"end":{"row":87,"column":6},"action":"insert","lines":["#ifndef SYSTEM_H","#define SYSTEM_H","","#include <map>","#include <functional>","#include \"Dispatcher.h\"","#include \"Entity.h\"","#include \"Event.h\"","#include \"IStorage.h\"","","namespace Strife {","    namespace Core {","        ","        class Scene;","        ","        template <class C>","        class System : public ISystem {","            ","        private:","        ","            template <class E>","            using Callback = std::function<void(C* const, const E&)>;","            ","            template <class E>","            class Binding {","                ","            public:","            ","                Binding(Callback<E> callback)","                    : callback_(callback) {}","                ~Binding() = default;","                ","                void operator()(C* const component, const Event& event) {","                    callback_(component, static_cast<const E&>(event));","                }","                ","            private:","            ","                Callback<E> callback_;","                ","            };","            ","        public:","        ","            System(Scene& scene, Dispatcher& dispatcher, IStorage& storage)","                : ISystem(scene)","                , dispatcher_(dispatcher)","                , storage_(storage) {","                C::Initialize(*this);","            }","            ~System() = default;","            ","            template <class E>","            void on(Callback<E> callback) {","\t\t\t\tconst std::type_index type = std::type_index(typeid(E));","\t\t\t\tBinding<E> binding(callback);","\t\t\t\tcallbacks_.insert({type, binding});","\t\t\t\tdispatcher_.on<E>(std::bind(&System<C>::emit<E>, this, std::placeholders::_1));","            }","            ","            template <class E>","            void emit(const Event& event) {","\t\t\t\tconst std::type_index type = std::type_index(typeid(E));","\t\t\t\tCallback<Event> callback = callbacks_[type];","\t\t\t\tif (event.target.has_value()) {","\t\t\t\t    C* component = event.target.value().components.find<C>();","\t\t\t\t    if (component != nullptr) {","\t\t\t\t        callback(component, event);","\t\t\t\t    }","\t\t\t\t} else {","\t\t\t\t    for (auto [entity, component] : storage_) {","\t\t\t\t        callback(static_cast<C*>(&component), event);","\t\t\t\t    }","\t\t\t\t}","            }","                ","        private:","            ","            Dispatcher& dispatcher_;","            IStorage& storage_;","\t\t\tstd::map<const std::type_index, Callback<Event>> callbacks_;","            ","        };","        ","    }","}","","#endif"],"id":1}],[{"start":{"row":5,"column":10},"end":{"row":5,"column":11},"action":"remove","lines":["D"],"id":2},{"start":{"row":5,"column":10},"end":{"row":5,"column":11},"action":"insert","lines":["d"]}],[{"start":{"row":6,"column":10},"end":{"row":6,"column":11},"action":"remove","lines":["E"],"id":3},{"start":{"row":6,"column":10},"end":{"row":6,"column":11},"action":"insert","lines":["e"]}],[{"start":{"row":7,"column":10},"end":{"row":7,"column":11},"action":"remove","lines":["E"],"id":4},{"start":{"row":7,"column":10},"end":{"row":7,"column":11},"action":"insert","lines":["e"]}],[{"start":{"row":8,"column":10},"end":{"row":8,"column":11},"action":"remove","lines":["I"],"id":5},{"start":{"row":8,"column":10},"end":{"row":8,"column":11},"action":"remove","lines":["S"]}],[{"start":{"row":8,"column":10},"end":{"row":8,"column":11},"action":"insert","lines":["s"],"id":6}],[{"start":{"row":16,"column":30},"end":{"row":16,"column":31},"action":"remove","lines":["I"],"id":7}],[{"start":{"row":16,"column":14},"end":{"row":16,"column":15},"action":"insert","lines":["C"],"id":8},{"start":{"row":16,"column":15},"end":{"row":16,"column":16},"action":"insert","lines":["o"]},{"start":{"row":16,"column":16},"end":{"row":16,"column":17},"action":"insert","lines":["m"]},{"start":{"row":16,"column":17},"end":{"row":16,"column":18},"action":"insert","lines":["p"]},{"start":{"row":16,"column":18},"end":{"row":16,"column":19},"action":"insert","lines":["o"]},{"start":{"row":16,"column":19},"end":{"row":16,"column":20},"action":"insert","lines":["n"]},{"start":{"row":16,"column":20},"end":{"row":16,"column":21},"action":"insert","lines":["e"]},{"start":{"row":16,"column":21},"end":{"row":16,"column":22},"action":"insert","lines":["n"]},{"start":{"row":16,"column":22},"end":{"row":16,"column":23},"action":"insert","lines":["t"]}],[{"start":{"row":44,"column":12},"end":{"row":44,"column":18},"action":"remove","lines":["System"],"id":10},{"start":{"row":44,"column":12},"end":{"row":44,"column":13},"action":"insert","lines":["C"]},{"start":{"row":44,"column":13},"end":{"row":44,"column":14},"action":"insert","lines":["o"]},{"start":{"row":44,"column":14},"end":{"row":44,"column":15},"action":"insert","lines":["m"]},{"start":{"row":44,"column":15},"end":{"row":44,"column":16},"action":"insert","lines":["p"]},{"start":{"row":44,"column":16},"end":{"row":44,"column":17},"action":"insert","lines":["o"]},{"start":{"row":44,"column":17},"end":{"row":44,"column":18},"action":"insert","lines":["n"]},{"start":{"row":44,"column":18},"end":{"row":44,"column":19},"action":"insert","lines":["e"]},{"start":{"row":44,"column":19},"end":{"row":44,"column":20},"action":"insert","lines":["n"]},{"start":{"row":44,"column":20},"end":{"row":44,"column":21},"action":"insert","lines":["t"]},{"start":{"row":44,"column":21},"end":{"row":44,"column":22},"action":"insert","lines":["S"]},{"start":{"row":44,"column":22},"end":{"row":44,"column":23},"action":"insert","lines":["y"]},{"start":{"row":44,"column":23},"end":{"row":44,"column":24},"action":"insert","lines":["s"]},{"start":{"row":44,"column":24},"end":{"row":44,"column":25},"action":"insert","lines":["t"]},{"start":{"row":44,"column":25},"end":{"row":44,"column":26},"action":"insert","lines":["e"]},{"start":{"row":44,"column":26},"end":{"row":44,"column":27},"action":"insert","lines":["m"]}],[{"start":{"row":50,"column":13},"end":{"row":50,"column":19},"action":"remove","lines":["System"],"id":11},{"start":{"row":50,"column":13},"end":{"row":50,"column":28},"action":"insert","lines":["ComponentSystem"]}],[{"start":{"row":57,"column":33},"end":{"row":57,"column":39},"action":"remove","lines":["System"],"id":12},{"start":{"row":57,"column":33},"end":{"row":57,"column":48},"action":"insert","lines":["ComponentSystem"]}],[{"start":{"row":45,"column":18},"end":{"row":45,"column":19},"action":"remove","lines":["I"],"id":13}],[{"start":{"row":0,"column":8},"end":{"row":0,"column":9},"action":"insert","lines":["C"],"id":14},{"start":{"row":0,"column":9},"end":{"row":0,"column":10},"action":"insert","lines":["O"]},{"start":{"row":0,"column":10},"end":{"row":0,"column":11},"action":"insert","lines":["M"]},{"start":{"row":0,"column":11},"end":{"row":0,"column":12},"action":"insert","lines":["P"]},{"start":{"row":0,"column":12},"end":{"row":0,"column":13},"action":"insert","lines":["O"]},{"start":{"row":0,"column":13},"end":{"row":0,"column":14},"action":"insert","lines":["N"]},{"start":{"row":0,"column":14},"end":{"row":0,"column":15},"action":"insert","lines":["E"]},{"start":{"row":0,"column":15},"end":{"row":0,"column":16},"action":"insert","lines":["N"]},{"start":{"row":0,"column":16},"end":{"row":0,"column":17},"action":"insert","lines":["T"]},{"start":{"row":0,"column":17},"end":{"row":0,"column":18},"action":"insert","lines":["_"]}],[{"start":{"row":1,"column":8},"end":{"row":1,"column":9},"action":"insert","lines":["C"],"id":15},{"start":{"row":1,"column":9},"end":{"row":1,"column":10},"action":"insert","lines":["O"]},{"start":{"row":1,"column":10},"end":{"row":1,"column":11},"action":"insert","lines":["M"]},{"start":{"row":1,"column":11},"end":{"row":1,"column":12},"action":"insert","lines":["P"]},{"start":{"row":1,"column":12},"end":{"row":1,"column":13},"action":"insert","lines":["O"]},{"start":{"row":1,"column":13},"end":{"row":1,"column":14},"action":"insert","lines":["N"]},{"start":{"row":1,"column":14},"end":{"row":1,"column":15},"action":"insert","lines":["E"]},{"start":{"row":1,"column":15},"end":{"row":1,"column":16},"action":"insert","lines":["N"]},{"start":{"row":1,"column":16},"end":{"row":1,"column":17},"action":"insert","lines":["T"]},{"start":{"row":1,"column":17},"end":{"row":1,"column":18},"action":"insert","lines":["_"]}],[{"start":{"row":10,"column":10},"end":{"row":10,"column":11},"action":"remove","lines":["S"],"id":16},{"start":{"row":10,"column":10},"end":{"row":10,"column":11},"action":"insert","lines":["s"]}],[{"start":{"row":11,"column":14},"end":{"row":11,"column":15},"action":"remove","lines":["C"],"id":17},{"start":{"row":11,"column":14},"end":{"row":11,"column":15},"action":"insert","lines":["c"]}]]},"ace":{"folds":[],"scrolltop":480,"scrollleft":0,"selection":{"start":{"row":78,"column":36},"end":{"row":78,"column":36},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":33,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1571435712177,"hash":"24cd2b456b702fbd8ea289a0c7c24bf773357feb"}