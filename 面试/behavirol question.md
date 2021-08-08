

Tell me about a time you worked on something that you do not have knowledge about?







**Tell me about a time you failed/ The biggest mistake you made**
→ 对应的是 earn trust, customer obsession
错误不能是致命伤,突出的是为了customer坚持了什么，没有customer的换成老师同学小组都可以。

因为意外（不是自己问题），产品没有弄得很完善，权衡之下觉得与其交付一个不好的产品，符合顾客需求更重要。于是先和客户沟通好，承认错误，客户允许delay，然后全队人一起努力赶，最后皆大欢喜。

可以想想你修的bug比较复杂或者比较难，没法catch code freeze或者某个deadline，然后你很及时的把问题反馈给你的manager，然后manager会去和release manager或者更上层的manager escalate 这个issue。最后你加班把bug修了，但是还是晚了一天，然后由于bug很重要，所以在code freeze之后特批还是进了release。





**Take a risk, or do not have much time, to make a decision/ Tell me about a time when you had to work on a project with unclear responsibilities.**
→ 对应的是 Bias for action, Ownership.
是行动优先，而且是要突出当仁不让，有责任自己能顶上的意识。比如customer找不到人刚好你在，你能主动做些事。







**Challenging client-facing situation/ Disagree with teammate or manager/ Tell me a time when you did something without asking approval from you manager**
→ 对应的是earn trust
这个很多人没对准，记住不是强行说服或者没什么理由的顺应别人, 为了customer或者最重要目的所以不同意别人。都是好说辞，和事佬的说法是偏题。
介绍背景，说出分歧。然后说自己怎么做，可以是讨论trade off, 可以是坚持高标准..等 结局一定说最后的选择是对的。 It proved to work well.





https://www.1point3acres.com/bbs/thread-346993-1-1.html

What is the currently remote work policy in linked? Do you know how it will change after the pandemic?

 What kind of team culture do you have? Is there a team happy hour ?

How many people are currently in your team? Whatis the distribution between senior and junior engineers?





My name is Hui Li. I graduated from Duke University in may 2019 with a master in computer engineering. Then I joined Mexico search team Walmart ecommoce until now. My main responisbility to develop search backend for Mexico market, focuing on improving relevancy and reanking of the search results. I have two years of experiences working with Java and Python to build microservices. I am familiar with the common web framework, like Spring boot, FastApi, Django and we use SolrCloud as our search solutions. I am also familiar with the CICD pipeline, (Dockers, Kubernates, jenkins) and have the experiences to launch the product on my own from problem understanding to shipping the solution. I also have the experience working closely with data scientist to build the data pipleline and ship the machine learning models into production

**Most challenging/proudest project/Tell me a time you solved a complex problem**
→ 对应的是highest standards, think big
要讲自己怎么走出comfort zone, 当然舒适区本身也是一道题。
扣题，怎么复杂，是deadline 紧，还是技术复杂，你怎么做的，学习了新技术，use my priavte time to work on it 等等 最后说结果或者说通过这个process 你学到了什么

chanllenging 的点是 deadline 紧， 没有data 相关的基础

Let me share you a quick story. At that time, I way driving the project to build rerank service. The goal of this service is to rerank the results after we retrieve it from Solr. We want our result is driven by user signal data, like user click, add to cart instead of pure text relevancy. 

At first, we planned  to ship a machine learning solution. Since we don't have a data scientist in our team, I corporate with a data scientist from data team. However, our company was facing a big reorg at that time and due to a lot of reasons. That data scientist cannot work for our team. My manager told me that we may need to halt this project for now untill we find another data scientist to continue with the model training.  However, that will definatly missed our deadline and  we may also have the chance to miss the hot sales which is the most imnportant event in mexico market. that is not acceptable. This is an important feature that will improve the costumer's search quality. 

 In order to launch this service before hot sales to meet the needs of customers, I did some research on my own and redeisgned the rerank service  to use a more traditional and heruistic way to handle this problem. I mixed up together all the factors like text relevancy score, user signal data, sales data, fresshness to generate a final score and use it to rank the documents. Then I also booked some time of our former data scientist to review this new solution using his expertise.  Later, I have a meeting with my manager  and convince him to launch this approach first then later we can migrate to a machine laerning solution. I succesfully launched this new service before the hot sales and it actually generate a pretty good result. One important thing I learned is that there are a lot of solutions to a problem and sometimes a simple solution can also make a big impact.



