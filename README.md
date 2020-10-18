## Ascii decoder
Simple decoder creating, according to given rules, ascii chars from string of digits.

## Table of content
- [Problem description](#problem-description)
- [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Building](#building)
- [Built with](#built-with)
- [Usage](#usage)
- [Testing](#testing)
- [License](#license)

## Problem description
Decode string of digits into ascii string with following rules:
* Each 4 consecutive digits encodes 1 ascii char.
* Digit 1 and 3 of 4 digits sequence need to be concatenated to get first number.
* Digit 2 and 4 of 4 digits sequence need to be concatenated to get second number.
* Sum of first and second number is an ascii code encoded by 4 digit sequence.

**Decoding example**:  
On input is given string `24746211151814964359`. String need to be split into `2474` `6211` `1518` `1496` `4359`. From each 4 digits group we extract first and second number also calculating sums:
| 4 digits sequence | first number | second number | sum (first + second) |
| --- | --- | --- | --- |
| 2474 | 27 | 44 | 71 |
| 6211 | 61 | 21 | 82 |
| 1518 | 11 | 58 | 69 |
| 1496 | 19 | 46 | 65 |
| 4359 | 45 | 39 | 84 |

ASCII codes (sums) will give encoded string `GREAT` (71 = `G`, 82 = `R`, ...).

**Input**:  
In each line encoded ascii chars as sequences of 4 digits per sign.

**Output**:  
Decoded ascii string.

## Getting Started
This section describes briefly how to setup environment and build project.

### Prerequisites
C++ compiler with C++17 support as a minimum and CMake 3.8+. Additionally Git tool for downloading Google Test library as it is needed by test subproject.

### Building
Recommended:  
Use Cmake directly or your favorite IDE supporting CMake projects.  

Alternative:  
Use bare compiler for building project binary:
```shell
$ g++ -Wall -std=c++17 -O3 -c *.cpp
$ g++ -Wall -std=c++17 -O3 -o ascii-decode *.o
```

## Built with
| Tool |  Windows 10 | Lubuntu 20.04 |
| --- | --- | --- |
| GCC | 7.3.0 | 9.3.0 |
| Cmake | 3.14 | 3.17 |
| Git | 2.20 | 2.25 |
| QtCreator | 4.12.0 | 4.13.0 |

## Usage
Application expects on std in strings containing encoded ascii chars in form of 4 digit sequences.  
Example input:
```
24746211151814964359
2244
```

Examples of usage:  
1. Pass example file named `testFile.txt` from project repo:
    ```shell
    $ ./ascii-decode < testFile.txt
    GREAT
    0

    ```
2. Use binary directly:
    ```shell
    $ ./ascii-decode
    24746211151814964359
    GREAT
    2244
    0
    ```
3. Pipe input:
    ```shell
    $ cat testFile.txt | ./ascii-decode
    GREAT
    0
    ```
## Testing
Project contains test subproject based on Goggle Test framework. Compile testing subproject and launch tests via IDE or directly from console.  
Example run:
```
$ ./ascii-decode-test.exe
(...)
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from AsciiDecode
[ RUN      ] AsciiDecode.decodePositive
[       OK ] AsciiDecode.decodePositive (0 ms)
[ RUN      ] AsciiDecode.decodeNegative
[       OK ] AsciiDecode.decodeNegative (0 ms)
[----------] 2 tests from AsciiDecode (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 2 tests.
```

## License
Project is distributed under the MIT License. See `LICENSE` for more information.
