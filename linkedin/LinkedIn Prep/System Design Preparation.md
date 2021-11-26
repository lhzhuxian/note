# Web App and Software Architecture

## N Tiers App / Distributed Application

Tiers: component divided by physical location. 

### Example of components

- *Cache*
- *Message queues for asynchronous behavior*
- *Load balancers*
- *Search servers for searching through massive amounts of data*
- *Components involved in processing massive amounts of data*
- *Components running heterogeneous tech commonly known as web services* etc.



### Reason for using N Tiers

Single Responsibility Principle and Separation Of concerns

### Layers of Web Application (Code Level)

![app_layers](C:\Users\cljmars\Pictures\system\app_layers.jpg)

### High Level Web App Architecture

![app_arch](C:\Users\cljmars\Pictures\system\app_arch.jpg)

### Client-Server Architecture

Holds user interface which is the presentation part of the application. Written with HTML, CSS and JS.![client server](C:\Users\cljmars\Pictures\system\client server.jpg)

#### Thin Client

*Thin client* is the client that holds just the user interface of the application. It has no business logic of any sort. For every action, the client sends a request to the backend server. Just like in a *three-tier* application.

#### Thick Client

On the contrary, the thick client holds all or some part of the business logic.

#### Rest Endpoint

An *API/REST/Backend* endpoint means the *URL* of a service. For example, `https://myservice.com/users/{username}` is a backend endpoint for fetching the user details of a particular user from the service.

The *REST-based* service will expose this *URL* to all its clients to fetch the user details using the above stated *URL*.

#### API Gateway

#### ![api gateway](C:\Users\cljmars\Pictures\system\api gateway.jpg)

The *REST-API* acts as a gateway, or a single-entry point into the system. It encapsulates the business logic and handles all the client requests, taking care of the authorization, authentication, sanitizing the input data, and other necessary tasks before providing access to the application resources.

So, now you are aware of the client-server architecture and we know what a *REST API* is. It acts as the interface, and the communication between the client and the server happens over HTTP.

#### Http Push

![Http push](C:\Users\cljmars\Pictures\system\Http push.jpg)

Why we need it?

- When application is real-time application like MMORPG, Live Streaming.
- When we need to reduce the number of client requests hitting the server every now and then, checking for new information.
- When we are certain that the response time of the server will be more than the TTL set by the browser.
- When the frequency of request and response between the client and the server is high.

Keep communication alive between client and server. We can use Web Sockets, AJAX long polling, HTML5 Event-Source API and Server-Sent Events, and Stream over HTTP.

- AJAX is used to dynamically update the web page by polling the server at regular intervals. AJAX Long polling has a connection open time slightly longer than the polling mechanism.
- Web Sockets have bi-directional data flow, whereas server-sent events facilitate data flow from the server to the client.
- Streaming over HTTP facilitates the streaming of large objects like multi-media files.

### Client and Server Side Rendering

For Client side rendering, the browser has several components, such as the:

- *Browser engine*
- *Rendering engine*
- *JavaScript interpreter*
- *Networking and the UI backend*
- *Data storage* etc.

However, we can leverage a hybrid approach, to get the most out of both techniques. We can use server-side rendering for the home page and for the other static content on our website and use client-side rendering for the dynamic pages.

## Scalability

### What is Scalability

![Scalability](C:\Users\cljmars\Pictures\system\Scalability.jpg)

Scalability means the ability of the application to handle and withstand increased workload without sacrificing the latency.

For instance, if your app takes x seconds to respond to a user request. It should take the same x seconds to respond to each of the million concurrent user requests on your app.

The backend infrastructure of the app should not crumble under a load of a million concurrent requests. It should scale well when subjected to a heavy traffic load and should maintain the latency of the system.

### What is Latency

*Latency* is the amount of time a system takes to respond to a user request. Let’s say you send a request to an app to fetch an image and the system takes 2 seconds to respond to your request. The latency of the system is 2 seconds.

Minimum latency is what efficient software systems strive for. No matter how much the traffic load on a system builds up, the latency should not go up. This is what scalability is.

