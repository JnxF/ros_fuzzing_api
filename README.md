# ROS Fuzzing API

![Hits](https://visitor-badge.glitch.me/badge?page_id=jnxf._ros_fuzzing_api)
[![GitHub stars](https://img.shields.io/github/stars/JnxF/ros_fuzzing_api.svg)](https://GitHub.com/JnxF/ros_fuzzing_api/stargazers/)
[![GitHub forks](https://img.shields.io/github/forks/JnxF/ros_fuzzing_api.svg)](https://GitHub.com/JnxF/ros_fuzzing_api/network/)
[![GitHub repo size in bytes](https://img.shields.io/github/repo-size/JnxF/ros_fuzzing_api.svg)](https://github.com/JnxF/ros_fuzzing_api)
[![GitHub contributors](https://img.shields.io/github/contributors/JnxF/ros_fuzzing_api.svg)](https://GitHub.com/JnxF/ros_fuzzing_api/graphs/contributors/)
[![GitHub license](http://img.shields.io/github/license/JnxF/ros_fuzzing_api.svg)](https://github.com/JnxF/ros_fuzzing_api/blob/master/LICENSE)

Header-only library to generate C++ type primitives for fuzzing ROS 2. This library conforms to the [official documentation](https://design.ros2.org/articles/generated_interfaces_cpp.html#mapping-of-primitive-types).

## Installation

Clone this repository and link it appropriately in a `CMakeLists.txt` file with the `fuzzing_api_library` cmake library.

## Usage

Import the [fuzzing_api.hpp](src/fuzzing_api.hpp) file and pass the variable by reference to be read. All the functions return a boolean indicating whether the reading was successful or not, so using them inside of `if` and `while` statements is useful. Check the file for the whole list.

### Examples

Read one value:

```c++
#include <iostream>
#include "fuzzing_api.hpp"

int main() {
    float f;
    if (getFloat32(f)) {
        std::cout << "I read: " << f << std::endl;
    } else {
        std::cerr << "Couldn't read a float" << std::endl;
    }
}
```
Read as many pairs of values as possible:

```c++
#include <iostream>
#include "fuzzing_api.hpp"

int main() {
    int8_t a, b;
    while (getInt8(a) && getInt8(b)) {
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << a << std::endl;
    }
}
```

Reading a string of a constrained size (always recommended with strings):

```c++
#include <iostream>
#include "fuzzing_api.hpp"

int main() {
    uint8_t length;
    getUInt8(length);

    std::string s;
    if (getString(s, length % 30)) {
        std::cout << "A string shorter than 30 characters:";
        std::cout << s << std::endl;
    } else {
        std::cerr << "Couldn't read the string" << std::endl;
    }
}
```

## Test
Run the `fuzz.sh` command with `source fuzz.sh` to start a 10 minute fuzzing session. If you haven't installed it yet, install AFL (`apt-get install afl` or `brew install afl` on Mac).


## License
[MIT](https://choosealicense.com/licenses/mit/)

## Acknowledgements

<!--
    ROSIN acknowledgement from the ROSIN press kit
    @ https://github.com/rosin-project/press_kit
-->

<a href="http://rosin-project.eu">
  <img src="http://rosin-project.eu/wp-content/uploads/rosin_ack_logo_wide.png" alt="rosin_logo" height="60">
</a>

Supported by ROSIN - ROS-Industrial Quality-Assured Robot Software Components.
More information: <a href="http://rosin-project.eu">rosin-project.eu</a>

<img src="http://rosin-project.eu/wp-content/uploads/rosin_eu_flag.jpg" alt="eu_flag" height="45" align="left" >

This project has received funding from the European Union’s Horizon 2020 research and innovation programme under grant agreement no. 732287.