**Miss deadline  对应的是customer obsession, Deliver Results.**
要突出怎么让影响最小, 让customer不受影响。讲你自己的影响就偏题了。
解释为何会miss 你是怎么把损失降到最低的，最后结果是好的，影响不是很大
‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌

Let me share you a quick story. At that time, I way driving the project to build rerank service. The goal of this service is to rerank the results after we retrieve it from Solr. We want our result is driven by user signal data, like user click, add to cart instead of pure text relevancy. 

At first, we planned  to ship a machine learning solution. Since we don't have a data scientist in our team, I work closly with a data scientist from another team. However, our company was facing a big reorg at that time and due to a lot of reasons. That data scientist cannot work for our team and we don't have time to find another data scientist to continue with the model training.  If we sticked to our original plan, we would not only missed our deadline, we may also have the chance to miss the hot sales which is the most imnportant event in mexico market that is not acceptable.

 In order to launch this service before hot sales to meet the needs of customers, I redeisgned the rerank service and decide to use a more traditional and heruistic way to handle this problem and we can change it to use a machine learning solution in the later time. I mixed up of solr score, user signal data, sales data, fresshness that is all the factors we think is importnat together to generate a final score and use it to rank the documents. Then I also booked some time of our former data scientist to review this new solution using his expertise.  Later, I have a meeting with our team and convince them to my new design. I succesfully launched this new service before the hot sales and it actually generate a pretty good result. I also learned that a simple solution can also works for a complex problem. 



**Tell me a time when you received negative feedback**
先介绍背景,别人对你哪里不满意了, 简单说以下就行, 不要说很多别人如何对你不满, 也不要sugar coat 说自己其实没错。重点放在自己怎么解决这个问题，以及学到了什么。结果一定是好结果

When the padanmic starts, we started to work remotely. I don't have much experience work remotely. So I received the feedback that teammates think I am not focusing on the work. At first, I was suprised, because I commited every sprint and finished my jobs. Later, I realized it is the lack of communication. I would like to focus on coding, while replying to slack later. So my teammates think I am not responding sometimes. And another point is that I speak too less about what I did in the meeting. When working remotely, it is harder for us to keep track on what each teammates did. So I set up a call with each of my teammates to explain my habits and in the later meeting that I will prepare a small demo to illustrate what I did , so everyone could better track on it. What I learned is that you need to earn the trust from your teammates. Trust is based on communication. 





### CUSTOMER OBSESSION

leaders start with the customer and work backwards. They work vigorously to earn and keep customer trust. Although leaders pay attention to competitors, they obsess over customers.

1. Walk us through a time when you helped a customer through a difficult process and what that looked like.
   case 1
   Last year in Telamon, I took on and led a project of developing a web application for our Telecom engineering team, in order to help engineers build and manage detail specifications easily for their Telecom installation jobs. The detail specification building process was sort of complex, involving a lot of data entry and field data collection, and the requirement documentation provided to us was brief and totally in text description.
   Therefore, it is challenging for me to come up with an intuitive and engineer-friendly design.
   In order to understand the process thoroughly, I made several appointments with the engineering team, going through the specification building process with them step by step in detail. Then, I did some field observations, looking at how engineers use their iPads and computers in the field and in the office, when and how they input the data to complete a detail specification. Based on what I’ve learned and observed, I was able to come up with data schemas, draft a working prototype, and bring it to the engineers to collect feedback.
   It turned out that the prototype was very helpful, it saved us around 10% time when implementing the web application. After the production was released, the engineers tried and loved it immediately. They said they took less time building a specification now  with less error. The customer was obsessed with our professional process and result, and start to have more business with us.
   case 2  (customer obsession and ownership, highest standard)
   In Telamon, once I led the team to implement an AP processing service for one of our client - Hubert Corporation. We provide a customized AP processing system as well as a team of AP clerks to help Hubert process their invoices. Since invoices from different vendors might require different ways of processing and our client didn’t have a full instruction for that (they usually process invoices based on their knowledge and familiarity), we had to spend time emailing back and forth dicussing about instructions whenever there was a special invoice processed incorrectly.
   I looked at the invoices reported and thought we could do better in managing different invoices, vendors and corresponding instructions, and thus reducing the communication effort put by the client and us.
   I first created a shared matrix and recorded all the invoices and instructions provided, and asked our AP clerks to update it as long as there was any new invoice feedback from the client. Then based on the analysis of the matrix, I created a checklist listing certain type of error-prone invoices and asked our AP quality managers to check on these type of invoices every day. Further, I programed and applied notifications for several type of invoices with special instructions in the system, so that our AP clerks didn’t have to watch out for them all the time.
   After several weeks of running the service, I scheduled a meeting with the client and reviewed the matrix with them, they were impressed by it. And they even used the matrix as the instructions on their side. After a month or two, we barely got any email about incorrectly processed invoices from the client. We obsessed our client with our great quality and attitude to insist on the highest standards.

