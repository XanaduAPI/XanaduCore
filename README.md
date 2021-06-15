# Xanadu.Core

*A cross platform C++ extension library*


## Explain

This is a collection of C++ extension classes, which can make some C++ calls more convenient.


### Function
    XString         : String processing of Unicode encoding
    XByteArray      : Byte array processing
    XBase64         : Base64 codec
    XLibrary        : Dynamic library loading
    XMutex          : Mutex
    XShell          : Shell operation, easy to call the command line and return output
    XStream         : Log output
    XVariant        : Variant
    XHash           : Provide calculation of MD5 / CRC32 / SHA1
    XException      : Exception handling
    more...


## Note

If you want to commit any changes, write the code in the following format.

set encoding=utf-8

set tabstop=8

set shiftwidth=8



## Comment format

*Consistent with XanaduAPI/XanaduRuntime*


## Installation

### Ubuntu Linux

First install all required dependencies and build tools:
```shell
sudo apt install cmake
sudo apt install XanaduRuntime
```

Then clone the actual project Repository:
```shell
git clone https://github.com/XanaduAPI/XanaduCore.git
svn checkout https://github.com/XanaduAPI/XanaduCore/trunk
cd XanaduCore
```

Now you can build and install it:
```shell
cmake .
make
sudo make install
```

## License

This library is licensed under the [GNU Lesser General Public License v2.1](https://www.gnu.org/licenses/lgpl-2.1.en.html),
also included in the repository in the `LICENSE` file.

README Updated on: 2021-06-15
