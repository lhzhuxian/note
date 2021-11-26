BQ

最骄傲的项目，解决冲突，leadership



product design

也可能是另一個掛的原因，我挑了product design，題目是design downloader app，聽到題目腦子就空白了
因為recruiter說會注重在API design上我才挑product design，結果面試官說不要design api部分，assume api is there，還問了我UI/UX怎麼設計，怎麼存data到手機，TCP/UDP...etc
我覺得我盡力了，面試官卻沒有滿意的樣子。總之假如大家對system design不怕的話還是建議挑system design，product design是迷

newsfeed变种，focus 在了image的cache样子和存储。楼主菜，cache的部分答的烂，没get到考官什么意思

刚开始说了CDN来cache住图片，但是面试官想问的是image url的cache，就是常见的合并newsfeed那些，但是这里合并的是image不是newsfeed。应该需要围绕push和pull model对cache设计的影响进行讨论。我之前准备的都是db层面的东西以及push和pull model的优缺点，没有准备过具体这两种model下cache如何设计。所以是大挂点。

Design INS.

system design

sd:‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌ 设计leetcode，着重在api design和data model



SD: status search

autocomplete

fb messager

Design typeahead suggestion，就对着grokking那套讲了一下。

------

Design si‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌mple photo sharing app，其实就是简化版的Instagram，三个功能：上传图片，下载图片，生成首页的feed。

没有那么深入，我就提了一下按题目需求的access pattern来说photo metadata用个NoSQL wide-column DB就足够了，horizontal scaling比较方便，面试官也没问什么深入的了。我倒是主动提到了照片存blob storage (因为可能会很大) 外加CDN来提高访问速度，面试官也没多问具体选择什么blob storage系统。

------

botnet crawler

------

leetcode contest

https://www.youtube.com/watch?v=eg0nlYcbLpo



coding

Coding。第一题是给两个排序好的int数组a和b，其中a数组更长，末尾有额外空间刚好能把b数组里面的数字都放进去，要求把两个数组里面的数字都合并到a数组里面并且最后是排好序的，这个题面试官要求线性时间完成。第二题是蠡口饵丝酒原题，Caesar cipher相关的。
Coding。第一题是实现个简单的atoi，不需要处理out of bound的情况，不过需要问清楚各种edge case。第二题是蠡口柳汽酒，区别在于用除法的时候必须要能整除才行，楼主直接DFS+Backtracking暴力做的，但是Java没有multiset这个数据结构，实现起来还是有点蛋疼，最后就拿List来保存状态，然后解释了一下Java没有multiset的问题以及用multiset的好处。





非原题，隐藏string信息到图片。这题就更崩溃，没有做过类似的题目，心里顿时很慌，加上小哥的法国口音实在很重，有些就没有太听懂。后来基本是小哥基本告诉了我算法，我写出了代码。他还鼓励鼓励了我。



1570 

hashmap memory overhead还是太高  用了merge two sorted list方法解了



十六进制加法

616，是tag题，但可惜我没做过，太纠结于更好的找字符串的方法，后来开始暴力求了start， end，然经过提示
用了merge interval的思路解了。



coding：共同祖先，follow up是假如tree是BST / n-ary可以怎麼改code

coding：k-th largest / smallest in array，我用了min heap做，follow up是假如不用heap有什麼別的方法

coding：
這輪應該是掛的原因，第一題是verify外星人字典，不難，然而第二題我從沒見過，類似trap雨水題，但要的是可以trap雨水的pair數量，只想得出brute force，然而面試官想要linear time

https://www.1point3acres.com/bbs/thread-785638-1-1.html



4 第一题减少最少括号make valid 第二题 距二维矩阵某个点最远的点 ‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌
5 第一题 N茶🌲的深度， 第二题 给定字符串最长回文



346

173 preorder

就是原题是in-order iterator，现在要求实现pre-order iterator。我个人感觉你说的这个方法可能不行，我感觉iterator类题目所有的解法都不能用倒腾到list然后用list iterator这个解法，如果数据太大没法压入内存怎么办。我个人感觉iterator类题都是为了simulate这种情况，需要一个个按需给值。另外，非死不可一定会让你实现到最优的状态。原题是用iterative stack的方式，现场面试我用的也是stack，只不过是变成了pre-order的压栈方式，弹出top，然后先压右，再压左。楼主菜，想法仅供参考。。。

1004

977

1570