### OWNERSHIP

leaders are owners. They think long term and don’t sacrifice long-term value for short-term results. They act on behalf of the entire company, beyond just their own team. They never say “That’s not my job”.

Give me a example of when you took a risk and it failed.

这个也可以套rerank service 的例子

I didn't give up at that time. 



case 1
I’d like to talk about one of my project at BitTiger. BitTiger had a bootcamp course for project managers and I was hired as the lead developer to help implement the idea driven by the project managers teamed with me.
Our task was to improve BitTiger's current communication channels between teachers and students, and integrate them more with its official web portal.
Since I was the person who was going to lead another developer to build the product, it was important for me to understand the user needs and the decisions made by the project manager thoroughly. The best way to do so was to actively take part in the decision making process from the very beginning. Therefore, for most of the activities hosted by the project managers, I asked to join them, like, taking notes while the project managers were interviewing with teachers and students, coming up with suggestions while they were discussing about user personas and stories, offering help while they were building wireframes, and joining discussion when they were creating and prioritizing tasks.
I was able to implement the product quickly because I totally understood what the project managers wanted. We didn't need to spend time communicating the requirements again. With the time saved, I was able to add more customized features making the product easier to use. On the demo day, we had a great presentation and received very good reviews.
case 2
the communication feature is not easy to use, only remind the client you received a new message and log in. The client didn't log in to the system very often. Sometimes the client just email back to me saying what happened.
I took the ownership to support this project, I designed a new process by delivering the content to the kitchen designer and bring it to the client to discuss. the client agreed. After deliver, our customer support team has reduced around 70% support request for this project.

### INVENT AND SIMPLIFY: 

Leaders expect and require innovation and invention from their teams and always find ways to simplify. They are externally aware, look for new ideas from everywhere, and are not limited by "not invented here". As we do new things, we accept that we may be misunderstood for long periods of time.

Tell me a time when you created an innovative product.
case 1
question board, BitTiger need to manager a lot of things, like notification, link to the live course, questions, communication. We are overwhelmed at the first about inventing the process, thinking about a lot of ideas like group by different tabs, create with different categories. But I decided to keep it simple and stupid, we create the post for all purpose, but group it by weeks. All important notification on the top.
care more about look and feel rather than a lot of features
case 2
The project we did for hartson kennedy was to help process their drawing and purchase order. The customers  usually order countertops in their stores and kitchen designers then doing the drawings and generate PO paperwork, and send to us. However, the kitchen designer only uses fax machine, but we didn't have fax machine.
Instead of just purchasing a fax machine and assigning a person to handle the scanning everyday, I googled and did a research online first. I found a service that can receive the fax via email. I created a distribution list and registered it as the receiving mailbox.
With the simplified process, we don’t have spend money and time dealing with fax machine and scanning.  I invented and simplified the fax receiving process and saved money for our company.



### ARE RIGHT, A LOT

Tell me about a time when you observed two business opportunities to improve ROI, and how did you determine that they were connected.
Leaders are right a lot, they have strong judgment and  good instincts. They seek diverse perspective and work to disconfirm their beliefs.
tell me about a time when you are wrong
tell me about a time when you had to work with incomplete data or information
make a decision, but also consider the opinions of the other people
case 1
we have a indexing team in china that helps enter the data on the invoice, I designed the indexing panel for them. Before making the decision, I decided to talk to the staff who are doing the data entry. Ask them to try and record the time and provide feedback. It turned out that they have some very good point of view, like amount match, required text-box color. And I changed my design and improve 10% processing time.
case 2
once I argue with the manager about issue the corporate email, I want to register emails from MS and Gmail for business use because Telamon email sometimes blocks, and we have to contact Telamon IT which are not very responsible. The manager disagree at first, he said the corporate email is more professional. I collected the issue happened, and the impact on the client, feedback from them, average time IT reach and solve the problem, it turned out that we cannot bare it. then the manager agrees to switch as long as we can get a good domain name. We then applied a domain based on coporate and the name of our department. Everyone is happy.