Let’s think of scalability in terms of *Big-O notation*. Ideally, the complexity of a system or an algorithm should be *O(1)* which is *constant time* like in a Key-value database.

A program with the complexity of *O(n^2)* where n is the size of the data set is not scalable. As the size of the data set increases the system will need more computational power to process the tasks.

#### Network latency

Network latency is the amount of time that the network takes to send a data packet from point A to point B. The network should be efficient enough to handle the increased traffic load on the website. To cut down the network latency, businesses use CDN and try to deploy their servers across the globe as close to the end-user as possible.

#### Application latency

Application latency is the amount of time the application takes to process a user request. There are more than a few ways to cut down the application latency. The first step is to run stress and load tests on the application and scan for the bottlenecks that slow down the system as a whole. 

### Pros and cons of vertical and horizontal scaling

This is the part where I talk about the pluses and minuses of both approaches.

Vertical scaling for obvious reasons is simpler in comparison to scaling horizontally because we do not have to touch the code or make any complex distributed system configurations. It takes much less administrative, monitoring, and management efforts as opposed to managing a distributed environment.

A major downside of vertical scaling is availability risk. The servers are powerful but few in number. There is always a risk of them going down and the entire website going offline, which doesn’t happen when the system is scaled horizontally. It becomes more highly available.

### Primary Bottlenecks That Hurt the Scalability of our Application

#### Single Database or Add business logic to the database

Single database might cause high response latency. Just like workload scalability, the database needs to be scaled well.

Make wise use of database partitioning, sharding, and multiple database servers to make the module efficient.

#### Application architecture

A poorly designed application’s architecture can become a major bottleneck as a whole.

A common architectural mistake is not using asynchronous processes and modules whereever required rather all the processes are scheduled sequentially.

#### No Caching

Caching can be deployed at several layers of the application and it speeds up the response time by notches. It intercepts all the requests going to the database, reducing the overall load.

#### Improper Load Balancer

Load balancers are the gateway to our application. Using too many or too few of them impacts the latency of our application.

### Tuning the performance of the application – Enabling it to scale better.

#### Profiling

*Profile* the hell out of your app. Run *application profiler* and *code profiler*. See which processes are taking too long and which are eating up too many resources. Find out the bottlenecks. Get rid of them. It helps us measure the space and the time complexity of our code and enables us to figure out issues like concurrency errors, memory errors and robustness and safety of the program.

#### Caching 

*Cache* wisely, and cache everywhere. Cache all the static content. Hit the database only when it is really required. Try to serve all the read requests from the cache. Use a write-through cache.

#### CDN 

Use a *Content Delivery Network (CDN)*. Using a CDN further reduces the latency of the application due to the proximity of the data from the requesting user.

#### Data compression

*Compress data*. Use apt compression algorithms to compress data, and store data in the compressed form. As compressed data consumes less bandwidth, consequently, the download speed of the data on the client will be faster.

#### Avoid unnecessary client server requests 

*Avoid unnecessary round trips* between the client and server. Try to club multiple requests into one.

These are a few of the things we should keep in mind in the context of application performance.

## High Availability

High availability, also known as *HA*, is the ability of the system to stay online despite having failures at the infrastructural level in real-time. In the industry, HA is often expressed as a percentage. For instance, when the system is *99.99999%* highly available, it simply means *99.99999%* of the total hosting time the service will be up. You might often see this in the Service Level Agreements (SLA) of cloud platforms.

### Reasons For System Failures

- Software crashes
- Hardware failures
- Human errors
- Planned downtime

### Fault Tolerance

*Fault tolerance* is a system’s ability to stay up despite taking hits. To achieve high availability at the application level, the entire massive service is architecturally broken down into smaller loosely coupled services called **micro services**, even if a few services go down the application as a whole is still up.

There are many upsides of splitting a big monolith into several micro services, as it provides:

- Easier management
- Easier development
- Ease of adding new features
- Ease of maintenance
- High availability

