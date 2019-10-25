{"filter":false,"title":"message.h","tooltip":"/core/include/message.h","undoManager":{"mark":4,"position":4,"stack":[[{"start":{"row":0,"column":0},"end":{"row":26,"column":6},"action":"insert","lines":["#ifndef MESSAGE_H","#define MESSAGE_H","","namespace Strife {","    namespace Core {","        ","        class Message {","            ","        public:","        ","            template <class M>","            static void AssertBase();","            ","            Message() = default;","            virtual ~Message() = default;","            ","        };","        ","        template <class M>","        void Message::AssertBase() {","            static_assert(std::is_base_of<Message, M>::value, \"Type not derived from Message\");","        }","        ","    }","}","","#endif"],"id":1}],[{"start":{"row":3,"column":10},"end":{"row":3,"column":11},"action":"remove","lines":["S"],"id":2},{"start":{"row":3,"column":10},"end":{"row":3,"column":11},"action":"insert","lines":["s"]}],[{"start":{"row":4,"column":14},"end":{"row":4,"column":15},"action":"remove","lines":["C"],"id":3},{"start":{"row":4,"column":14},"end":{"row":4,"column":15},"action":"insert","lines":["c"]}],[{"start":{"row":9,"column":8},"end":{"row":12,"column":12},"action":"remove","lines":["","            template <class M>","            static void AssertBase();","            "],"id":4}],[{"start":{"row":13,"column":10},"end":{"row":18,"column":9},"action":"remove","lines":["","        ","        template <class M>","        void Message::AssertBase() {","            static_assert(std::is_base_of<Message, M>::value, \"Type not derived from Message\");","        }"],"id":5}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":6,"column":23},"end":{"row":6,"column":23},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1571870691625,"hash":"3f5f78120ff14e958f6be78523bf2435621deb66"}