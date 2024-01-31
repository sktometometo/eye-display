# Eye Display Module

Eye Display Example

## Supported devices

1. Round Display Module with M5Stamp C3 (pio env name: `stampc3`) : https://www.switch-science.com/products/8098
2. Round Display Module with M5Stamp S3 (pio env name: `stamps3`) : https://www.switch-science.com/products/8971

## How to use

First you have to install ROS and PlatformIO

```bash
pip install platformio
```

And then, you can build and upload the firmware to the device.

For simple_version and type 1 device (display module with m5stamp-c3)

```bash
cd simple_version
pio run -e stampc3
pio run -e stampc3 -t uploadfs --upload-port <port to device>
pio run -e stampc3 -t upload --upload-port <port to device>
```

Then simple_version will work

For rosserial_version and type 2 device (display module with m5stamp-s3)

```bash
cd rosserial_version
pio run -e stamps3
pio run -e stamps3 -t uploadfs --upload-port <port to device>
pio run -e stamps3 -t upload --upload-port <port to device>
```

And run serial node

```bash
roscore
```

```bash
rosrun rosserial_python serial_node.py _port:=<port to device> _baud:=57600
```

Then rosserial_version will work.

You can control pupil position by publish a message to "/serial_node/look_at" topic.

```bash
rostopic pub -1 /serial_node/look_at geometry_msgs/Point "{x: 1.0, y: 1.0, z: 0.0}"
```

You can control emotion expression with eye by publishing a message to "/eye_status" topic.

```bash
rostopic pub -1 /eye_status std_msgs/UInt16 "data: 0"
```
The following table shows the correspondence between the data and the emotional expression of the eyes.
| data | emotion |
|---|---|
|0| normal |
|1| blink |
|2| surprised |
|3| sleepy (tired) |
|4| angry |
|5| sad / troubled |
|6| happy (star) |
|7| heart |