### Redundancy

### ![HA redundancy](C:\Users\cljmars\Pictures\system\HA redundancy.jpg)

Redundancy is duplicating the components or instances and keeping extras on standby to take over in case the active instances go down. It is the fail-safe, backup mechanism.

### Replication

![HA replication](C:\Users\cljmars\Pictures\system\HA replication.jpg)

Replication means having a number of similar nodes running the workload together. There are no standby or passive instances. When a single or a few nodes go down, the remaining nodes bear the load of the service. Think of this as load balancing. All the components of the system are active at any point in time.

### HA Clustering

![HA clustering](C:\Users\cljmars\Pictures\system\HA clustering.jpg)

A *high availability cluster* also known as the *fail-over cluster*, contains a set of nodes running in conjunction with each other that ensures high availability of the service.

The nodes in the cluster are connected by a private network called the *heartbeat network* that continuously monitors the health and the status of each node in the cluster.

A single state across all the nodes in a cluster is achieved with the help of a shared distributed memory and a distributed coordination service like the *Zookeeper*.

## Load Balancing

![load balancer health](C:\Users\cljmars\Pictures\system\load balancer health.jpg)

Load balancing is vital in enabling our service to scale well with an increase in traffic load, as well as stay highly available. Load balancing is facilitated by load balancers, which makes them a key component in the web application architecture.

### DNS Querying

![DNS lookup](C:\Users\cljmars\Pictures\system\DNS lookup.jpg)

There are four key components, or a group of servers, that make up the DNS infrastructure. These are:

- *DNS Recursive nameserver aka DNS Resolver*
- *Root nameserver*
- *Top-Level Domain nameserver*
- *Authoritative nameserver*

### DNS Load Balancing

![DNS load balancing](C:\Users\cljmars\Pictures\system\DNS load balancing.jpg)

*DNS load balancing* enables the *authoritative server* to return different *IP addresses* of a certain domain to the clients. Every time it receives a query for an *IP*, it returns a list of *IP addresses* of a domain to the client.

When another client sends out a request for an *IP address* to the *authoritative server*, it re-orders the list and puts another *IP address* at the top of the list following the *round-robin algorithm*.

Also, when the client hits an *IP*, it may not necessarily hit an application server. Instead, it may hit another load balancer implemented at the data center level that manages the clusters of application servers.

#### Limitations

It does not take into account the existing load on the servers, the content they hold, their request processing time, their *in-service* status, and so on. Also, since these *IP addresses* are cached by the client’s machine and the *DNS Resolver*, there is always a possibility of a request being routed to a machine that is out of service.

### Load Balancing Methods

There are primarily three modes of load balancing:

1. *DNS Load Balancing* 
2. *Hardware-based Load Balancing*
3. *Software-based Load Balancing*  HAProxy

## Message Queue

![message queue](C:\Users\cljmars\Pictures\system\message queue.jpg)

Message queue, as the name says, is a *queue* that routes messages from the source to the destination, or from the sender to the receiver. Message queues enable us to run background processes, tasks, and batch jobs. Queuing tech widely used in the industry, are *RabbitMQ*, *ActiveMQ*, *Apache Kafka*, etc.

### Publish-Subscribe Model

![pub-sub mode of message queue](C:\Users\cljmars\Pictures\system\pub-sub mode of message queue.jpg)

A *publish-subscribe(pub-sub)* model is the model where multiple consumers receive the same message sent from a single or multiple producers.

### Point-to-Point Model

### ![point to poiont model of message queu](C:\Users\cljmars\Pictures\system\point to poiont model of message queu.jpg)

The use case for * Point-to-point* communication is pretty simple. It’s where the message from the producer is consumed by only one consumer.

# Database

- Structured data eg: SQL
- Unstructured data eg: image, video
- Semi-structured data eg: JSON, XML

**Note:** A well-designed SQL data store will always be more performant than a not so well-designed NoSQL store.

## When to use Relational Database?

- When you want transactions and data consistency. Like dealing with stock and money.
- When you want to store relationship.

