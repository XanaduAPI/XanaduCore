# Xanadu.Core

*一个跨平台的C++扩展库，Xanadu系列的核心*


## 说明 / Explain

这是一些C++的扩展类集合，可以使一些C++调用更加方便。


### 提供的功能 / Function
    XString         : Unicode编码的字符串处理类，提供比 std::wstring 便捷的调用
    XByteArray      : 字节数组处理类，提供比 std::vector<char> 便捷的调用
    XBase64         : Base64编解码，来源于QT
    XLibrary        : 根据平台调用相关函数的动态库加载类
    XMutex          : 互斥量
    XShell          : Shell操作，方便调用命令行并返回输出
    XStream         : 日志处理
    XVariant        : 通用类型
    XHash           : 提供 MD5 / CRC32 / SHA1 的便捷调用
    更多...


## 注意 / Note

如果要提交任何更改，请按以下格式编写代码。

set encoding=utf-8

set tabstop=8

set shiftwidth=8



## 注释格式 / Comment format

*与 XanaduAPI/XanaduRuntime 一致*


## 安装 / Installation

### Ubuntu Linux

首先安装所有必需的依赖项和生成工具:
```shell
sudo apt install XanaduRuntime
```

然后克隆实际的项目存储库:
```shell
git clone https://github.com/XanaduAPI/XanaduCore.git
svn checkout https://github.com/XanaduAPI/XanaduCore/trunk
cd XanaduCore
```

现在您可以构建和安装它了:
```shell
cmake .
make
sudo make install
```

## 许可证 / License

This library is licensed under the [GNU Lesser General Public License v2.1](https://www.gnu.org/licenses/lgpl-2.1.en.html),
also included in the repository in the `LICENSE` file.

自述文件更新时间 / README Updated on: 2021-06-08