### LEARN AND BE CURIOUS:

Leaders are never done learning and always seek to improve themselves. They are curious about new possibilities and act on explore them.

 How do you find the time to stay inspired, acquire new knowledge, innovate in your work?

case 1
I recently learned how Redux architecture and how it work
actions, global status, dispatch actions
case 2
how large company deploy their front-end
how to cache


HIRE AND DEVELOP THE BEST: Tell me about a time when you had to deal with a poor performer on your team.
Leaders raise the performance bar with every hire and promotion. They recognize exceptional talent, and willingly move them throughout the organization. Leaders develop leaders and take seriously their in coaching others. We work on behalf of out people to invent mechanisms for development like Career Choice.
case 1
for the data entry team in China, they didn’t care much about the system before. When I led the project, I will  invite them to join the meeting, tell them I we develop the system, teach them how to test and ask them to feel free to give me feedback if they any idea. they are the direct users of the system.
finally these employees are very helpful for testing new features, and improve the efficiency of the indexing.
case 2
When I transferring the projects from one person to another, I will co-work with them for a while, making sure the things they completely get the idea.


INSIST ON THE HIGHEST STANDARDS: Tell me about a time when you could have stopped working but persisted.
Leaders have relentlessly high standards - many people may think these standards are unreasonably high. Leaders are continually raising the bar and driving their teams to deliver high quality products, services and processes. Leaders ensure that defects do not get sent down the line and that problems are fixed so they stay fixed.
case 1
hubert three way matching features, we have implemented the feature successfully. But I found the processor took long time to compare the amount of receipt, Purchase order, and invoice, calculate the tolerant percentage, identify any mismatches. I took the initiative to add exception handling features, instead of finding mismatches by eyes, I add a box to input and compare the amounts by the program.
it turned out the efficiency has improved a lot.
case 2
client give us the ftp, and overwrite data everyday, sometimes if there is holiday, we may miss one or two load. I write a program to fetch the file and archive the data by date, so that we’ll always have the backup if there is any issue happened.
http://www.codejava.net/java-se/networking/ftp/java-ftp-file-download-tutorial-and-example


THINK BIG: Tell me about a time when you proposed a new business.
Thinking small is a self-fulfilling prophecy. Leaders create and communicate a bold direction that inspires results. They think differently and look around corners for ways to serve customers.
case 1
augmented reality to find store
case 2
ambient building


BIAS FOR ACTION: Describe how you would handle a busy situation where three people are waiting for help from you.
Speed matters in business. Many decisions and actions are reversible and do not need extensive study. We value calculated risk taking.
case 1
the other engineer and I discussed for a couple hours, figured out what we disagreed on, and I suggested that neither answer was necessarily better. She agreed. I said that unless she had any new info, I’d rather we just pick mine, and we could always come back to the decision later if we learned something new.
example??
case 2



FRUGALITY: Tell me about a time where you thought of a clever new way to save money for the company.
dd
case 1
for most of internal tools, we’ll google first instead of developing by ourself.
case 2
USL, this project is a little hurry, we don’t have enough resources for that. Average of processing one load takes around 4.5min, and we watch all the steps, automatically whatever we can, and reduce the process time to 2 min finally.


EARN TRUST: Tell me a time when you earned trust of a group.
Leaders listen attentively, speak candidly, and treat others respectfully. They are vocally self-critical, even when doing so is awkward or embarrassing. Leaders do not believe their or their team’s body order smells of perfume. They benchmark themselves and their teams against the best.
vocally self critical
The biggest mistake I’ve made happened when I took on and led a project for the first time by myself. I got a requirement from the client about updating parts of a certain workflow. I listed the requirements, developed with the team, and released the update to the demo system on time, however, the client tried and didn’t like it.
I diagnosed the system immediately, It turned out that we paid a lot of attention on the changes the client requested us to do, but didn’t do much evaluation on other features that are impacted by the change. A solid evaluation and design was necessary in this case because all the features in the workflow were closely connected to each other, and even a small change might cause butterfly effect.
I apologized to the client immediately and asked if we could have an extended deliver date. Luckily the client agreed and also showed understanding. Then I called a meeting with the dev team, walked through the whole workflow step by step together, evaluated all the possible operations that user might take on each step and then tailored the change we were gonna make accordingly. We then released a tentative version to the demo system before the deadline , walked through it with the client, and collected any feedback provided.
Finally, we delivered the update to the production successfully, our client was very happy and used it every day without any trouble yet.

