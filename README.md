# seeed-ardupy-TFLidar [![Build Status](https://travis-ci.com/Seeed-Studio/seeed-ardupy-TFLidar.svg?branch=master)](https://travis-ci.com/Seeed-Studio/seeed-ardupy-TFLidar)

## Introduction

The TF Mini LiDAR is based on the ToF (Time of Flight) principle and integrated with unique optical and electrical designs, so as to achieve stable, precise, high sensitivity, and high-speed distance detection.

You can get more information in here [Grove - TF Mini LiDAR](https://wiki.seeedstudio.com/Grove-TF_Mini_LiDAR/).

## How to binding with ArduPy

- Install [AIP](https://github.com/Seeed-Studio/ardupy-aip)

- Build firmware with Seeed ArduPy TFLidar

```shell
aip install Seeed-Studio/seeed-ardupy-TFLidar
aip build
```

- Flash new firmware to you ArduPy board

```shell
aip flash # + Ardupy Bin PATH
```

For more examples of using AIP, please refer to [AIP](https://github.com/Seeed-Studio/ardupy-aip).

## Usage

```python
from arduino import grove_tf_lidar
import time

lidar = grove_tf_lidar()

while True:
    while(lidar.get_frame_data() == False):
        time.sleep(0.001)
    print ("The distance is:", lidar.distance, 'CM')
    print ("The strength is:", lidar.strength, '')
    time.sleep_ms(1000)
```

## API Reference

- **get_frame_data()** :  get frame data (include distance and strength)

```python
while(lidar.get_frame_data() == False):
    time.sleep(0.001)
```

- **distance** :distance from obstacle

```python
print ("The distance is:", lidar.distance, 'CM')
```

- **strength** : lidar strength

```python
print ("The strength is:", lidar.strength, '')
```

----

This software is written by seeed studio<br>
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>