假设大部分都是一个非0数字怎么办，solution：存minority的val和idx。

1428

219

528

977

Coding 1:
原谅我不能熟练背出题号但是是lc原题，implement一个hashmap，实现set/get/last/delete ，要求last返回最近access的entry
第二道是滑动窗口找窗口的平均值

感谢楼上指出，第一部分coding类似LRU但没有size限制，并且要实现delete(key)和getlast()的调用
第二部分的那道是酒灵气变型，都是可以用monotonous stack实现最优解，只要会做酒灵气做这道题应该是没问题

Coding 2:
就灵气 + 气凌吧



coding:

1. 尔幺舞

2. 尔拔尔 简化版只有+ -， followup，怎么优化

3. 没找到原题，given a list of bytes, 判断最后一个byte是1个byte还是2个byte的一部分。 LC717
   1 byte: 0xxxxxxxx  <- 以‘0’开头
     2 byte: 1xxxxxxxx xxxxxxxx  <- 如果有byte是‘1’开头，那连着两个就是part of 2-byte character
     e.g.
     01010000     10101111      01011100        11001111
     ^ 1 byte      ^2 byte(1st)   ^2byte (2nd)   ^2byte (1st)

  第三题不是散就散。lz一开始也给了个O(n)从头扫到尾的解法，后来想到backtracking也行，‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌但是worst case也是O(n)。interviewer说考虑average的情况，从后面扫更优化，就让我按从后面扫写了。写得有点崩。。。

https://www.1point3acres.com/bbs/thread-784029-1-1.html



第一轮 1.BQ
           2. 递进税率计算器
            第二轮 SD design user favorite songs list in the past 7 days
            第三轮  1. the sum of all the root-to-path in a binary tree
                        2. 三四亿，多了一个removePrev()
                        第四轮  1. 输出所有子集
                                    2. 24点，但是每位可以直接合并 example: "1111" -> 0 : ["11-11"，‘-11+11’，“-1-1+1+1”.....]

https://www.1point3acres.com/bbs/thread-783947-1-1.html



电面：Alian dictionary，topological sort 解出来了，LC准备过
onsite coding：都是LC上 FB tag的高频题，具体是什么想不起来了，因为都刷过，基本都是直接做出来了。我遇到的题基本都和array有关，lee215 大神有个用 monotonic stack/queue 的方法（他解题回复里有个list，忘记是哪题了...) ，我遇到的至少2个题都是那样解的。

SD 是一个facebook music的题，类似于 top K。去youtube看这个channel UC9vLsnF6QPYuH51njmIooCQ ，把里面每个视频看3遍再自己复述，所有的知识点都弄明白，过FB和G的system design应该都没问题。


一个manager面的behavior，都是网上可以搜到的题，大部分是问工作中的tricky情况如何处理的，STAR套路。中间加了一个小coding面，一个BST求 M~N 之间数的和。就是个BST遍‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌历，加个条件提前终止一些branch，熟练就好。

https://www.1point3acres.com/bbs/thread-782808-1-1.html



是面过了 coding有一个没过 所以最终没给过

1. bq，主要还是问project和team work
2. system design, design fb messenger
3. system design, design leetcode coding contest
4. coding, 蠡口散霸气， 役散领悟。 第一题是一个easy我傻了 用了linkedhashset，那个面试官偏要我把linkedhashset给implement出来 简直惊呆了，我当时就问我们是只面这一题嘛，意思就是让我implement linkedhashset太浪费时间了，她说没事，有时间...结果导致我第二题没时间写完，估计挂在‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌这里.呵呵哒
5. coding, 第一题是改变work directory，没有蠡口原题，第二题是加大数

https://www.1point3acres.com/bbs/thread-782565-1-1.html



第一轮： 总共三道题，前两道都是那种比easy还要esay的题，抱歉实在记不住了。第三道是LC霸实霸的小变种，要求inplace，ouput需要返回input的那两个数组。
第二轮：设计FB messenger
第三轮：两道题，第一道好像是，给一个乱序数组，返回这些数在sorted的情况下的index。第二道是深度克隆一个图。
‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌第四轮：BQ

https://www.1point3acres.com/bbs/thread-782597-1-1.html



本来是五轮，两轮coding两轮system design一轮bq，面试的时候有一轮system design的面试官没时间，就减免了一轮。coding：
minimum remove to balance parenthesis
exclusive time of function
shortest distance from all buildings
merge k sorted list, 不过这道题包装了一个iterator, 是给了k个iterator，实现一个新的iterator

