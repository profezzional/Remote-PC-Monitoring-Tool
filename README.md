# Remote-PC-Monitoring-Tool
Cross-platform desktop client/server and mobile app to display and monitor PC vitals and stats


## Sensor Status:
| Sensor | Status |
| --- | --- |
| CPU Temp | Placeholder |
| CPU Usage | Placeholder |
| GPU Memory | Complete |
| GPU Temperature | Complete |
| GPU Usage | Placeholder |
| Memory Usage | Placeholder |


## Developer Docs

* [Adding Sensors](docs/AddingSensors.md)
*[**To-do list**](docs/todo.md)

## Build Guide

### Windows:

#### Status:
| Build Source | Status |
| --- | --- |
| Visual Studio | Working |
| Batch File | Not Working |

#### Requirements:
* [Git](https://git-scm.com/download/win)
* [Visual Studio 2019](https://visualstudio.microsoft.com/vs/community/) with `Desktop Development with C++` Workload selected: 

![See here](docs/vs_installershell_UescUGq5ae.png)

#### Building:
```
git clone https://github.com/profezzional/Remote-PC-Monitoring-Tool
cd Remote-PC-Monitoring-Tool
build.bat
```


### Linux/OSX:

#### Requirements:
* Git (`sudo apt install git`)
* CMake (`sudo apt install cmake`)
* Make (`sudo apt install make`)
* G++ (`sudo apt install g++`)

#### Building:
```
git clone https://github.com/profezzional/Remote-PC-Monitoring-Tool
cd Remote-PC-Monitoring-Tool
chmod +X ./build.sh
./build.sh
```