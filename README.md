# Development Envirnoment

- Visual Studio 2017
- Windows SDK Version `10.0.16299.0`

# Classes Description

1. CEventRegistry
    - store all events
    - broadcasting
2. CEvent
    - store all event listeners
    - specify different events by different names
3. CEventEntity
    - store what values are passed through the event
    - provide simple safe casting by limiting to pass `string`, `bool` and `float` type
4. IEventListener
    - an interface for a class which needs to listen an event
5. CDemoGame
    - a demo class for demostrating the usage of IEventListener

# Further Studies

1. [https://gameprogrammingpatterns.com/observer.html](https://gameprogrammingpatterns.com/observer.html)
