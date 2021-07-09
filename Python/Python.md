# docker

https://aws.amazon.com/cn/blogs/china/choose-the-best-docker-image-for-your-python-application/

# package

比较好的blog：
https://github.com/gaborbernat

https://bernat.tech/posts/pep-517-and-python-packaging/



## Python type check

https://fastapi.tiangolo.com/zh/python-types/

### virtual environment management

```bash
// 创建venv
python -m venv snow-venv 
// 激活虚拟环境
source snow-venv/bin/activate
//使用 pip 管理依赖
pip install flask
更新依赖：
pip install --upgrade flask
pip install -U flask
卸载依赖：
pip uninstall flask
//手动生成依赖列表
pip freeze > requirements.txt
// 安装依赖
pip install -r requirements.txt
```



## demo

**csv**



```python
#read csv file
    with open('file.csv', 'r') as file:
        reader = csv.reader(file)
        for row in reader:
          print(row)
#write csv file
with open('employee_file.csv', mode='w') as employee_file:
    employee_writer = csv.writer(employee_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
    employee_writer.writerow(['John Smith', 'Accounting', 'November'])
    employee_writer.writerow(['Erica Meyers', 'IT', 'March'])
```

```python
#request
https://www.nylas.com/blog/use-python-requests-module-rest-apis/
  
import requests
response = requests.get("http://api.open-notify.org/astros.json")
print(response)
>>>> Response<200>

response.content() # Return the raw bytes of the data payload
response.text() # Return a string representation of the data payload
response.json() # This method is convenient when the API returns JSON

query = {'lat':'45', 'lon':'180'}
response = requests.get('http://api.open-notify.org/iss-pass.json', params=query)
print(response.json())

# Create a new resource
response = requests.post('https://httpbin.org/post', data = {'key':'value'})
# Update an existing resource
requests.put('https://httpbin.org/put', data = {'key':'value'})

print(response.headers["date"]) 
>>>> 'Wed, 11 June 2020 19:32:24 GMT'

requests.get(
  'https://api.github.com/user', 
  auth=HTTPBasicAuth('username', 'password')
)
# add headers in the request
response = requests.get("https://www.walmart.com.mx/api/v2/content/Shared/Taxonomy", headers={'User-Agent': 'PostmanRuntime/7.26.8'})
```

```python
"My name is {fname}, I'm {age}".format(fname = "John", age = 36)
```

```python
#Python enumerate(): Simplify Looping With Counters
>>> for count, value in enumerate(values):
...     print(count, value)
...
0 a
1 b
2 c
```

# Errors and Exceptions

### catching any exception

You would normally only ever consider doing this at the outermost level of your code if for example you wanted to handle any otherwise uncaught exceptions before terminating.

The advantage of `except Exception` over the bare `except` is that there are a few exceptions that it wont catch, most obviously `KeyboardInterrupt` and `SystemExit`: if you caught and swallowed those then you could make it hard for anyone to exit your script.

```python
import traceback
import logging

try:
    whatever()
except Exception as e:
    logging.error(traceback.format_exc())
    # Logs the error appropriately. 
```

