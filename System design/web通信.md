Commnunication protocols between a client (web browser) and a web server.

### Ajax Polling

传统轮询，间隔一段时间就发一个request给server，如果没有data 就返回一个空的response

缺点很明显：程序每发出一次请求就要新建一个Http请求。因为发起Http请求时会有很多头部信息，真正的请求信息几乎很少，这样就会造成资源浪费， HTTP overhead



### HTTP Long-Polling

而长轮询意味着浏览器只需启动一个HTTP请求，其连接的服务器会“hold”住此次连接，直到有新消息才返回响应信息并关闭连接，客户端处理完响应信息后再向服务器发送新的Http请求,以此类推。（其实还是http 短连接）

轮询可能在以下3种情况时终止。

> - 有新数据推送 。当服务器向浏览器推送信息后，应该主动结束程序运行从而让连接断开，这样浏览器才能及时收到数据。
> - 没有新数据推送 。应该设定一个最长时限，避免WEB服务器超时（Timeout），若一直没有新信息，服务器应主动向浏览器发送本次轮询无新信息的正常响应，并断开连接，这也被称为“心跳”信息。
> - 网络故障或异常 。由于网络故障等因素造成的请求超时或出错也可能导致轮询的意外中断，此时浏览器将收到错误信息。

- 优点：在无消息的情况下不会频繁的请求，耗费资源小。
- 缺点：服务器hold住连接会消耗资源，返回数据顺序无保证，难于管理维护



### WebSockets

WebSocket provides [Full duplex](https://en.wikipedia.org/wiki/Duplex_(telecommunications)#Full_duplex) communication channels over a single TCP connection

通过WebSocket handshake 来建立连接， 然后server 和 client可以互相接发消息

advantage：full duplex， lower overhead， facilitating real-time data transfer from and to the server， 

### Server-Sent Events

Under SSEs the client establishes a persistent and long-term connection with the server

server可以发送消息给client，但client需要通过其他的protocol来发送消息给server

1. Client requests data from a server using regular HTTP.
2. The requested webpage opens a connection to the server.
3. The server sends the data to the client whenever there’s new information available.

SSEs are best when we need real-time traffic from the server to the client or if the server is generating data in a loop and will be sending multiple events to the client.