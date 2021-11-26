https://www.bilibili.com/video/BV1w4411y7Go?from=search&seid=5206766687820906971





### kubernetes

Kubernetes is a portable, extensible, open-source platform for **managing containerized workloads and services**, that facilitates both declarative configuration and automation



### Why Kubernetes

That's how Kubernetes comes to the rescue! Kubernetes provides you with a framework to run distributed systems resiliently. **It takes care of scaling and failover for your application, provides deployment patterns, and more. For example, Kubernetes can easily manage a canary deployment for your system.**

- **Service discovery and load balancing** Kubernetes can expose a container using the DNS name or using their own IP address. If traffic to a container is high, Kubernetes is able to load balance and distribute the network traffic so that the deployment is stable.
- **Storage orchestration** Kubernetes allows you to automatically mount a storage system of your choice, such as local storages, public cloud providers, and more.
- **Automated rollouts and rollbacks** You can describe the desired state for your deployed containers using Kubernetes, and it can change the actual state to the desired state at a controlled rate. For example, you can automate Kubernetes to create new containers for your deployment, remove existing containers and adopt all their resources to the new container.
- **Automatic bin packing** You provide Kubernetes with a cluster of nodes that it can use to run containerized tasks. You tell Kubernetes how much CPU and memory (RAM) each container needs. Kubernetes can fit containers onto your nodes to make the best use of your resources.
- **Self-healing** Kubernetes restarts containers that fail, replaces containers, kills containers that don't respond to your user-defined health check, and doesn't advertise them to clients until they are ready to serve.
- **Secret and configuration management** Kubernetes lets you store and manage sensitive information, such as passwords, OAuth tokens, and SSH keys. You can deploy and update secrets and application configuration without rebuilding your container images, and without exposing secrets in your stack configuration.



### cluster（集群）

A *Kubernetes cluster* is a set of nodes that run containerized applications.

k8s 集群是一组运行容器化应用程序的节点计算机。如果你在运行 Kubernetes，实际上就是在运行集群 。

### pod

*Pods* are the smallest deployable units of computing that you can create and manage in Kubernetes.

Pod是Kubernetes中能够创建和部署的最小单元，是Kubernetes集群中的一个应用实例，总是部署在同一个节点Node上。Pod中包含了一个或多个容器，还包括了存储、网络等各个容器共享的资源。Pod支持多种容器环境，Docker则是最流行的容器环境。

- 单容器Pod，最常见的应用方式。
- 多容器Pod，对于多容器Pod，Kubernetes会保证所有的容器都在同一台物理主机或虚拟主机中运行。多容器Pod是相对高阶的使用方式，除非应用耦合特别严重，一般不推荐使用这种方式。一个Pod内的容器共享IP地址和端口范围，容器之间可以通过 localhost 互相访问。

### Namespace

Kubernetes supports multiple *virtual* clusters backed by the same *physical* cluster. These virtual clusters are called namespaces. Namespaces are intended for use in environments with many users spread across multiple teams, or projects.

Quite simply, namespaces are where your deployed applications reside.

### Helm

**Helm是**Kubernetes的一个包管理工具，用来简化Kubernetes应用的部署和管理。 可以把**Helm**比作CentOS的yum工具。 通过使用使用**Helm**可以管理Kubernetes manifest files、管理**Helm**安装包charts、基于chart的Kubernetes应用分发。



![Deployment evolution](https://d33wubrfki0l68.cloudfront.net/26a177ede4d7b032362289c6fccd448fc4a91174/eb693/images/docs/container_evolution.svg)

Containers are similar to VMs, but they have relaxed isolation properties to **share the Operating System (OS)** among the applications. Therefore, containers are considered lightweight. Similar to a VM, a container has its **own filesystem, share of CPU, memory, process space, and more**. As they are decoupled from the underlying infrastructure, they are portable across clouds and OS distributions.





### Kubectl

[cheat sheet](https://kubernetes.io/docs/reference/kubectl/cheatsheet/)

[kubectl](https://kubernetes.io/docs/reference/kubectl/overview/) is the command line tool used to interact with Kubernetes clusters and therefore also with your Managed Containers namespace.

```bash
kubectl get deploy -n namespace  ## Check the status of your deployment
kubectl describe deploy deploymentName -n namespace ## Check the detailed status of a deployment
kubectl get pods -l app=nginx -n namespace ## Check the status of a single pod in a deployment
kubectl logs frontend-deployment-5d7c89c76c-djgh2 ## Viewing the application logs inside of a pod
kubectl exec -it {pod name} -- /bin/bash ## Getting a command line in your container

```

