Push notification

------

Search status，或者叫twitter search，一般要求real time，仅限text post。可以[参考](https://blog.twitter.com/engineering/en_us/a/2011/the-engineering-behind-twitter-s-new-search-experience) 

------

Aggregation system，一般会考虑到fast和slow两种cases

------

Design Yelp，经典题目，quadtree或者grid，geohash我自己没多看，觉着重点不在这里

------



- Translation syste，两种思路，一个是google translate这种，你可以assume已经有一个现成可用的translation service，然后你要设计一个系统满足三高。另外一个思路可以借鉴一下airbnb的翻译系统 https://medium.com/airbnb-engine ... atform-45cf0104b63c
- News feed
- Design Netflix
- i18n，参见上面说的airbnb的翻译系统
- Collaborative doc editing，就是设计个google doc
- Subscription system，比如说youtube的subscription
- Hashtag trend，类似于topK，YouTube上有个视频讲的挺好 🔗www.youtube.com，另外我也很推荐这个哥们儿的channel
- Live commenting system，个人感觉这个地方偏重考database
- KV store，经典题，主要靠怎么满足三高
- Design Facebook Messenge，要求能做到group chat
- Design Instagram
- Proximity server backend，参考design Yelp
- Design load balancer，要求包含balance servers的workload的功能
- Ad click counter，参考前面的hashtag trend，只是有相似之处并不完全相同，考虑slow和fast两种实现可能都需要
- Web crawler，看到大家提到的都是需要跑在botnet上，我自己能想到的就是中控server负责存储、判重，还有负责给bot们发命令，命令里面包括url。Bots们接收命令，下载网页，解析文字和urls，然后把网页文字内容和URLs发回给中控server。另外中控server要能做到三高。
- Design typeahead suggestions，也就是autocomplete，经典题
- Design privacy settings at Facebook，几个privacy类型，比如说public可见，只能朋友看，只能朋友和朋友的朋友看，只能自己看