## NoSQL Database

NoSQL database is more like *JSON-based* databases built for Web 2.0

They are built for high-frequency read and writes, typically required in social applications like Twitter, LIVE real-time sports apps, online massive multiplayer games, etc.

They have better **Scalability** than relational database. It have the ability yo add new server nodes on the fly.

However, NoSQL database is more eventually consistent instead of being strongly consistent.

### Pros:

- Schema-less, more flexible, not join and relationships.
- Easy to learn.

### Cons:

- Inconsistency, data is not normalized.
- Not support for ACID transactions, some of them support ACID within the limited range.

### When to use NoSQL database

- Handling large number of read write operations. Since NoSQL databases have the ability to add nodes on the fly, they can handle more concurrent traffic and bigger amounts of data with minimal latency.
- Flexibility with data modeling. Don't need to worry about your data modeling during the initial phases.
- Eventual consistency over strong consistency. It’s preferable to pick *NoSQL* databases when it’s okay for us to give up *strong consistency* and when we do not require *transactions*. Like B站点播数量, there is no much differences between 1M and 1M and 500.  The value of the entity eventually becomes consistent after a short while. This is what *eventual consistency* is.

## Polyglot Persistence

![polyglot](C:\Users\cljmars\Pictures\system\polyglot.jpg)

*Polyglot persistence* means using several different persistence technologies to fulfil different persistence requirements in an application.

![multimodel db](C:\Users\cljmars\Pictures\system\multimodel db.jpg)

We can also use multi-model databases to use different data model in single database system. Eg: *ArangoDB*, *CosmosDB*, *OrientDB*, and *Couchbase*.

## CAP Theorem

*CAP* stands for **consistency**, **availability**, **partition tolerance**.

*The CAP theorem* simply states that in case of a network failure, when a few of the nodes of the system are down, we have to make a choice between *availability* and *consistency*

If we pick *availability*, this means when a few nodes go down, the other nodes are available to the users for making updates. In this situation, the system is inconsistent because the nodes that are down don’t get updated with the new data. When they come back online, if a user fetches the data from them, they’ll return the old values they had when they went down.

If we pick *consistency*, in this scenario, we have to lock down all the nodes for further writes until the nodes that have gone down come back online. This ensures the *strong consistency* of the system because all the nodes will have the same entity values.

## Types of Different Databases

### Document-Oriented Database

*Document-oriented databases* are the main types of *NoSQL* databases. They store data in a document-oriented model in independent documents. The data is generally *semi-structured* and stored in a *JSON*-like format.

Some of the popular document-oriented stores used in the industry are *MongoDB, CouchDB, OrientDB, Google Cloud Datastore, and Amazon DocumentDB*.

Typical use cases of document-oriented databases include:

- Real-time feeds
- Live sports apps
- Writing product catalogues
- Inventory management
- Storing user comments
- Web-based multiplayer games

### Graph Database

![graph db](C:\Users\cljmars\Pictures\system\graph db.jpg)

Each *node* in a graph database represents an entity. It can be a person, a place, a business, etc., and the *edge* represents the relationship between the entities.

Good for visualization, low latency due to no query time like join since the relationship is maintained with edges and nodes.

A good real-life example of an application that would fit a graph database is Google Maps. *Nodes* represent the cities, and the *edges* represent the connections between them. Now, if I have to look for roads between different cities, I don’t need *joins* to figure out the relationship between the cities when I run the query. I just need to fetch the edges, which are already stored in the database.

Ideal use cases of graph databases are building social, knowledge, and network graphs, writing AI-based apps, recommendation engines, and fraud analysis apps, storing genetic data, etc.

### Key-Value Database

*Key-value* databases also are a part of the *NoSQL family*. These databases use a simple *Key-value* method to store and quickly fetch the data with minimum latency. Due to the minimum latency they ensure, a primary use case for the *Key-value* databases is to implement caching in applications.

Some of the popular *key-value* data stores used in the industry are *Redis*, *Hazelcast*, *Riak*, *Voldemort*, and *Memcached*.