### DIVE DEEP: 

Tell me about a time when you had to dive deep into the data and the results you achieved.
trust but verify
you believe the person but check the facts anyway
Leaders operate at all levels, stay connected to the details, audit frequently, and are skeptical when metrics and anecdote differ. No task beneath them.
case





HAVE BACKBONE, DISAGREE AND COMMIT : Tell me about the most difficult interaction you had at work.
Leaders are obligated to respectfully challenge decisions when they disagree, even when doing so is uncomfortable or exhausting. Leaders have conviction and are tenacious. They do not compromise for the sake of social cohesion. Once a decision is determined, they commit wholly.
disagree with boss?
If I have different idea with my manager or boss, I will try to collect data or make a prototype trying to convince him. If I have tried my best and he still disagree, then I would respect his decision and start committing for that.
when we released the service for US Logistics. The client complaint that some invoices were missed. I checked around and found that Telamon Network blocked s‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌ome of the emails sent by the client. I talked the problem to the network administrator and they couldn’t change the email restrictions due to the policy.
Therefore, I brought this problem up to my manager and suggested to register another business mailbox provided by gmail or microsoft. The manager disagreed at first because he thought it was unprofessional if we didn’t use our own corporate email domain. I thought solving this problem was more important because our client would lose the trust on the quality of our data. In order to convince him, I showed him the data of email missing rate and the impacts on our client, and also I registered a good domain name composed by our company and department name, so we could still be professional on that part.
Finally, the manager was convinced and agreed on my suggestion. We barely have any missed emails after we switched our mailbox. And because of the good result, we started to use the domain for other projects gradually.

DELIVER RESULTS: Tell me about a time where you overcame an obstacle and delivered results.
leaders focus on the key inputs for their business and deliver them with the right quality and in a timely fashion. Despite setbacks, they rise to the occasion and never settle.
what you’d do after you realized you couldn’t hit the date?
First, I’d check every possible way that could possibly make me hit the date, like using after-work time, weekends, or holidays, asking for help or suggestions, finding alternatives or simpler solutions, etc. Since I am the owner of the tasks, it’s my responsibility to deliver results on time. It’s my fault that I underestimated the workload when I took the tasks.
There was one time that we couldn’t finish the troubleshooting of a bug on time, the system should have sent out auto emails at 7:00 am but sometimes it failed. Before solving the problem, I will check each morning and manually trigger emails to the client.
If I still couldn’t hit the date, I would look at features, pick out a few with highest priority that I could finish, and then discuss about the problem with the project manager. Of course, I would apologize first and then try to discuss about the best solution to minimize the impacts. Once the project manager agrees, I would notify all the people that could be impacted by the delay.





Tell me about a time when you gave a simple solution to a complex problem/ Find a new way to do something
这个问题一定要让面试官信服你说的例子。先说一般的方法很耗时，自己找到一个方法很快就完成并且Deliver 了，而且很稳定，没出过问题，结果要是好的。

soft sorting. 

Let me share you a quick story. One day, I was testing the search functionality after we migrating the search engine from Endeaca to Solr cloud. I found our sort by price feature is pretty broken. One example, when you search for tv, a lot of tv related product like tv controller, tv mounter will be included. At that time, we haven't implemented the features like category classification, brand classification that will help us filter out these unwanted products in our recall set.  And since their prices is much lower than tv, so when you sort the price from low to high, they will jump to the top. That is not customer want. Customer want to see a cheaper tv instead of tv controller or something. I think of a simple solution is to only sort the selected parts of the recall set. We can pick the most relevant products and show the sorted results to the costomer. After I elaborated the problem to my manger and demod my solutons, he approved it and it didn't took me a long time to deliver it. The ab test is suprisily good, It improve the revenue by 11%.  











