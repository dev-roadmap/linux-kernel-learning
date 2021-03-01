# Kernel Learning

## Starting point

To learn about Linux Kernel, the starting point is knowing that everything is a file. Instead of opening the Task Manager, you can inspect the content of `/proc` folder. You can control everything on your running linux instance only inspecting some files.

For example:

| Folder | Content |
|--------|---------|
| `/proc` | All running process information |
| `/dev` | All available devices |
| `/sys` |  |


## Checking hardware info

You can use the commands bellow:
* `lshw`
* `lspci`
* `lsusb`
* `lsbk`
* `lscpu`
* `lsdev`

Maybe your linux distro does not have some of theses commands, or maybe you have to install it. Using Ubuntu 20.04 on Windows WSL 2, I found working:

* `lshw`
* `lspci`
* `lsusb`
