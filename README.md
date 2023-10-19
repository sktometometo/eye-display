# Eye Display Module

Eye Display Example

## Supported devices

- https://www.switch-science.com/products/8098

## How to use

First you have to install ROS and PlatformIO

```bash
pip install platformio
```

And then, you can build and upload the firmware to the device.

For simple_version

```bash
cd simple_version
pio run
pio run -t uploadfs --upload-port <port to device>
pio run -t upload --upload-port <port to device>
```

Then simple_version will work

For rosserial_version

```bash
cd rosserial_version
pio run
pio run -t uploadfs --upload-port <port to device>
pio run -t upload --upload-port <port to device>
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