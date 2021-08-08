### Why message queue:

**Synchronous communication** 

advantage

easier and faster to implement

disadvantage:

1. hard to deal with consumer failure
2. need to think not to overwhelm consumer with too many request
3. how to deal with a slow consumer service host

**Message Queue** to implement asynchronous communication



### Requirements

Funtional 

- sendMessage(messageBody)
- receiveMessage()

Non-funtional

- Scalable(handles load increases, more queues and messages)
- Highly Available(survives hardware/ network failures)
- Highly Performant(single digit latency for main operations)
- Durable(onced submitted, data never lost)