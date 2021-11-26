讨论下amazon price tracker system design。
1. crawler to scan amazon periodically to log product price on local DB (nosql). Skip this step If amazon feed available
2. Pub/Sub ser‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌vice to notificate users

個人覺得這種設計有兩種可能性
1. 假如Amazon有提供notification (ex. Webhook) 去告訴我們的system有price change, 那就可以直接加一個async handler(s)去handle, 然後再trigger一個aggregator去update history, 另外可能有一個notification service去notify users? 這個需要考慮到怎樣去避免丟失那個notification, 因為如果handler死掉, 那個notification就會沒了
2. 假如Amazon沒有以上notification功能, 那我們的system可能要每24小時去crawl product pages, 然後再scan price, 再做以上的steps.
但這種方法可能需要考慮到politeness, 不然會被Amazon當成DDOS.
還有data可能會沒那麼up to date. 但不一定要所有product都去crawl, 可以選擇性去crawl, 例如Amazon's Choice, laptop, popular products等等, 其他那些沒甚麼人買的東西可以lower priority去crawl?
1. 如要要像camelcamelcamel去search by Amazon URL的話, 那可能要一個inverted index去map url to history_id, 那就可以看到history
2. 甚至要顯示graph, min, max, history等等的話, 那就要討論怎樣去aggregate, 怎樣去store那些states, 和query efficiently.

https://www.1point3acres.com/bbs/thread-788379-1-1.html

https://es.camelcamelcamel.com/?utm_campaign=locale_redir&utm_source=C:US-L:ES&utm_medium=www

这个玩意儿可能就是这个price tracker system

我面的是infra, 就是general的面试。拿到这题的时候我也有点慌，只准备了一下newsfeed和typeahead。但是我觉得不用怕，system design翻来覆去，其实底层都是server+db。比如message queue，cache什么的本质上也是db。我觉得你只要follow一定的套路：明确要求，做好back-of-the-envelope计算 , 设计好api, db schema, 画清楚架构图, 讲讲某些选择的trade off，分析一下怎么处理某些component的failure，就差不多了。

谢谢！感觉没什么侧重点。之前复习只准备了高频的newsfeed和typeahead。我认为只要follow套路：明确要求，做好back-of-the-envelope计算 ,讲清楚api, db schema, 画清楚架构图, 讲讲某些选择的trade off，分析一下怎么处理某些component的failure，就差不多了。主要功能就是对于任意商品，可以查看历史价格，所以要有一个async batch processing job去定时抓取亚麻的商品信息。然后subscribe的用户可以收到价格降低的通知，我觉得可以聊聊message queue，或者看看其他notification service怎么设计的。一轮45分钟时间很短的，一下就过去了。个人感觉交流很重要，多顺着面试官的思路说。

如果主要功能讲完了，可以多聊聊怎么crawl price data。

设计一个tracker可以根据amazon url提供历史价格数据



capacity planning and estimation

https://www.youtube.com/watch?v=0myM0k1mjZw



1. 设计uber

2. Web crawler.   botnet crawler
   1. 给你1000个machine，让每个machine既下载又存储，等等。
      请问您被问到的这题有这种要求么？
      还是说存储的cluster和html downloader cluster可以分开
   2. https://leetcode.com/discuss/interview-question/1162048/facebook-or-system-design-or-onsite-or-E4-or-USA
   
3. fb status search **
   1. 设计一个‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌个人状态发布系统，要求支持 updateStatus 和 searchStatus
   2. 问FB状态搜寻，挺常规的，小哥人超级好，还花了三分钟帮我解释functional requirement，给了一些踩点(也就是提示一定要讲相关的概念)，我照套路一路讲下来，画图解释，DB各种分析，sharding优劣，cache改进，等等等等。小哥特别的supportive，中间我讲到每条status需要有一个unique ID，但这个比较複杂，咱先跳过，最后有机会回来讲讲怎麽处理，最后十分钟deep dive小哥人很nice的听懂了我的暗示，叫我解释怎麽样去处理这个uuid的创造方式，我给了一个twitter-snowflake解法，小哥连连点头表示很满意。
   3. https://www.youtube.com/watch?v=KxfYCkZJw8U
   4. https://medium.com/@morefree7/design-facebook-posts-search-10c9aceb6f39

4. Design typeahead suggestion，就对着grokking那套讲了一下。**

