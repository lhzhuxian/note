## Array



```java
//Array Literal
// The length of this array determines the length of the created array.
// There is no need to write the new int[] part in the latest versions of Java
 int[] intArray = new int[]{ 1,2,3,4,5,6,7,8,9,10 };  // Declaring array literal


// two dimension array
// https://www.java67.com/2014/10/how-to-create-and-initialize-two-dimensional-array-java-example.html

// array copy
int[] array = {23, 43, 55, 12};
int newLength = array.length;
int[] copiedArray = Arrays.copyOf(array, newLength);
int[] copiedArray = Arrays.copyOfRange(array, 1, 4);

```



## Sort

```java
Arrays.sort(arr);
Arrays.sort(boxTypes, (a, b) -> b[1] - a[1]);
Collections.sort()
```



## PriorityQueue

```java
boolean add(E e) // O(log)
E poll() // O(log)
boolean contains(Object o)  // O(n)
boolean remove(Object o) // O(n)
```



```java
 // Creating empty priority queue
PriorityQueue<Integer> pQueue = new PriorityQueue<Integer>();
 
// Adding items to the pQueue using add()
pQueue.add(10);
pQueue.add(20);
pQueue.add(15);

// 10, 20, 15 default是max stack， 排最前面的是最小的值
 PriorityQueue<Integer> min = new  PriorityQueue<Integer>(Collections.reverseOrder());
```

## Stack

```java
stack.pop();
stack.push();
stack.peek();
stack.isEmpty();
```

## Deque

## LinkedList

```java
LinkedList<String> ll = new LinkedList<String>();
ll.add("B");
ll.addLast("C");
ll.addFirst("D");
ll.add(2, "E");
ll.remove(3);
ll.removeFirst();
ll.removeLast();
ll.set(1, "For"); 
```

## **StringBuilder**

```java
sb.deleteCharAt(index);
sb.append(character);
```



## String

```java
String[] brokenSentence = words
            .replaceAll("\\W", " ");
// java pattern
// \W 	A non-word character: [^\w]
String[] brokenSentence = words
            .split(" ");   

```



## TreeMap

```java
floorKey(K key)
Returns the greatest key less than or equal to the given key, or null if there is no such key.

higherKey(K key)
Returns the least key strictly greater than the given key, or null if there is no such key.

ceilingKey(K key)
Returns the least key greater than or equal to the given key, or null if there is no such key.

firstKey()
Returns the first (lowest) key currently in this map.

	lastKey()
Returns the last (highest) key currently in this map.

headMap(K toKey)
Returns a view of the portion of this map whose keys are strictly less than toKey.

tailMap(K fromKey)
Returns a view of the portion of this map whose keys are greater than or equal to fromKey.
```



## Collections

```
Collections.reverse()
Collections.sort()
Collections.swap(List list, int i, int j)
```

### Random

- For using this class to generate random numbers, we have to first create an instance of this class and then invoke methods such as nextInt(), nextDouble(), nextLong() etc using that instance.
- We can generate random numbers of types integers, float, double, long, booleans using this class.
- We can pass arguments to the methods for placing an upper bound on the range of the numbers to be generated. For example, nextInt(6) will generate numbers in the range 0 to 5 both inclusive.

```java
// Generate random integers in range 0 to 999
int rand_int1 = rand.nextInt(1000);
```

