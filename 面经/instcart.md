## Time Based Key-Value Store

Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the `TimeMap` class:

- `TimeMap()` Initializes the object of the data structure.
- `void set(String key, String value, int timestamp)` Stores the key `key` with the value `value `at the given time `timestamp`.
- `String get(String key, int timestamp)` Returns a value such that `set` was called previously, with `timestamp_prev <= timestamp`. If there are multiple such values, it returns the value associated with the largest `timestamp_prev`. If there are no values, it returns `""`.

**Example 1:**

```
Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "ba2r" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"
```

**Solution**

```
依旧是利口981，一共三题。
第一题
kv = KV.new
kv.set('foo', 'bar')
kv.get('foo')
=>  "bar"

第二题
kv = KV.new
timestamp = kv.set('foo', 'bar')
sleep(1)
kv.set('foo', 'bar2')

# Fetch the key 'foo' with the correct timestamp
kv.get('foo', timestamp)
=> "bar"

# Fetch the key 'foo' without a timestamp
kv.get('foo')
=> "bar2" # returns the last set value

第三题
kv = KV.new
timestamp = kv.set('foo', 'bar')
sleep(1)
kv.set('foo', 'bar2')

# The case of no timestamp should continue to return the latest set value
kv.get('foo')
=> "bar2"

# Fetch the key 'foo' with the initial timestamp, plus 750 milliseconds
kv.get('foo', timestamp + 0.75)

=> "bar" # returns the closest set value to that timestamp‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌, but always in the past

需要知道如何获取目前得timestamp，in Java, 可以用System.currentTimeMillis(), 以及如何做thread sleep。

```



```java


3. System design - 设计 shopper swipe credit card 的时候的 risk evaluation
这题在论坛里被提到过几次。面试官会先描述一下这个场景，然后说 issuer bank 会来 call instacart 的 api, 并给了一个 sample payload, 然后要面试者描述背后怎么实现。楼主没领悟到其中的奥秘，就设计了几张 db table, 然后根据 input doll‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌ar amount 去尝试猜一个 open order, 然后结合一些别的信息来判断是否 reject transaction. 面试官在过程中并没有问太多的问题。

4. Coding
Password decoder. 主要考察文件基本读写和简单的 string parsing, 给定一个文件格式，要求按照 spec 输出字符。此题相当简单，楼主平时搬砖还挺熟练的，这题为了一雪前耻，做的更加认真了， 不到25分钟， 就完成了3个小题。对方表示问不出问题了， 提早收工。
```



## indexOf

实现 string.indexOf, 不能用 indexOf 

The `indexOf()` method returns the position of the first occurrence of specified character(s) in a string.

**follow up**

pattern 里带有 `*`

1.2是蠡口肆拾肆的简化版

**Solution**

这里和 LC 的 wildcard 不太一样，LC 的是完整匹配， 这个是返回 index. 楼主在这里卡壳了，没把逻辑整理好就开始写代码，过不了 case 以后急躁了，越改越错。最后没能完成这题的所有 case. 事后楼主重新尝试了一下，思路理清以后， 十分钟就搞定了。属于不幸卡壳没能自救回来的例子。

```
```



## shopper swipe credit card

这题在论坛里被提到过几次。面试官会先描述一下这个场景，然后说 issuer bank 会来 call instacart 的 api, 并给了一个 sample payload, 然后要面试者描述背后怎么实现。楼主没领悟到其中的奥秘，就设计了几张 db table, 然后根据 input doll‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌ar amount 去尝试猜一个 open order, 然后结合一些别的信息来判断是否 reject transaction. 面试官在过程中并没有问太多的问题。

Design 是shopper payment verification，被两个staff老哥轮番轰炸，每个decision都需要非常有理有据。takeaway（因人而异！） 是争取做一些business decision，或者实际开发中的decision： 比如我们需要从别的team的table里拿data，是否直接query他们的DB？如果他们有内部API但是特别慢，怎么办？再比如payment timeout的时候可以不retry，直接让user重来一遍（这样简化server这边的逻辑）



## Password decoder



## Shoppers pickup order

情景是shoppers从某location pickup order，然后deliver到另一个location，要求计算从某个地点到另个地点的average travel time。让你implement这些函数。
public void pickup(int timestamp, String pickUpLocation, int shopperId)
public void deliver(int timestamp, String, DeliverLocation, int shopperId)
public double calculateAverage(String locationA, String locationB)

比如 shopper1 在时间 0 从 地点 A pickup 了order，‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌在时间5 地点B 放下了order
shopper2 在时间0 从地点A pickup了order， 在时间6 地点B 放下了order
那calculateAverage（A, B) 就返回 1.0*(5 + 6)/2 = 5.5

1. 只需要考虑直接deliver的情况，不需要考虑类似已知 A-B, B-C, 求A-C。
2. input都是顺序的，不会出现（shoper1, pickup1, time0), (shoper1, pickup2, time2), (shoper1, deliver1, time1), (shoper1, deliver2, time3) 这样乱序的pickup & deliver。
3. 需要自己设计test case，并且编译跑通

