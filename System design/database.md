## indexing



Partition

partition不是必须的 The main reason for partition data is **scalability**

选择sql 和 nosql 的driven factor不是scalability

Replication: keeping a copy of the same data on several different nodes, potentially in different locations. Replication provides redundancy.

Partition: splitting a big databse into smaller subsets called partitions so that different partions can be assigned to different nodes(sharding)





Partition 经常出现的问题 hot spot. All the load could end up on one partition, so other nodes are idle and your bottleneck is the single busy node.



sql:

NoSql: dynomoDB



### Methods of partioning of key-value data

#### Partition by Range Key

advantage: range scans are easy

Disadvantage: certain access patterns can lead to inbalanced and hot spot. 

#### Partition by Hash Key

MongoDB uses MD5, Cassandra uses Murmur3, Voldemort uses the Fowler-Noll-Vo Fucntion

Once you have a suitable hash function for keys, you can assign each partion a range of hashes and every key whose hash falls within a partion's range will be stored in that partition.

UUID: Universally Unique Identifier 128-bit integer 

Advantage: Uniform distributed

Disadvantage: lost the ability to do efficient range queries

Cassandra achieves a compromis between the two partitoning strategies. A table in Cassandra can be decalared with a **compound primary key** consisting of several columns. Only the first part of that key is hashed to determing the partition. but the othre columns are used as a concatenated index for sorting the data in casssandrea's SSTables. A query therefore cannot search afor a range of values within the first column of a compound key, but if it specifies a fixed value for the first column. It can perform an efficient rage scan over the other columns of the key



### Hot Spot

In the extreme case where all reads and wirtes are for the same key, you still end up with all requests being routed to the same partition. Example: Twitter hot user

Most data systems are not able to automatically compensate for such a highly skewed workload.So it's the responsiability of the application to reduce the skew. For example, if one key is known to be very hot, a simple technique is to add a random number to the beginning or end of the key, allowing those keys to be distributed to different partitions.  

It only make sense to append the random number for the small number of hot keys. For the vast majority of keys with low write throughput this would be unneccessary overhead. Thus, you also need some way of keeping track of which keys are being split.



### Secondary Indexes

#### local/ document secondary index

在本地来做这个secondary index， 写很快，但读的时候需要query 所有的partiion 然后combine all the result you get back（scatter / gather)



Global / term secondary index

read more efficient, a client onlyu needs to make a request to the partition containing the term that it wants. However, the downside of a global index is that writes are slower and more complicated, because a write to a single document may now affect multiple partitions of the index

















- Structured data eg: SQL
- Unstructured data eg: image, video
- Semi-structured data eg: JSON, XML

**Note:** A well-designed SQL data store will always be more performant than a not so well-designed NoSQL store.



## Relational database management system(RDBMS)

### Transactions



### ACID

**ACID** is a set of properties of relational database [transactions](https://en.wikipedia.org/wiki/Database_transaction).

- **Atomicity** - Each transaction is all or nothing
- **Consistency** - Any transaction will bring the database from one valid state to another
- **Isolation** - Executing transactions concurrently has the same results as if the transactions were executed serially
- **Durability** - Once a transaction has been committed, it will remain so







## When to use Relational Database?

- When you want transactions and data consistency. Like dealing with stock and money.
- When you want to store relationship.

## NoSQL Database

Driving points for NoSQL database:

1. a need for greater scalability
2. preference for free and open source software over commercial database products
3. specilized query operations that are not well supported by the relational model
4. Frustration with the restrictivenss of relational schemas and a desire for a more dynamic and expressive data model
5. Object-relational mapping is required between the objects in the application code and the database model of tables, rows and columns. The disconnect between the models is sometimes called an impedance mismatch





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



https://www.infoq.cn/article/j0mfq1cntskbk5rbdpvl