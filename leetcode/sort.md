## 1233 Remove Sub-Folders from the Filesystem

Given a list of folders, remove all sub-folders in those folders and return in **any order** the folders after removing.

If a `folder[i]` is located within another `folder[j]`, it is called a sub-folder of it.

The format of a path is one or more concatenated strings of the form: `/` followed by one or more lowercase English letters. For example, `/leetcode` and `/leetcode/problems` are valid paths while an empty string and `/` are not.

 

**Example 1:**

```
Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
Output: ["/a","/c/d","/c/f"]
Explanation: Folders "/a/b/" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
```

**Example 2:**

```
Input: folder = ["/a","/a/b/c","/a/b/d"]
Output: ["/a"]
Explanation: Folders "/a/b/c" and "/a/b/d/" will be removed because they are subfolders of "/a".
```

**Example 3:**

```
Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
Output: ["/a/b/c","/a/b/ca","/a/b/d"]
```

**Solution**

**sort by length then put only parent into HashSet**

1. Sort `folder` by length;
2. Check if the floder's parent fold in HashSet before adding it into the HashSet.
   Note: the part before any `/` is a parent.

**sort folders**

1. Sort the folders;
2. For each folder check if the followings are child folders; if yes, ignore; otherwise, count it in.

```java
 public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder, Comparator.comparing(s -> s.length()));
        Set<String> seen = new HashSet<>();
        outer:
        for (String f : folder) {
            for (int i = 2; i < f.length(); ++i)
                if (f.charAt(i) == '/' && seen.contains(f.substring(0, i))) 
                    continue outer;
            seen.add(f);
        }
        return new ArrayList<>(seen);
    }
    
    public List<String> removeSubfolders(String[] folder) {
        LinkedList<String> ans = new LinkedList<>();
        Arrays.sort(folder);
        for (String f : folder)
            if (ans.isEmpty() || !f.startsWith(ans.peekLast() + '/')) //  need '/' to ensure a parent.
                ans.offer(f);
        return ans;
    }

 public List<String> removeSubfolders(String[] folder) {
        LinkedList<String> ans = new LinkedList<>();
        Arrays.sort(folder);
        for (String f : folder)
            if (ans.isEmpty() || !f.startsWith(ans.peekLast() + '/')) //  need '/' to ensure a parent.
                ans.offer(f);
        return ans;
    }
```