5. leetcode contest  着重在api design和data model **

   1. 设计hackerrank，支持多语言，leader board。跟System Design稍有不同就是不需要担心infra的部分，LB/Sharding/Cache这些全部都可以直接用现成的。
      主要细讲了workflow和interface的设计。觉得自己答得还可以。
   2. 主要core function 就是用message queue来防止overload（rate limiting为什么不行), security 用一个container来跑code
   3. Design an Online Judge system 

8. fb messager * 过了一遍

9. design downloader app，聽到題目腦子就空白了
   因為recruiter說會注重在API design上我才挑product design，結果面試官說不要design api部分，assume api is there，還問了我UI/UX怎麼設計，怎麼存data到手機，TCP/UDP...etc
   我覺得我盡力了，面試官卻沒有滿意的樣子。總之假如大家對system design不怕的話還是建議挑system design，product design是迷

8. 设计instagram.就是把不同的service和他们的data schema讲了一遍，画了整个图 **

   1. https://www.1point3acres.com/bbs/thread-586264-1-1.html
   2. 中间问了几个问题: photo upload失败怎么办？需要多少host？
   3. https://www.1point3acres.com/bbs/thread-786323-2-1.html
   4. 就是access control，已经有了valid user，需要判定用户是否可以看到制定图片。这个图片的用户可以设置public private friends only或者friend of friend这些情景，主要是讨论use case和对应的系统设计。table design, data storage等等

9. dropbox 

10. SD design user favorite songs list in the past 7 days **

    SD 是一个facebook music的题，类似于 top K。去youtube看这个channel UC9vLsnF6QPYuH51njmIooCQ ，把里面每个视频看3遍再自己复述，所有的知识点都弄明白，过FB和G的system design应该都没问题。

11. newsfeed 是product design ，主要API design getFeed 这一个 **

    1. newsfeed变种，focus 在了image的cache样子和存储。楼主菜，cache的部分答的烂，没get到考官什么意思。挂点2
    2. 应该是Product Design.
       具体就是design这个API的request parameter和response payload. 需要支持
       infinite loading
       support browser + mobile app
       support @ and # feature in feed text.
       support different types of attachment.
    3. 面试product design的时候，面试官直接开门见山告诉我，说假设所有的backend services都是完美无缺的，只让我讨论workflow，request，response，data model。

12. live 评论 https://www.1point3acres.com/bbs/thread-621854-1-1.html **

    1. https://leetcode.com/discuss/interview-question/583184/fbinstagram-live-comments-system-design
    2. https://dev.to/kutanti/designing-live-commenting-in-youtube-facebook-instagram-live-stream-video-4bec

13. design youtube video service

14. 设计一个系统，可以随时查找一定范围内所有的餐馆 yelp

15. 设计一个ins电商的竞价拍卖功能，假设这样物品有很多‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌人拍卖怎么办

    https://leetcode.com/discuss/interview-question/792060/Bidding-System%3A-System-Design-Interview

    1. 第4轮design一个二手拍卖系统，类似ebay和stockx，卖家挂个商品，买家可以出价。主要是问拍卖的过程，不用考虑付款那些系统。
       先考虑很少的买家和卖家。
       问了数据库设计，product拍卖和每个竞价怎么存，卖家要怎么知道当前出价最高的bid。
       详细说清楚买卖双方的使用流程。卖家放商品的话是哪些操作步骤，买家出价是哪些步骤。
       用户一登录进去怎么浏览所有在卖的商品。是每次在用户登录的时候都select正在卖的商品吗？类似news feed pre-generation。什么时候用pull和push model。

       然后是大量用户的情况。用一些假设的数字计算需要多少存储和机器。
       用户的traffic怎么分流。如果product相关的信息一个table里存不下怎么shard。
       ‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌怎么改进read的serving

       最后2个有点类似开放性问题
       怎么设计tie breaker，有几个用户出价一样怎么办。
       有些用户等到拍卖快结束的最后时刻再出价压倒之前的人，怎么防止这种行为。

       我觉得答得并不好，有些关于read的优化我知道但是没有主动说，想等他问再说，但他也没有问。

