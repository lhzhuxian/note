





people, 























My name is Hui Li. I graduated from Duke University in  may 2019 with a master in computer engineering. After I joined Walmart until now.  Our team is mexico search team. The main responisbility of our team  is to provide backend support for search in mexico market. For me , I am focusing more on  improve relevancy and reanking of the search results, Including pre retrieval query processing like query understanding, retrieval strategies(teawking the query to our search engine), rerank and personalization of search results. 



We are using Java and Python to build microservices with framework like spring boot ,fastApi and we use SolrCloud as our search solutions. I am also familiar with the CICD pipeline, (Dockers, Kubernates, jenkins) and have the experiences to launch the product on my own from problem understanding to shipping the solution. I am currently working closely with  newly joined data scientist to build the data pipleline and ship the machine learning solutions.





### Tell me about a time you **disagreed** with Someone / **conflict** with your manager / worked with **a difficult person** /communication with a coworker ?



S/T:

About one month ago, I am assigned with a project to implement the deployment pipeline for our machine learning model. Basicly it is to solve the problem when training pipeline releasing a new model, how will we let the inference service know about this model and update it. Our tech lead give me the high level design that our training pipeline can post a message to kafka about the new file that has been deployed. I disagree with his design. It actually an over engineering to use kafka right here. 

 A:

I first wrote a design documents for several solutions with its pros and cons. Then I scheduled an pair with our tech lead. We discuss through several options and my tech lead agreed that there is no need to use kafka here and it will add the complexity. And then he helps me to improve my solutions with more details and make it a better solutions. I demoed the design change in the next day's tech discussion and my manager appricated our work.

R:

I later successfully deployed our model deployment pipeline and it works perfectly. It will easy to extend to a new model training pipeling and extend to more features like how we picking up the models

L:

What I learned from this experiences that we need to be open. Willing to give advice and willing to listen to others. Everyone stands in a different aspect and an thought from a different aspect can make help make a better solution. 









### TELL ME ABOUT A TIME YOU RECEIVED CONSTRUCTIVE FEEDBACK/ 有没有同事或老板给你Critical comments, 之后如何处理 / To‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌ugh feedback.

not responding in slack, 

S/T:

It is right after we start work from home. It went well at first, but later I feel distracting from a lot of slacks and emails. So I decide to block sometime in a day that I will focus on my work and ignore the notifications. However later in one on one with my manager, my manager told me that he learned from my other colleges that sometimes I didn't response in time. I am suprised and told my manger the situations. I realized that there is a misunderstanding between my colleagues and me which is caused by work from home. 

A:

In the next day's meeting, I apologize and explain why I am not responding sometimes to my teammates. Our teamates actually agreed with my idea, because they sometimes also feel the same. So we brainstorm together to come out some rules that can help us better communicate and improve the effiencicy. Like having an hour tech discussion in tuesday and thursday, so we can learn from what each ohters doing and bring out the blocking we faced.  When sending slack message, instead of sending hello and wait for response, we can directly send the questions. So we can all work asynchronously. 

R:
We came out with a lot help rules and it helps a lot to release the inconvenient when working from home. And it brings our team closer.

   



### chanllenging and proud project.  // 有External Obstacle怎么处理

S/T:

 In Q4 last year, I way driving the project to build rerank service. The goal of this service is to rerank the results after we retrieve it from Solr. We want our result is driven by user signal data, like user click, add to cart instead of pure text relevancy. 

At first, we planned  to ship a machine learning solution. Since we don't have a data scientist in our team, I corporate with a data scientist from data team. However, our company was facing a big reorg at that time and due to a lot of reasons. That data scientist cannot work for our team. My manager told me that we may need to halt this project for now untill we find another data scientist to continue with the model training.  However, that will definatly missed our deadline and  we may also have the chance to miss the hot sales which is the most imnportant event in mexico market. that is not acceptable. This is an important feature that will improve the costumer's search quality. 

A

 In order to launch this service before hot sales to meet the needs of customers, I did some research on my own and redeisgned the rerank service  to use a more traditional and heruistic way to handle this problem. I mixed up together all the factors like text relevancy score, user signal data, sales data, fresshness to generate a final score and use it to rank the documents. Then I also booked some time of our former data scientist to review this new solution using his expertise.  Later, I have a meeting with my manager  and convince him to launch this approach first then later we can migrate to a machine laerning solution. 

R

I succesfully launched this new service before the hot sales and it actually generate a pretty good result. One important thing I learned is that there are a lot of solutions to a problem and sometimes a simple solution can also make a big impact.