BQ应该是所有面试里最好准备的部分了，有过一些工作经验的话都比较简单，尤其是对于香蕉厂员工来说，每天工作的一部分就是互相扔贝索斯语录。大家按照leadership principle的14（现在是16）条来准备就好。大家可以准备5到8个例子，利用STAR method （Situation, Task, Action,Result)来把例子写下来。尽量写的详细一些。最好是那种一个例子可以cover很多个问题的，写下来每个例子可以cover的LP。核心要义就是体现你是一个good team player， good problem solver 。然后在练习讲的时候可以针对具体问题对例子进行删减。远程面试的好处是可以直接把例子打开现场快速查找。不过不要照着读，一定要现场组织语言。准备足够以后基本上听完面试官的问题就大概知道面试官想听到的点是什么。一个小技巧是听完题以后，不要着急回答。和面试官说give me 30 seconds to think about a good example，利用这个时间来组织一下语言，想一下用哪个例子，侧重点是什么。
在面试中如果遇到非常规题，不要慌张，还是通过那30秒来快速回想一个例子。如果实在想不到合适的例子，千万不要现场编造。可以直接和面试官说想不到一个例子。这是没关系的，我谷歌和fb的面试都遇到了没有例子的问题，面试官就直接move到下一题了。. 1point3acres
最后还有一类面试题不是“tell me about a time when xxx”的，而是比较虚的问题。比如我遇到过"what is your ideal team culture" "if you were to give some advice to a junior new member, what would you say"。这一类不太好准备，就只能根据经验现场发挥了。这里体现了香蕉厂的一个好处，把平时乱丢的LP jargon讲一讲，面试官就很满意哈哈。





介绍一个你最喜欢的项目？介绍下简历？介绍下自己？

翻译：有没有看职位要求？说说职位要求要找什么人？你是这样的人么？介绍一个你最符合这个职位要求的项目，最后强调你是good fit

你最大的缺点/失败？

翻译：你一个无伤大雅的小缺点/失败是什么？你从以前的哪个项目知道自己有这个缺点/失败？知道以后学到了什么教训？在后面哪个项目中吸取了这个教训，做了什么，取得了什么结果？

你最大的优点？

翻译：我知道你很牛，你哪个特质最符合这个职位的要求，并且在最后强调你的某某优点让你是一个good fit for this position

为什么选我们这个公司？

翻译：公司的mission是什么？我的career goal和你们公司的mission完美契合；职位的要求是什么？我的背景和能力和这个职位的要求完美契合。最后强调你是good fit

怎么知道这个职位的？

翻译：如实回答就行，我一般都说career fair和公司的工程师聊了聊，关键是最后要再重复一遍，据我了解，这个职位是干啥或者需要啥，我以前也在做这个或者有相关的技能，所以good fit

队友/同事不干活/很难相处咋办？

翻译：你有没有经常和队友/同事主动沟通？你愿不愿意为了团队，帮队友/同事分担一些工作？能不能以非常职业的方式解决这个问题？
. 1point3acres
队友/同事不同意你的观点咋办？

翻译：你有没有自己花一些时间做一个数字化（quantitative）的比较？有没有向队友/同事提交一个详细的报告或者比较（report/strong case）来说服ta？会不会有效的沟通？

你怎么定义成功？
. 1point3acres
翻译：一般我都说达到自己制定的目标就算成功，这样容易说；那就可以理解为你有没有为自己制定目标？你的目标是啥？你现在完成的怎么样？未来在这个公司想怎么发展自己？（develop tech stack，gain more domain knowledge，see myself in postion of senior engiener in xx years）. 1point3acres

被安排了一个很难的任务咋办？

翻译：你会不会和你的老板沟通？你会不会和你的同事沟通？你会不会提出合理的要求？能不能以非常职业的方式解决这个问题？. 1point3acres

任务的due被提前了咋办？有没有身背数个deadline的经历？
以下内容需要积分高于 20 您已经可以浏览

翻译：你是怎么管理你的时间的？比如日历上设置好项目，还有提醒；你会不会根据工作的优先级安排你的时间？你会不会为了项目组的整体利益考虑（best interest of my team），舍弃一些个人利益？比如为了毕设，自己的考试就不投入太多时间；会不会和别人沟通寻找解决方案？如果你是组长，你知道due提前了会不会采取措施？比如立刻开会，重新安排这个项目后面的任务和时间节点。

为什么你是xx专业，却想做sde/ds/mle？

翻译：你之前哪段项目/实习经历做了有关sde/ds/mle的啥？你产生了啥影响，取得了啥结果？你是不是很享受你的产出？（是，所以我想转）



BQ
Dive deep主题。最有意思的一次dive deep debug的经历。

BQ问了两个问题
1. 你为团队解决重大技术障碍的事例
2. 你需要经过很多层来解决一个问题的事例

BQ: beyond job responsibilities + tight deadline





Tell me about a time you failed/ The biggest mistake you made
→ 对应的是 earn trust, customer obsession
错误不能是致命伤,突出的是为了customer坚持了什么，没有customer的换成老师同学小组都可以。