16. 翻译设计, 这次以面试官提出问题你来回答为主。 问的有关怎么design不同语言有不同string细节问题偏多，没什么system design的问题。可能后面‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌不同语言不同string，单复数什么的怎么设计问题没答好，和面试官想的不一样，于是被挂掉了。

    https://medium.com/airbnb-engineering/building-airbnbs-internationalization-platform-45cf0104b63c

    https://leetcode.com/discuss/interview-question/386322/Design-a-translator-service-for-facebook

    Client (web/mobile/etc.) posts the message to Facebook service (say Post service) -> this post service persists the data in the Post database and then publishes a notification via RabbitMQ (or something similar) . The notification message includes a post id and to/from language requested.
    A Translation service listens for that topic notification and performs the translation. This service persists the translation in the post db where a link is also created with the original post.
    There could be multiple language specific translation services for efficiency.

https://leetcode.com/discuss/interview-question/system-design/513374/FAANG-system-design-interview-question

1. de‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌sign aggregation system
   1. https://medium.com/pinterest-engineering/building-a-real-time-user-action-counting-system-for-ads-88a60d9c9a





If Software Engineer, Product, then one of the virtual onsite rounds will be a Technical Product Design round: It’s a design round and the focus is typically on the more holistic parts of building a software solution and less focus on the back end components required. A Technical Product Design question typically has a lot more product-oriented questions to be considered and more leeway in terms of the direction that the interview question can go in. **An example question is, “Design the news feed API”. In discussing this question we expect our candidates to explore the problem domain more fully, to think about the entities in the system, a logical data model, potentially the physical data model (how the data is stored within the client and the server), the APIs and the interactions between the servers and clients.** A good rule of thumb for the line between a Systems Design and a Technical Product Design: if the candidate can build the entire product using just AWS components, then that's about the level of systems knowledge we should expect.



Let’s assume we average 1 game/day with 2 users/game: 1 billion / (2 users/game) * 1 game/day → 500 million games per day. If each game lasts 10 minutes each, this equates to around 3.5 million games going on at any one time. Once a game is being played, we don't really expect a huge number of requests (e.g., we might have one for every card being turned over) and the calls themselves won't be expensive. We can expect to be limited by the number of requests a server can handle at any given time, let's say 10,000. This leads to ~350 servers on average, which we can double to ~700 as a good upper bound.



The Product Design interview typically focuses on the more holistic parts of building a software solution and less on the back end components required.



This type of design interview will spend a significant amount of time focusing on a good API. The base expectation is that you consider the product needs and design the API to cater to the specific problem you're working on. A good design will provide a way to extend the API as the product evolves, and also be self-contained such that it is clear that some production changes might require a new API to be built.

You should be able to talk about enabling an efficient interaction between the product running on a client and the server. Do API calls require a single round trip between the client and the server or multiple round trips? If the product is latency sensitive, discuss caching and how that might help. What are the shortfalls of caching, for example, the client might need to store state on the device, which then needs to be secured and managed, or the server might need a good invalidation strategy in case the cache is inconsistent.

If you have client-side experience you should be able to talk about how you handle user interactions like scrolling, page refreshes etc. You will also want talk about how you can improve user experience by masking latency for server interactions by tweaking the client.





API Design两个非常有用的网站

https://www.1point3acres.com/bbs/thread-691382-1-1.html

脸家API Design的一些helpful resources 

https://www.1point3acres.com/bbs/thread-706792-1-1.html

https://www.1point3acres.com/bbs/thread-700703-1-1.html

常见的Facebook Product Design Question

Product design在写requirement的时候要想想use cases有哪些，users是怎样用你的product的。

比如说设计online algorithm competition system的时候要想清楚users是怎样join competition的，join之后怎样得到题目的，然后答题的时候怎样run test cases，最后怎样submit，submit的时候发生什么。这整个过程frontend会需要用到哪些endpoint，每个endpoint的input跟output是什么。

https://www.1point3acres.com/bbs/thread-793367-1-1.html

FB近期系统设计题总结及对策

https://www.1point3acres.com/bbs/interview/facebook-software-engineer-680958.html



https://www.1point3acres.com/bbs/thread-772110-3-1.html



https://www.1point3acres.com/bbs/thread-706792-1-1.html

https://www.1point3acres.com/bbs/thread-301250-1-1.html

https://www.1point3acres.com/bbs/thread-700703-1-1.html

https://www.1point3acres.com/bbs/thread-690792-1-1.html

https://www.youtube.com/watch?v=hykjbT5Z0oE&t=610s