bq忘了什么问题，之后十分钟问了一道简单的题目。给很多机票，输出机票的顺序。这道题时间不够没写完，还有两分钟的时候面试官说他了解了就让我停下了。

System design：Design instagram

这次面试的题目都不难，我也没觉得自己有哪轮表现很差。除了bq的题目没写完其他的都写完了（讲道理bq那轮的题目一两分钟我是可以写完的），system design面的时候面试官‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌看上去也都挺满意的，所有的问题讨论完他也都说good solution啥的，也说了我的design可以满足requirements，good job on estimation啥的。然而周二面完周四就给拒信。难道bq回答的太差了？或者是面试官们表面嘻嘻哈哈完了心里其实觉得不行呢。无法理解。

https://www.1point3acres.com/bbs/thread-781514-1-1.html

一: 天竺大叔.
妖溜唔灵 + 妖儿灵酒变种
第一个followup要求space到o(1).
第二个有点蛋疼...原题是K, 这里是连续的都消除.
几乎快写完了，大叔看看时间还剩8分钟了(算上最后提问5分钟)，让我别写了...问复杂度, test case啥的. 末了我还问他，+1行就完事了，需要写完么....他说不用了(这尼玛我也不知道咋评价啊....)

二: 人美心善小姐姐
第一个好像不是原题，但是不难...给一个2D matrix, 里面有一个扫地机器人，几个障碍物，别的都是需要打扫的empty cell, 问距离机器人最远的empty cell是多远.
followup: 如果有多个机器人呢.
第二题是妖儿撕酒.

三: 扭腰那边的天竺小哥.
SD轮，设计非死不可status search.
就挺常规的，感觉一直是我在说，他有foll‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌ow, 有个地方漏算了一个10倍他提醒了我下....提问的也不是特别难吧.

四：国人大哥.
BQ + 写了个妖溜儿变种，原题是找peak的，变种是找min, 几乎没啥区别.

感觉第一轮有点迷...目测要挂, lol.

https://www.1point3acres.com/bbs/thread-781013-1-1.html



FB E4面经：

电面：
max product except itself, 还一题忘记了……

这里有个小插曲，这两题我都秒了，但由于当时我在H1B身份转换阶段（OPT还一年出头到期），所以HR说不move forward了，但是我转成了H1B以后又给她们发了封邮件，就发了onsite。

Onsite：
Round1:
两题，第一题我忘记了，第二题是散吆柒

Round2:
两题，第一题是right view of a binary tree, 第二个是subarray sum to k, 两题都不难，所以做完还有些时间，面试官和我讨论了下怎么证明第二题的答案一定是对了，然后讨论了下什么时候可以用two pointer什么时候用BDFS。

Round3:
BQ记不清问了什么了，最后十分钟问了个移除最少左右括号让它valid的题。

Round4:
设计爬虫，这轮差点以为跪了，面试官的网络很不好直接关了摄像头，然后延迟很长……基本上我说什么他过十来秒才会回我，而且声音也不是很清楚，全程也没什么反馈，但好在从结果来看没有为难我。

还一轮BQ+题训练，是两个人的。

周二面的在下一周的周五给的回复，手上还有LinkedIn和Doordash的offer，在compete之中，我问HR能‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌不能去LA……HR表示有点难，默认坐标西雅图，还在考虑中，希望大家能给点米，感谢！

https://www.1point3acres.com/bbs/thread-780273-1-1.html



coding 1: 第一题给一个sorted array和x，找出两个元素满足两数字相减等于x。想了一会儿，最后用了two pointer，左边指针从左到右，右边指针可以用binary search来找。想的时间长了点所以binary search写了一半就开始第二题。第二题i18n (lc 司令吧)，这个很简单写完了。

coding 2: 给一系列的time ranges，返回有最多time ranges overlap的时间。这题又没见过想了一阵子，先是想用stack，觉得不靠谱，改用hashmap记录每一时间的count。然后在此基础上optimize，移除map种不再需要的数据。因为思考时间太久所以只做了一题。

system design：设计一个tracker可以根据amazon url提供历史价格数据

behavior：常见问题，coding是三意思，说了思路和complexity，只剩四五分钟了没写代码。

https://www.1point3acres.com/bbs/thread-779822-1-1.html