Typical use cases of a *key-value* database are the following:

- Caching
- Persisting user state
- Persisting user sessions
- Managing real-time data
- Implementing queues
- Creating leaderboards in online games and web apps
- Implementing a pub-sub system

### Time Series Database

*Time-series* data is primarily used for running analytics, deducing conclusions and making future business decisions by looking at the results of the analytics. Running analytics also helps the product evolve continually.

### Wide-Column Database

*Wide-column* databases belong to the *NoSQL* family of databases, primarily used to handle massive amounts of data, technically called the *Big Data*. Also known as *column-oriented* databases *wide-column* databases store data in a record with a dynamic number of columns. A record can hold billions of columns.

Some of the popular wide column databases are *Cassandra*, *HBase*, *Google BigTable*, *ScyllaDB*, etc.

*Wide-column* databases are built to manage Big Data ensuring *scalability*, *performance* and *high availability* at the same time.

## Caching

![cache server](C:\Users\cljmars\Pictures\system\cache server.jpg)

*Caching* is key to the performance of any kind of application. It ensures *low latency* and *high throughput*. An application with caching will certainly do better than an application without caching, simply because it returns the response in less time as opposed to the application without a cache implemented.

It’s always a good idea to use a cache as opposed to not using it. It doesn’t do any harm and cut down the load on the databases. Like more *SQL Join* means more latency, a cache can reduce the need for running join every time. 

Implementing caching in a web application simply means copying frequently accessed data from the database, which is *disk-based* hardware, and storing it in *Random Access Memory (RAM)* hardware.

They can be used for *cross-module communication* in a *microservices* architecture by saving the shared data which is commonly accessed by all the services. It acts as a backbone for the *microservice* communication.

### Caching dynamic data

Data with a expiry time or a TTL, after that, the data will be purged from cache and updated data is stored in it. This process is known as cache invalidation.

### Caching static data

Data like image, font files, CSS doesn't change often and can easily be cached on client-side in their browser, it can also be stored on the **Content Delivery Networks (CDNs)**.

### Caching Strategies

#### Cache aside 缓存读，若cache miss则直接读DB

The data is *lazy-loaded* in the cache. When the user sends a request for particular data, the system first looks for it in the cache. If present, it is simply returned. If not, the data is fetched from the database, and the cache is updated and returned to the user.

This kind of strategy works best with *read-heavy* workloads and data that is not updated frequently like user profile data.

The data in this strategy is written directly to the database. This means that the data present in the cache and the database could become inconsistent. To avoid this, data on the cache has a TTL. After the stipulated period, the data is invalidated from the cache.

#### Read-through 缓存读，若cache miss则由backend logic (cache provider) 加载到缓存中

Similar to cache aside, but cache always stays consistent with the database.

The cache library, or the framework, takes the onus of maintaining consistency with the backend. The information in this strategy, is also *lazy-loaded* in the cache, only when the user requests it.

So, for the first time, when information is requested, it results in a cache miss. Then, the backend has to update the cache while returning the response to the user.

Both cache aside and read-through might meet cache miss (no target data in cache), can be optimized by preloading data into cache.

#### Write-through 缓存写，由cache provider将数据同步写入DB和Cache

In this strategy, each and every information written to the database even goes through the cache. Before the data is written to the DB, the cache is updated with it.

This maintains high consistency between the cache and the database even though it adds a little latency during the write operations because the data is updated in the cache separately. This works well for write-heavy workloads like online massive multiplayer games.

#### Write-back 缓存写，定期将缓存的数据写入DB，异步

This strategy helps optimize costs significantly. In the *write-back* caching strategy the data is directly written to the cache instead of the database, and the cache after some delay, as per the business logic, writes data to the database.

If there are quite a heavy number of writes in the application, developers can reduce the frequency of database writes to cut down the load and the associated costs.

A risk in this approach is if the cache fails before the DB is updated, the data might get lost. Again, this strategy is used with other caching strategies to make the most out of them.





