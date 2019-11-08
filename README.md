# Development Envirnoment

- Visual Studio 2017
- Windows SDK Version `10.0.16299.0`

# Classes Description

1. CEventRegistry ([.h](https://github.com/Aa22041100/cpp_complex_event_system/blob/master/Event/CEventRegistry.h), [.cpp](https://github.com/Aa22041100/cpp_complex_event_system/blob/master/Event/CEventRegistry.cpp))
    - store all events
    - broadcasting
2. CEvent ([.h](https://github.com/Aa22041100/cpp_complex_event_system/blob/master/Event/CEvent.h), [.cpp](https://github.com/Aa22041100/cpp_complex_event_system/blob/master/Event/CEvent.cpp))
    - store all event listeners
    - specify different events by different names
3. CEventEntity ([.h](https://github.com/Aa22041100/cpp_complex_event_system/blob/master/Event/CEventEntity.h), [.cpp](https://github.com/Aa22041100/cpp_complex_event_system/blob/master/Event/CEventEntity.cpp))
    - store what values are passed through the event
    - provide simple safe casting by limiting to pass `string`, `bool` and `float` types
4. IEventListener ([.h](https://github.com/Aa22041100/cpp_complex_event_system/blob/master/Event/IEventListener.h))
    - an interface for a class which needs to listen an event
5. CDemoGame ([.h](https://github.com/Aa22041100/cpp_complex_event_system/blob/master/Event/CDemoGame.h), [.cpp](https://github.com/Aa22041100/cpp_complex_event_system/blob/master/Event/CDemoGame.cpp))
    - a demo class for demostrating the usage of IEventListener

# Further Studies

1. [https://gameprogrammingpatterns.com/observer.html](https://gameprogrammingpatterns.com/observer.html)
