## 1657 Determine if Two Strings Are Close

Two strings are considered **close** if you can attain one from the other using the following operations:

- Operation 1: Swap any two existing characters.
  - For example, `abcde -> aecdb`
- Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
  - For example, `aacabb -> bbcbaa` (all `a`'s turn into `b`'s, and all `b`'s turn into `a`'s)

You can use the operations on either string as many times as necessary.

Given two strings, `word1` and `word2`, return `true` *if* `word1` *and* `word2` *are **close**, and* `false` *otherwise.*

**Example 1:**

```
Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
```

**Example 2:**

```
Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
```

**Example 3:**

```
Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
```

**Example 4:**

```
Input: word1 = "cabbba", word2 = "aabbss"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any amount of operations.
```

 **Solution**

```java
class Solution {

    public boolean closeStrings(String word1, String word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        Map<Character, Integer> word1Map = new HashMap<>();
        Map<Character, Integer> word2Map = new HashMap<>();
        for (char c : word1.toCharArray()) {
            word1Map.put(c, word1Map.getOrDefault(c, 0) + 1);
        }
        for (char c : word2.toCharArray()) {
            word2Map.put(c, word2Map.getOrDefault(c, 0) + 1);
        }
        if (!word1Map.keySet().equals(word2Map.keySet())) {
            return false;
        }
        List<Integer> word1FrequencyList = new ArrayList<>(word1Map.values());
        List<Integer> word2FrequencyList = new ArrayList<>(word2Map.values());
        Collections.sort(word1FrequencyList);
        Collections.sort(word2FrequencyList);
        return word1FrequencyList.equals(word2FrequencyList);
    }
}
```





## 249 Group Shifted Strings

We can shift a string by shifting each of its letters to its successive letter.

- For example, `"abc"` can be shifted to be `"bcd"`.

We can keep shifting the string to form a sequence.

- For example, we can keep shifting `"abc"` to form the sequence: `"abc" -> "bcd" -> ... -> "xyz"`.

Given an array of strings `strings`, group all `strings[i]` that belong to the same shifting sequence. You may return the answer in **any order**.

**Example 1:**

```
Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
```

**Example 2:**

```
Input: strings = ["a"]
Output: [["a"]]
```

**Solution**

shift all the string to start with 'a'

```java
class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        Map<String, List<String> > map = new HashMap<>();
        for(String s : strings) {
            String init = shiftToInit(s);
            if(!map.containsKey(init)) {
                map.put(init, new ArrayList<>());
            }
            map.get(init).add(s);
        }
        List<List<String> > result = new ArrayList<>();
        for(List<String> l : map.values()) {
            result.add(l);
        }
        return result;
    }
    
    private String shiftToInit(String s) {
        if(s.isEmpty()) {
            return s;
        }
        s = s.toLowerCase();
        int offset = s.charAt(0) - 'a';
        StringBuilder sb = new StringBuilder();
        for(char c : s.toCharArray()) {
            c -= offset;
          // char shift 的小技巧
            if(c < 'a') {
                c += 26;
            }
            sb.append(c);
        }
        return sb.toString();
    }
}
```