Take a risk, or do not have much time, to make a decision/ Tell me about a time when you had to work on a project with unclear responsibilities.
→ 对应的是 Bias for action, Ownership.
是行动优先，而且是要突出当仁不让，有责任自己能顶上的意识。比如customer找不到人刚好你在，你能主动做些事。

Challenging client-facing situation/ Disagree with teammate or manager/ Tell me a time when you did something without asking approval from you manager
→ 对应的是earn trust
这个很多人没对准，记住不是强行说服或者没什么理由的顺应别人, 为了customer或者最重要目的所以不同意别人。都是好说辞，和事佬的说法是偏题。
介绍背景，说出分歧。然后说自己怎么做，可以是讨论trade off, 可以是坚持高标准..等 结局一定说最后的选择是对的。 It proved to work well.

Most challenging/proudest project/Tell me a time you solved a complex problem
→ 对应的是highest standards, think big
要讲自己怎么走出comfort zone, 当然舒适区本身也是一道题。
扣题，怎么复杂，是deadline 紧，还是技术复杂，你怎么做的，学习了新技术，use my priavte time to work on it 等等 最后说结果或者说通过这个process 你学到了什么

Miss deadline  对应的是customer obsession, Deliver Results.
要突出怎么让影响最小, 让customer不受影响。讲你自己的影响就偏题了。
解释为何会miss 你是怎么把损失降到最低的，最后结果是好的，影响不是很大
‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌

Tell me a time when you received negative feedback
先介绍背景,别人对你哪里不满意了, 简单说以下就行, 不要说很多别人如何对你不满, 也不要sugar coat 说自己其实没错。重点放在自己怎么解决这个问题，以及学到了什么。结果一定是好结果

Tell me about a time when you gave a simple solution to a complex problem/ Find a new way to do something
这个问题一定要让面试官信服你说的例子。先说一般的方法很耗时，自己找到一个方法很快就完成并且Deliver 了，而且很稳定，没出过问题，结果要是好的。





**1. Basics**

Tell me about yourself？

不是要你讲真正的关于自己的兴趣爱好，而是一切和应聘的岗位有联系的。例如相关工作经验，以及相关的 personal traits。按照面试官给定的时长来说。

万能公式：总结过去的工作经验 + 1 个该工作相关 personal traits

My name is Hui Li. I graduated from Duke University with a master in computer engineering in  may 2019. Then I joined Walmart ecommoce, in Mexico search team until now. My main responisbility to develop search backend for Mexico market, focuing on improving relevancy and reanking of the search results. I have two years of experiences working with Java and Python to build microservices. I am familiar with the common web framework, like Spring boot, FastApi, Django. I am also familiar with the CICD pipeline, (Dockers, Kubernates, jenkins) and have the experiences to launch the product on my own from problem understanding to shipping the solution. I also have the experience working closely with data scientist to build the data pipleline and ship the machine learning models



 What I did in the last two years, Start with tech moderlization. When I first joining the team, our search is powered by Oracle Endeca and  Oracle ATG.  We aim to deprecate it and move to a cloud native and scalable search Engine solr to improve performance and relevance as our catalog and query diversity continue to expand. I developed and launched the new search query service using Spring boot and Solr. provided search, browse api. Not only increasing the search add to cart by around 22% percent and meet the our sku scaling needs from 1M to 30M. After that, I was working on adding more data-driven microserves and features to improve our search results. I designed and implemented the query understanding service to increase the accuracy of our recall set from Solr. Like understand the category for a certain query based on the former user signal data. It also gave us pretty good result ,around 20 percent increasing in revenue. I also designed the reranking service to showing the trending and new products to the top. Recently, our team got some data scientists member. So I working closely with data scientist to build the data pipleline and ship the machine learning models



Why this company / this position / this team?

如果该公司是大公司，则着重强调大公司的优势，例如制度完整，有完善的学习路径；如果该公司是小公司，则说明这个公司非常有潜力，可以看到是未来炙手可热的 unicorn。一般从大公司跳到小公司更容易考这个点。

针对小公司的举例：

> XXX is a very hot unicorn company and it matches my next career goal - a larger stage so I can have more impact and contribute more in term of mentoring, leading and etc.



Why leave your last position / company？

如果从大公司跳到小公司，主要有几个方面

1 lack of impact（自己在公司缺乏影响力）

2 bording（干的活非常无趣）

3 boiling frag（温水煮蛙）