一面：类似刷题网 而要领。走代码时间都用了，只写了一道。 后来反馈这轮不咋行
二面：刷题网 要久久，幺儿似酒，🌂司令。
三面：刷题网 死药物，死灵。
四面：BH。 跪。 反馈不知道如何解决冲突.....
五面：SD：live 评论

最后跪了 ...... FB‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌家BH真的会挂人的
逝者已矣，生者当如斯。 祝后面的小伙伴好运🍀

https://www.1point3acres.com/bbs/thread-779576-1-1.html



1. bq， most challenging project，what good quality did you learn from your teammates, and how you internalize it, disagreements, etc,
   然后一道简单的coding, calculate taxes, input是一个income，和一个List[List], 代表每一段收入的税率。
2. 刷题网 伊舅舅 吾儿爸
   第二题面试者不太了解python，bisect.bisect_left返回的index解释了好几分钟。
3. 刷题网 儿欺爸 伊留吾灵
   第二题先给的用set的解法，follow-up面试者想要O(1) space complexity的解法。
4. 系统设计 骆驼骆驼骆驼点抗亩 主要功能 1.任意商品能查近期的价格history，2.用户可以subscribe，价格降低的时候邮件通知。
   骆驼骆驼骆驼点抗亩 真有这个网站，大家去看看就知道了。面试的时候我没尝试访问这个网站。

https://www.1point3acres.com/bbs/thread-779741-1-1.html

coding 1
刷题网 幺期陆尔 和 伍斯散

coding 2
translate an interger number to english words and vice versa

coding 3
flatten a binary tree to circular doubly linked list in place with same order as in order tree tranversal and vice versa

sys design 1
设计一个个人状态发布系统，要求支持 updateStatus 和 searchStatus


sys d‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌esign 2
设计一个多人联机VR乒乓游戏

BQ 1

https://www.1point3acres.com/bbs/thread-779066-1-1.html



1. BQ - 一个欧洲的Engineer Manager, nice的小姐姐
   聊之前的工作project，如何处理矛盾，最难的project等等。。聊太多导致没有时间做coding
2. Product Design - 国人小哥，之前在亚麻也做过
   设计hackerrank，支持多语言，leader board。跟System Design稍有不同就是不需要担心infra的部分，LB/Sharding/Cache这些全部都可以直接用现成的。
   **主要细讲了workflow和interface的设计。觉得自己答得还可以。**
3. Coding 1 - 一个类似南美洲的小哥
   第一题：删除链表的倒数第k个node
   第二题：设计一个class，存一堆有序list，然后有hasNext和getNext
   （这轮做得不太好，两题都不难，但小哥的网速太卡了，只有一格红色信号，问太多次他说什么，影响了心情。。45分钟内他还退出重登了三四次。。。然后我自己在第一题一些edge cases有点小卡）
4. Coding 2 - 东欧的小哥
   第一题：两个linked list，节点上存着不同的string，比较两个list的所有string合起来是不是equal，要求O(1)的空间复杂度
   第二题：一个schedule里面有working day和holiday，给定k天假期，问如何请假可以有连续最长的holiday。优化了下用sliding window做的，O(n)

https://www.1point3acres.com/bbs/thread-778792-1-1.html



1. coding：Shortest Path in a Grid with Obstacles Elimination， Longest Valid Parentheses, Remove invalid parentheses
   这面面的不是很好。。。最后一题没写完。面的时候感觉题还有点难，结果面完以后发现都是lc原题也是醉了
   现在公司工作太忙了，每天晚上都在加班，没时间刷题，建议面fb还是提前至少刷个20道题找找感觉。
2. system design：design一个feature用watch解锁手机，然后对watch做一系列动作。
3. behavior：就是问问你最大的职场decision是啥，然后还有一堆，你有没有跟manager意见不合的时候怎么办，你的项目推动不下去了怎么办，为什么要离开现在公司，blabla。。。
4. coding：国人小哥，感觉很放水。。。先问了sum of BST from range A to B, 然后follow up了一个Maximum Sum BST in Binary Tree， 后来又问了一个top k smallest euclidean distance
5. system design：des‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌ign一个tiktok的feature，input是一个video，然后output可以把你的脸变成个pig。。。

最后一面面完当天晚上recuirtor说review第二天送CR session，然后第二天下午5点约电话聊说面试过了，准备offer了
求大米求大米，想看看地里的包裹然后发现积分不足啥都看不了。。。

