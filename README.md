# KDIS

[![version](https://img.shields.io/github/v/release/karljj1/kdis?label=version)](https://github.com/karljj1/kdis/releases/latest)
[![release](https://github.com/karljj1/kdis/actions/workflows/release.yaml/badge.svg)](https://github.com/karljj1/kdis/actions/workflows/release.yaml)
[![codecov](https://codecov.io/gh/karljj1/kdis/branch/master/graph/badge.svg)](https://codecov.io/gh/karljj1/kdis)

Open source implementation of `DIS` (_Distributed Interactive Simulation_) `IEEE 1278.1`

## Contributing

I would love to see your contribution :heart:

See [CONTRIBUTING](./CONTRIBUTING.md) guidelines

## Development

### Requirements

| **Name**       | **Homepage**                                   |    **Required**    | **Notes**                     |
| :------------- | :--------------------------------------------- | :----------------: | :---------------------------- |
| `CXX Compiler` |                                                | :heavy_check_mark: | _`>= C++11`_                  |
| `CMake`        | <https://cmake.org>                            | :heavy_check_mark: | _`>= 3.14`_                   |
| `Clang Format` | <https://clang.llvm.org/docs/ClangFormat.html> |        :x:         |                               |
| `Clang Tidy`   | <https://clang.llvm.org/extra/clang-tidy>      |        :x:         |                               |
| `cmake lang`   | <https://github.com/cheshirekow/cmake_format>  |        :x:         | `pip install cmakelang[YAML]` |
| `Doxygen`      | <https://www.doxygen.nl>                       |        :x:         | Documentation                 |

### Build Options

| **Name**                    | **Description**                                                                                                                                      | **Type** | **Default**                                                                                    | **Notes**                                                                                                                       |
| :-------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------- | :------- | :--------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------ |
| `DIS_VERSION`               | `DIS` version: <br/> <ul><li>`5`<br/>_IEEE 1278.1-1995_</li><li>`6`<br/>_IEEE 1278.1A-1998_</li><li>`7`<br/>_IEEE 1278.1x-2012_</li></ul>            | `STRING` | `7`                                                                                            |                                                                                                                                 |
| `KDIS_USE_ENUM_DESCRIPTORS` | Enumeration descriptors. <br/> Allow `enum` values to be turned into their text labels. <br/> :warning: Increase the memory footprint of the library | `BOOL`   | `ON`                                                                                           |                                                                                                                                 |
| `KDIS_BUILD_INSTALL`        | Build install                                                                                                                                        | `BOOL`   | [PROJECT_IS_TOP_LEVEL](https://cmake.org/cmake/help/latest/variable/PROJECT_IS_TOP_LEVEL.html) |                                                                                                                                 |
| `KDIS_BUILD_DOCS`           | Build documentation                                                                                                                                  | `BOOL`   | [PROJECT_IS_TOP_LEVEL](https://cmake.org/cmake/help/latest/variable/PROJECT_IS_TOP_LEVEL.html) | [`Doxygen`](https://www.doxygen.nl) is required                                                                                 |
| `KDIS_BUILD_EXAMPLES`       | Build examples                                                                                                                                       | `BOOL`   | [PROJECT_IS_TOP_LEVEL](https://cmake.org/cmake/help/latest/variable/PROJECT_IS_TOP_LEVEL.html) |                                                                                                                                 |
| `KDIS_BUILD_TESTS`          | Build tests                                                                                                                                          | `BOOL`   | [PROJECT_IS_TOP_LEVEL](https://cmake.org/cmake/help/latest/variable/PROJECT_IS_TOP_LEVEL.html) |                                                                                                                                 |
| `KDIS_BUILD_TESTS_COVERAGE` | Build tests coverage                                                                                                                                 | `BOOL`   | [PROJECT_IS_TOP_LEVEL](https://cmake.org/cmake/help/latest/variable/PROJECT_IS_TOP_LEVEL.html) | Build option `KDIS_BUILD_TESTS` must be `ON`. <br/> [`LCOV`](https://github.com/linux-test-project/lcov) is required            |
| `BUILD_SHARED_LIBS`         | Build shared library                                                                                                                                 | `BOOL`   | `ON`                                                                                           | See [BUILD_SHARED_LIBS](https://cmake.org/cmake/help/latest/variable/BUILD_SHARED_LIBS.html) documentation for more information |

### Build

1. Generate project

    > [!TIP]
    > Change build options' values as needed

    ```sh
    cmake \
        -S . \
        -B ./build \
        -DCMAKE_BUILD_TYPE:STRING=Release \
        -DDIS_VERSION:STRING=7 \
        -DKDIS_USE_ENUM_DESCRIPTORS:BOOL=ON \
        -DKDIS_BUILD_INSTALL:BOOL=OFF \
        -DKDIS_BUILD_DOCS:BOOL=OFF \
        -DKDIS_BUILD_EXAMPLES:BOOL=OFF \
        -DKDIS_BUILD_TESTS:BOOL=OFF \
        -DKDIS_BUILD_TESTS_COVERAGE:BOOL=OFF \
        -DBUILD_SHARED_LIBS:BOOL=ON
    ```

1. Build project

    > [!NOTE]
    > Change value of `--config` to match value of `CMAKE_BUILD_TYPE`

    ```sh
    cmake \
        --build ./build \
        --config Release
    ```

## Documentation

> [!IMPORTANT]
> `KDIS_BUILD_DOCS:BOOL=ON` required

File `index.html` available under [`build/html`](./build/html) directory

```sh
cmake \
    --build ./build \
    --target KDIS_docs
```

## Examples

> [!IMPORTANT]
> `KDIS_BUILD_EXAMPLES:BOOL=ON` required

More information can be found in [`examples/README.md`](./examples/README.md)

## Tests

> [!IMPORTANT]
> `KDIS_BUILD_TESTS:BOOL=ON` required

> [!NOTE]
> Change value of `--build-config` to match value of `CMAKE_BUILD_TYPE`

More information can be found in [`tests/README.md`](./tests/README.md)

```sh
ctest \
    --verbose \
    --test-dir ./build/tests \
    --build-config Release
```

### Coverage

> [!IMPORTANT]
> `KDIS_BUILD_TESTS_COVERAGE:BOOL=ON` required

File `index.html` available under [`build/kdis_coverage`](./build/kdis_coverage) directory

```sh
cmake \
    --build ./build \
    --config Debug \
    --target KDIS_coverage
```

More information can be found in [`tests/README.md`](./tests/README.md)

## Scripts

More information can be found in [`scripts/README.md`](./scripts/README.md)

## License

This project is licensed under the [BSD 2-Clause](https://opensource.org/license/bsd-2-clause) "Simplified" License \
See [LICENSE](./LICENSE) file for details
