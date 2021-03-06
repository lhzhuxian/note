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
 // Creating empty priority queue
PriorityQueue<Integer> pQueue = new PriorityQueue<Integer>();
 
// Adding items to the pQueue using add()
pQueue.add(10);
pQueue.add(20);
pQueue.add(15);

// 10, 20, 15 default是max stack， 排最前面的是最小的值
 PriorityQueue<Integer> min = new  PriorityQueue<Integer>(Collections.reverseOrder());
```