https://www.1point3acres.com/bbs/thread-779060-1-1.html



1. 白人小哥。散似霸+二百。第一题写完后有个bug，小哥说你口头跑一下，跑的时候发现了改过来了。后来小哥觉得我啰嗦就说好了，下一题。这轮感觉第一题因为没睡头脑不清楚所以写的有点问题。
2. 两只阿三。伊尔丝舅+伊尔丝。master三跟我面，shadow三连摄像头都懒得开。
3. design。设计一个系统，可以随时查找一定范围内所有的餐馆，返回餐馆的位置和评价等相关内容。一个阿三面的，面完之后感觉很不好。
4. BQ。亚洲小哥，‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌感觉还是挺nice的，他是occulus组的，感觉他们组人不多，平时挺忙。

https://www.1point3acres.com/bbs/thread-775677-1-1.html

第一轮 亚洲招聘经理 都是经典bq + 蠡口散丝第二轮 白人码农 简单atoi + 没见过新题 input 是非负数整型数组 和一个整数k 要求找到 largest sum of any 2 non-overlapped k-size interval
[1,2,0,3,4], 2 => 结果是10, 我用的 prefix sum + treemap nlogn
第三轮 系统设计 感觉最差的一轮 日本面无表情卷毛狗面试官，design typeahead, 感觉跟我说不到一起，我说的他都要clarify，他说的我也要clarify, communication 浪费了很多时间。时间结束我还有很多点没说。
第四轮 友好国人 也有新题 第一题 买卖股票延展，input 是 非负数整型数组 代表股票价格，在每天只能做买股票或者卖掉手中‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌全部股票，求最大收益。面试官一直引导我最后写出解，点个赞。
第二题 穿马甲的蠡口霸气无。

希望能帮到大家！

https://www.1point3acres.com/bbs/thread-776264-1-1.html

发个两月前的面经攒点米，大概5月面的，

1. coding: 骑而毅
2. coding: 类似三妖斯
3. design: 设计一个简单的fb news feed
4. design: 设计一个short link se‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌rvice. 任给一个url，返回一个短url。

https://www.1point3acres.com/bbs/thread-776624-1-1.html



coding 1： 实现cd parser， 输入为当前路径和参数， 输出为最终路径例子1，
当前路径： “/bar”
参数： “foo”
结果： “/bar/foo”

例子2，
当前路径： “/bar”
参数： “.”
结果： “/bar”

例子3，
当前路径： “/bar”
参数： “..”
结果： “/”

例子4，
当前路径： “/bar”
参数： “/foo”
结果： “/foo”

vertical travel binary tree

coding 2: 是否存在subarray sum 等于 k， 找出 array 的top k元素

design youtube video service

design live comment

行为 + easy coding

https://www.1point3acres.com/bbs/thread-777249-1-1.html

coding1:  刷题网 拾陆 ， 外星人词典
coding2:  刷题网 期漆， 刷题网 舞溜
design 1: typeahead/auto complete
design 2: newsfeed
bq:  mentors‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌hip, challenge project, 等等吹牛。没coding

https://www.1point3acres.com/bbs/thread-777993-1-1.html

VO 两轮code,一轮 system design

第一轮 code 两道题

第一题找出 local mininum, https://www.geeksforgeeks.org/find-local-minima-array/
第二题实现一个hashmap，要求可以 set, get, 以及 getLast， https://leetcode.com/discuss/int ... gh-Twitter-Question

第二轮 code 两道题

第一提类似 https://leetcode.com/problems/simplify-path/
第二题 3 sum 变形，就是给一个矩阵，要求从矩阵找出 a^2 + b^2 = c^2 的三个数

system design 要求设计 web crawler，但是要求是完全 distributed

第‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌二题 3 sum 变形，就是给一个矩阵，要求从矩阵找出 a^2 + b^2 = c^2 的三个数

这个是一维矩阵，你们都想太复杂了。。。。

https://www.1point3acres.com/bbs/thread-778030-1-1.html



