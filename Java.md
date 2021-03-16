#### Java demo

```java
// wrong:
String s = "hello"
for(char c : s) {
}
// correct:
for(char c : s.toCharArray()) {
}
```

```java
/**
	Syntax:
  Hash_Map.values()
  Parameters: The method does not accept any parameters.
  Return Value: The method is used to return a collection view containing all the values of the map.
  Below programs are used to illustrate the working of java.util.HashMap.values() Method:
  Program 1: Mapping String Values to Integer Keys.
*/
for(List<String> list: map.values()) {
	Collections.sort(list);
}
```

## 

````java
Syntax:
// Makes all elements of a[] equal to "val"
public static void fill(int[] a, int val)

// Makes elements from from_Index (inclusive) to to_Index
// (exclusive) equal to "val"
public static void fill(int[] a, int from_Index, int to_Index, int val)

// This method doesn't return any value.

int[] ar = new int[5]
// To fill complete array with a particular 
// value 
Arrays.fill(ar, 10); 
````





## java 各个collections的底层结构和对应的时间复杂度



## Java api

#### String

```java
// int indexOf(char ch, int strt ) : This method returns the index within this string of the first occurrence of the specified character, starting the search at the specified index or -1, if the character does not occur.
// int indexOf() : This method returns the index within this string of the first occurrence of the specified character or -1, if the character does not occur.
indexOf()

subString()
```

#### Character

```java
isDigit()
```

#### Queue

```java
add()
peek()
// The remove() and poll() methods differ only in their behavior when the queue is empty: the remove() method throws an exception, while the poll() method returns null. The element() and peek() methods return, but do not remove, the head of the queue.
remove() vs poll()
Queue<TreeNode> level = new LinkedList<>();
```

#### Collection

```
sort
Comparator
```

#### Comparable vs Comparator in Java

>A comparable object is capable of comparing itself with another object. The class itself must implements the **java.lang.Comparable** interface to compare its instances. 
>Consider a Movie class that has members like, rating, name, year. Suppose we wish to sort a list of Movies based on year of release. We can implement the Comparable interface with the Movie class, and we override the method compareTo() of Comparable interface. 
>
>Unlike Comparable, Comparator is external to the element type we are comparing. It’s a separate class. We create multiple separate classes (that implement Comparator) to compare by different members.
>Collections class has a second sort() method and it takes Comparator. The sort() method invokes the compare() to sort objects.

#### Comparator

```java
//jdk官方默认是升序  
Collections.sort(list, new Comparator<Integer>() {
    @Override
    public int compare(Integer o1, Integer o2) {
      //下面这么写，结果是升序
      /*如果保持这个顺序就返回-1，交换顺序就返回1，什么都不做就返回0；所以 升序的话 如果o1<o2，就返回-1。*/
      //if (o1 < o2 ) {
      //     return  -1;
      //}else if (o1 > o2) {
      //    return 1;
      //}
      //return  0;

      //下面这么写，结果是降序
      /*如果保持这个顺序就返回-1，交换顺序就返回1，什么都不做就返回0；所以 升序的话 如果o1<o2，就返回-1。*/
      if (o1 < o2) {
        return 1;
      } else if (o1 > o2) {
        return -1;
      }
      return 0;
    }
  });

```



## Java feature

#### Lambda

