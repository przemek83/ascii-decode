[![Build & test](https://github.com/przemek83/ascii-decode/actions/workflows/buld-and-test.yml/badge.svg)](https://github.com/przemek83/ascii-decode/actions/workflows/buld-and-test.yml)
[![CodeQL](https://github.com/przemek83/ascii-decode/actions/workflows/github-code-scanning/codeql/badge.svg)](https://github.com/przemek83/ascii-decode/actions/workflows/github-code-scanning/codeql)
[![codecov](https://codecov.io/gh/przemek83/ascii-decode/graph/badge.svg?token=2EMRTM8G4R)](https://codecov.io/gh/przemek83/ascii-decode)

[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=przemek83_ascii-decode&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=przemek83_ascii-decode)
[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=przemek83_ascii-decode&metric=bugs)](https://sonarcloud.io/summary/new_code?id=przemek83_ascii-decode)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=przemek83_ascii-decode&metric=code_smells)](https://sonarcloud.io/summary/new_code?id=przemek83_ascii-decode)
[![Coverage](https://sonarcloud.io/api/project_badges/measure?project=przemek83_ascii-decode&metric=coverage)](https://sonarcloud.io/summary/new_code?id=przemek83_ascii-decode)
[![Duplicated Lines (%)](https://sonarcloud.io/api/project_badges/measure?project=przemek83_ascii-decode&metric=duplicated_lines_density)](https://sonarcloud.io/summary/new_code?id=przemek83_ascii-decode)

# Table of content
- [About](#about)
- [Problem description](#problem-description)
- [Getting Started](#getting-started)
   * [Prerequisites](#prerequisites)
   * [Building](#building)
   * [Used tools and libs](#used-tools-and-libs)
- [Usage](#usage)
- [Testing](#testing)
- [License](#license)

# About
Simple decoder creating, according to given rules, ascii chars from string of digits.

# Problem description
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

# Getting Started
This section describes briefly how to set up the environment and build the project.

## Prerequisites
C++ compiler with C++17 support as a minimum and CMake 3.14+. Additionally, the Git tool for downloading the Google Test library is needed by the test subproject.

## Building
Clone and use CMake directly or via any IDE supporting it. CMake should:
- configure everything automatically,
- compile and create binaries.

As a result of compilation, binary for simulations and binary for testing should be created.

## Used tools and libs
| Tool |  Windows 10 | Lubuntu 20.04 |
| --- | --- | --- |
| OS version | 10 22H2 | 24.04 |
| GCC | 13.1.0 | 13.2.0 |
| Cmake | 3.30.2 | 3.28.3 |
| Git | 2.46.0 | 2.43.0 |
| GoogleTest | 1.15.2 | 1.15.2 |

# Usage
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
# Testing
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

# License
Project is distributed under the MIT License. See `LICENSE` for more information.

The project uses the following open-source software:
| Name | License | Home | Description |
| --- | --- | --- | --- |
| GoogleTest | BSD-3-Clause | https://github.com/google/googletest | testing framework |