1. coding。国人小姐姐超级nice，尔而起，以及一个单调stack的题（不好意思，原以为自己记得住，结果过了几天之后完全记不起来细节了），两题都秒了，有一题一开始有点bug，不过应该是改对了。
2. design。让人比较崩溃的一轮，设计newsfeed，楼主之前看了不少design的课程，但是面试的国人大哥全程不讲话让我自己一直说，我跟他说有几种design options，分析了一下利弊想问问他想选哪个，大哥让我自己想，当时就感觉他态度不太好了。后来又碰到一个design选择的问题，我又分析了一下，然后问大哥想选哪个，然后他态度就明显大转弯感觉有点passive aggressive，我跟他解释了一下我之所以提到几个option，是想根据use case分析一下利弊，但是解释似乎也没有用，面试完后recruiter也说这一轮的feedback是比较weak。。。感觉也是挺无语的，design轮碰上不交流的面试官真的超级蛋疼。
3. coding。超级nice的亚裔，要领而起和尔灵灵，基本上是秒了
4. bq，天竺姐，一开始讨论的很嗨，时间逐渐要结束了，我以为这下没问题了，已经开始想下一轮了，结果天竺姐突然话锋一转，要问一个小coding。虽然coding本身不难（真的是要抱歉，完全想不起来问了啥了），但是因为不是刷过的题，我当时心态突然就懵了，也可能是因为担心要上卫生间中午吃的特别少可能有点低血糖了还是怎么滴，满脑子都空白。感觉天竺姐也知道时间有点不够，问她input和output也明显不给我好好讲，最后有个其实挺好改正的bug也没给我时间改，挺无奈的，跟recruiter打电话的时候也说了一下这个情况，recruiter是hiring committee有可能会考虑一下。
5. coding, 白人面试官，就散吧和要死刘的变种。两题都不难，但是bq那轮懵的我根本没缓过来，导致第一题那么简单的题写来写去各种bug花了好多时间才完成… 最后第二题也没有时间写完了（但是写完了绝大部份核心函数）。现在想起来，bq那轮崩了之后应该要求一个bathro‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌om break好好平复一下心情的，可惜了。。

https://www.1point3acres.com/bbs/thread-778290-1-1.html





------

443 String Compression 

Followup是decode

string two pointer









LRU变种. 地里的面经有提到. 没有capacity, 实现getLast().



680 Valid Palindrome II



236 Lowest Common Ancestor of a Binary Tree **Binary Tree**



1004 Max Consecutive Ones III **sliding windows**



42 Trapping Rain Water **two pointer**



977 Squares of a Sorted Array



atoi 

339 Nested List Weight Sum  **dfs**

317 Shortest Distance from All Buildings **bfs**



1539 Kth Missing Positive Number **binary search** *











we know it starts from 1, so



```
arr[mid] - (mid + 1)
```



will be the count of number that missed.

- We are maintaining such invariant throughout the loop: l + k <= ans <= r + k. Obviously when the array is missing k or more elements in the beginning, ans == k; when there is no missing elements, ans is arr.length + k;
- When we update l = mid + 1, there are already mid + 1 non-missed elements on the left, and we still need k missed elements, so l + k <= ans still holds true;
- When we update r = mid, we know ans is less than arr[mid], and on the left of mid, there are mid non-missed elements, plus k or more missed elements, so ans is at most mid + k;
- Finally when l == r, we get l + k == ans == r + k "

```java
    public int findKthPositive(int[] arr, int k) {
        int l = 0, r = arr.length;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] - (mid + 1) >= k) r = mid;  //missed more or equal than k numbers, left side;
            else l = mid + 1;   // missed less than k numbers, must be in the right side;
        }
        return l + k;
    }
```



162 Find Peak Element

```
class Solution {
    public int findPeakElement(int[] nums) {
        int start = 0;
        int end = nums.length - 1;
        while(start  < end) {
            int mid = start + (end - start) / 2;
            // binary search 的edge case 就是 start + 1 = end 的时候
            // 这时候的mid是start，所以只要start 是mid +1 最后是能收敛到一个值的
            if(nums[mid] > nums[mid + 1]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
}
```



152 Maximum Product Subarray **dp**



138 Copy List with Random Pointer **linked list**



merge interval

616 Add Bold Tag in String



679 24 Game 



\249 Group Shifted Strings



1570 Dot Product of Two Sparse Vectors

merge two sorted list 来避免用hash



695 Max Area of Island **dfs**

919 Complete Binary Tree Inserter 

616 Add Bold Tag in String



560 Subarray Sum Equals K



basic calculator 1, 2, 3

https://www.youtube.com/watch?v=ICfk--XA02E



314 Binary Tree Vertical Order Traversal - **binary tree**



贡献一个fb onsite挂经