准备两个



### Why linked

I want to work at Facebook for three reasons.

First, linkedin is the leading tech company which has billions of users. The Challenage here is incredible,  because the work it does impacts more than 1 billion people. This is a truly unique opportunity.

Second, I have several friends in working in linked right now, they recommended I apply. I really enjoyed my discussion with her as she seemed to be truly passionate about messaging and working

Finally, I'm attracted to linked culture of  Be open, take risks, act like an onwner. These are some of the values I try to implement in my own work and I'm excited to join a team that thinks along similar lines.

Robinhood’s mission is to democratize finance for all







### 工作中遇到blocking / chanllenging

search ab test 结果不好，我对schema进行了研究，找到了原因







### failure 

代码里bug，解决以后学到了test的重要性，学会tdd



s： 

- In the last year, our company faced a big reorg. We onboard several new members from UK department.  
- My manager want me to work with one of our new member to implement the autocomplete services for our new search architecture.
- It is my first time that I need to lead a project and onboarded a new member









### 自己做了什么超过自己职责范围的事情 / experience when not your area but you took ownership / tell me about a time you worked on something outside your OKR

S/T: 

- In q3 of last year, one day I was checking some production issues in our website. I found that our sort by price feature is quite broken. 
- For an example, when we search tv and sort by price,  we are expecting the results showing up is low price tv, but the reality is the first several pages are all TV remotes, stands and other accessories. 
- At that time I was working on some other projects, but I feel like this a feature that can largely improve users' search experience, especially our customer are price sensitive.  

A:

- So I design a soft sorting solution and scheduled a  meeting with my manager， product manger and tech lead to demo what I found and my solution.
- My manger appricaite what I find and provide and we decided we want to launch it in this quarter. Because, we have beau fin at the beginning of Q4 which is black friday in Mexico. We want this new feature before it, so it will have a larger impact.

R:

- I accomplished all my quarter OKR without any delay along with deploying this new soft  sorting feature. The AB test result is surprisely good, we see a 13% percent incresing in search revenue which is way beyond my expectation. The leadership team highly appreciated what I did. And it is also a precious learning experience of me. 

L:

- What I learned from this experiences is that you don't need to be a senior or manager to speak out your idea. Everyone's opinion is valuable. And sometimes, a solution doesn't need to be very complicated, a simple solution can make a big impact. Like what facebook values, Be Bold and focus on impact. 



### leadership

on board new-worker, lead autocomplete system

S： 

- In the last year, our company faced a big reorg. We onboard several new members from UK department.  
- My manager want me onboarding one of the new member and  implement the autocomplete services for our new search architecture with her.
- It is my first time that I need to lead a project and onboarded a new member

A:

- I first walked through our documents. I found that we dont have a structured document for new member to quickly learn our architecture, so I wrote a onboarding documents for our new members to help them learn each components of our search architecure and how they can settle up in the their local environment
- After that, I start to design the autocomplete services. After carefully reviewed with our tech lead, I divided the responsibity of the project with my co-worker and set up the timeline to make sure we can deliver on time. 
- Her previous work experience is more focuing on data engineer instead of backend engineer. To prevent her from blocking, I scheduled a half hour pair programming everyday to sync up and see if she has any questions and need any help
- At the mean time, I work with the data team to request the data we need for autocomplete service and build a data pipeline with them. 

R:

- Finally, we successfully deployed the autocompelete service on time. The service works pretty good in the production. My manager highly appreiciate our hardwork and my leadership in this project.

12. 处理突击任务/多项任务‍‍‍‌‌‍‌‌‌‍‍‌‍‍‍‍‌‌ Tell me about a time you had to manage conflicting priorities

13. tell me about yourself

- Your current and past experiences,
- Your core strengths,
- Your personality, and
- Your ability to respond to an unstructured question.





5. why leaving



What is the currently remote work policy in facebook? Do you know how it will change after the pandemic?

How is work life balance in Facebook?

 What kind of team culture do you have? Is there a team happy hour ?

How many people are currently in your team? Whatis the distribution between senior and junior engineers?

What is the new-hire onboarding process?

How and when are the performance reviews conducted?

What is your favorite part about working here?

What are the current projects that you are working on ?

What gets you most excited about the company's future?



















https://www.youtube.com/watch?v=Hr5UJnKxwyg&t=1642s

https://www.1point3acres.com/bbs/thread-686097-1-1.html

https://www.1point3acres.com/bbs/thread-760667-1-1.html

