### hard reset branch

```shell
git fetch origin master
git reset --hard FETCH_HEAD
```

### Managing remote repositories



```shell
git remote add origin https://github.com/user/repo.git
# Set a new remote
$ git remote -v
# Verify new remote
> origin  https://github.com/user/repo.git (fetch)
> origin  https://github.com/user/repo.git (push)
# Changing a remote repository's URL
git remote set-url origin https://github.com/USERNAME/REPOSITORY.git
# Change remote name from 'origin' to 'destination'
git remote rename origin destination
#Removing a remote repository
git remote rm destination
```

