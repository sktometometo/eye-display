# eye-display

## How to use

```bash
pip3 install platformio
```

```bash
cd lib
rosrun rosserial_arduino make_libraries.py .
cd ..
pio run
```

And burn it.

```bash
pio run -t upload --upload-port <port to device>
pio run -t uploadfs --upload-port <port to device>
```

And connect it with rosserial

```bash
roscore
```

```bash
rosrun rosserial_python serial_node.py _port:=<port to device> _baud:=57600
```

You can move the eye with

```bash
rostopic pub -1
```
