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



## Generateing random numbers in Java

```java
// java.util.Random
// create instance of Random class
Random rand = new Random();
// Generate random integers in range 0 to 999
int rand_int1 = rand.nextInt(1000);
int rand_int2 = rand.nextInt(1000);

// Math.random()
// returns a double value with a positive sign, greater than or equal to 0.0 and less than 1.0
Math.random();

// java.util.concurrent.ThreadLocalRandom class
// Generate random integers in range 0 to 999
int rand_int1 = ThreadLocalRandom.current().nextInt();
double rand_dub1 = ThreadLocalRandom.current().nextDouble();
boolean rand_bool1 = ThreadLocalRandom.current().nextBoolean();
```





## java 各个collections的底层结构和对应的时间复杂度



## RegEx

https://www.w3schools.com/java/java_regex.asp

## String

#### convert int to String

```java
int i=10;  
String s=String.valueOf(i);//Now it will return "10"  

int i=10;  
String s=Integer.toString(i);//Now it will return "10"  

int i=200;  
String s=String.format("%d",i);  
```

#### join list string

```java
List<String> list = Arrays.asList("a","b","c");
String result = String.join(",", list);
```

#### spilt

```java
/*
Parameters:
regex - a delimiting regular expression
Limit - the result threshold, default 0

Returns:
An array of strings computed by splitting the given string.

Throws:
PatternSyntaxException - if the provided regular expression’s 
                         syntax is invalid.  
  
 limit > 0 : If this is the case then the pattern will be
            applied at most limit-1 times, the resulting 
            array’s length will not be more than n, and 
            the resulting array’s last entry will contain
            all input beyond the last matched pattern.
limit < 0 : In this case, the pattern will be applied as
            many times as possible, and the resulting 
            array can be of any size.
limit = 0 : In this case, the pattern will be applied as 
            many times as possible, the resulting array can 
            be of any size, and trailing empty strings will
            be discarded.
  */
String str = "geekss@for@geekss";
String[] arrOfStr = str.split("@", 2); // geekss, for@geekss
String[] arrOfStr = str.split("@", 5); // geekss, for, geekss
```





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

## Collection

#### static api



### Map

#### TreeMap

##### Default Sorting in TreeMap

By default, *TreeMap* sorts all its entries according to their natural ordering. For an integer, this would mean ascending order and for strings, alphabetical order.

```java

public void givenTreeMap_whenOrdersEntriesNaturally_thenCorrect() {
    TreeMap<Integer, String> map = new TreeMap<>();
    map.put(3, "val");
    map.put(2, "val");
    map.put(1, "val");
    map.put(5, "val");
    map.put(4, "val");

    assertEquals("[1, 2, 3, 4, 5]", map.keySet().toString());
}
```

##### Custom Sorting in TreeMap

If we're not satisfied with the natural ordering of *TreeMap*, we can also define our own rule for ordering by means of a comparator during construction of a tree map.

In the example below, we want the integer keys to be ordered in descending order:

```java
@Test
public void givenTreeMap_whenOrdersEntriesByComparator_thenCorrect() {
    TreeMap<Integer, String> map = 
      new TreeMap<>(Comparator.reverseOrder());
    map.put(3, "val");
    map.put(2, "val");
    map.put(1, "val");
    map.put(5, "val");
    map.put(4, "val");
        
    assertEquals("[5, 4, 3, 2, 1]", map.keySet().toString());
}
```

##### Useful api

We now know that *TreeMap* stores all its entries in sorted order. Because of this attribute of tree maps, we can perform queries like; find “largest”, find “smallest”, find all keys less than or greater than a certain value, etc.

The code below only covers a small percentage of these cases:

```java
@Test
public void givenTreeMap_whenPerformsQueries_thenCorrect() {
    TreeMap<Integer, String> map = new TreeMap<>();
    map.put(3, "val");
    map.put(2, "val");
    map.put(1, "val");
    map.put(5, "val");
    map.put(4, "val");
        
    Integer highestKey = map.lastKey();
    Integer lowestKey = map.firstKey();
    Set<Integer> keysLessThan3 = map.headMap(3).keySet();
    Set<Integer> keysGreaterThanEqTo3 = map.tailMap(3).keySet();

    assertEquals(new Integer(5), highestKey);
    assertEquals(new Integer(1), lowestKey);
    assertEquals("[1, 2]", keysLessThan3.toString());
    assertEquals("[3, 4, 5]", keysGreaterThanEqTo3.toString());
}
/*
floorEntry(K key)
Returns a key-value mapping associated with the greatest key less than or equal to the given key, or null if there is no such key.
floorKey(K key)
Returns the greatest key less than or equal to the given key, or null if there is no such key.
higherEntry(K key)
Returns a key-value mapping associated with the least key strictly greater than the given key, or null if there is no such key.
higherKey(K key)
Returns the least key strictly greater than the given key, or null if there is no such key.
*/
```

##### Internal Implementation of TreeMap

>
>
>*TreeMap* implements *NavigableMap* interface and bases its internal working on the principles of [red-black trees](https://www.baeldung.com/cs/red-black-trees):
>
>```java
>public class TreeMap<K,V> extends AbstractMap<K,V>
>  implements NavigableMap<K,V>, Cloneable, java.io.Serializable
>```
>
>The principle of red-black trees is beyond the scope of this article, however, there are key things to remember in order to understand how they fit into *TreeMap*.
>
>**First of all**, a red-black tree is a data structure that consists of nodes; picture an inverted mango tree with its root in the sky and the branches growing downward. The root will contain the first element added to the tree.
>
>The rule is that starting from the root, any element in the left branch of any node is always less than the element in the node itself. Those on the right are always greater. What defines greater or less than is determined by the natural ordering of the elements or the defined comparator at construction as we saw earlier.
>
>This rule guarantees that the entries of a treemap will always be in sorted and predictable order.
>
>**Secondly**, a red-black tree is a self-balancing binary search tree. This attribute and the above guarantee that basic operations like search, get, put and remove take logarithmic time *O(log n)*.
>
>Being self-balancing is key here. As we keep inserting and deleting entries, picture the tree growing longer on one edge or shorter on the other.
>
>This would mean that an operation would take a shorter time on the shorter branch and longer time on the branch which is furthest from the root, something we would not want to happen.
>
>Therefore, this is taken care of in the design of red-black trees. For every insertion and deletion, the maximum height of the tree on any edge is maintained at *O(log n)* i.e. the tree balances itself continuously.
>
>Just like hash map and linked hash map, a tree map is not synchronized and therefore the rules for using it in a multi-threaded environment are similar to those in the other two map implementations.

#### LinkedHashMap

#### HashMap

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