如果是从小公司跳到大公司，那就更简单了，主要说明小公司不稳定，对自己的职业发展不是特别好。



Walk me through your typical day at work.

一般的大概是这样：Scrum meetings / Interviews / Codings / Design meetings / Retros



**2. Success**

a) Tell me a time when you succeed / a project you proud of

b) Tell me a goal you achieved

讲一个自己在工作中成功的例子即可。记住使用 STAR method 来描述。



**3. Failure / Conflict**

a) Tell me a time when you failed on something

b) Tell me a time when you disagreed with your manager

讲一个自己在工作中失败的例子，不是真的在业务上失败，而是其他无关痛痒的地方失败。记住使用 STAR method 来描述。

最好不是真的在业务上或者那些有负面影响的 conflict，例如各种歧视，自己的偏见等等。一般建议选择那些无关痛痒的方面来解答。



**4. Pressure / Challenge**

a) Tell me a time when you handle difficult customer / task

b) Tell me a time when you worked under close supervision or extremely loose supervision

可以说明是工作上的一些压力，例如时间比较紧，但最后成功的例子。



**5. Leadership / Deep Dive**

a) Tell me a time when you helped a peer / other

b) Tell me a time when you took on something outside your area of responsibility

可以把 pressure / challenge 准备的故事反面性拿在这里用。





HR问我，你选offer最看重什么， 我很傻的回答： “钱”。。 于是， 就没给我钱。 哈哈。。。
应该答：我比较看重个人成长， 和我能make的impact. 而且我个人非常喜欢游戏， 我觉得你们公司的产品非常有潜力，我很有兴趣.  钱的话，当然多给就好了，但不是重要因素



一个加了sauce的BQ故事的例子：
发现了系统performance issue, 自己做research 研究， 然后和TL讲。 TL不同意， 于是我做了prototype benchmark, 证明了我的想法是正确的, 于是领导很满意的让我做这个project, 我成功做出，把latency 从2s 提升到了20ms, 内存消耗减少了10%。对面感兴趣， 我会说中间用了这个open source， 那个open source, 每个设计间的取舍和trade off。

真实情况是， 这个side project做了一半, 我就准备面试没时间做了。。 哈哈～ 但是我确实有整体设计的思考过程，如果给我时间，我是可以做完的。

最后说一下多线程和behavior questions:
如果工作中接触多线程不多的小伙伴可以看看多线程，leetcode concurrency那几题做一下感觉差不多了，但要理解一下各种lock为什么这么用。楼主工作中用的不少，所以这方面没怎么花时间，一个周末做了那个leetcode的concurrency section就没怎么看了，不过面试中被问的真的非常多！！我觉得要面senior岗的小伙伴，可能要好好准备一下，下面提到的很多公司都面到了多线程。。比如楼主面试主要用java，可以想想比如condition为什么要bakced by a lock，reentrantlock.lock为什么写在try外面呀之类的。。细节多想想 或者看一下best practice 理解为什么这么写. critical section怎么样尽可能小一点之类的。即使别人不一定会问到，但你写的时候提一下这些我觉得会比较好.
BQ我觉得多准备几个例子就好，比如conflict怎么办，项目delay怎么办这种，说一个失败/自豪的项目，在职跳槽大家肯定都有素材，适当加工好好说就行了。。或者按照亚麻的leadership principles准备一下也不错。。这个一周肯定够了.能有一些例子体现scope会很好。。准备一个好的例子加分会很多，楼主工作中有一个很独特的帮助别人的例子，在面试中说了多次，每一次感觉都加分不少，我觉得好好挖掘一下自己的例子，不用准备太多，但准备几个很有说服力的就行。





个人感觉你可以这么说：
1.介绍这个项目的big picture, 比如项目是干什么的，动机是什么，实现的功能是什么。
2. 然后介绍具体应用到的技术，所用的语言，开发环境，系统架构，系统设计。
3. 在利用一些具体的use case来详细描述这个项目，好比做一个口头的demo。
4. 最后说一下这个项目的future work。（可选）

估计是所谓的behavior那轮，或者有的公司会直接说有个deep dive这样的一轮。一般是让你自己准备一两个项目详细讲，会问的很细，从用了什么技术到为什么做这样的选择，有什么trade off，如果现在让你重新做你会有什么改变的地方之类的。
估计也有可能会有面试官挑你简历上的项目让你说，所以rule of thumb就是，只要你写在简历上的，你就要很熟悉，能够talk about it。