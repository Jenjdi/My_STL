# 代码修复与验证说明

## 本次修改

修复优先队列比较器、vector 深拷贝和迭代器移动；补全哈希包装层与桶实现。字符串使用标准存储管理并保留示例操作接口，resize 的填充值为 char。移除未使用的 Windows 依赖，修正 C 队列声明及返回类型。哈希包装类沿用 My_Map/My_Set 命名空间。

修改处使用中文注释解释原因；新增及重写的变量使用能够表达业务含义的名称，保留未涉及的公开接口和题目约定。部分教学代码仍不是生产级组件。

## 运行检查

在本仓库根目录执行，要求 GCC/G++（C11、C++17）、Python 3。Protobuf、VideoWebSite 和部分 Linux 示例还需要 Protobuf 3.21、JsonCpp、MariaDB 客户端开发库。云环境可先执行 `source /workspace/.setup/env.sh`，再设置：

```bash
export CPPFLAGS=-I/workspace/.setup/sysroot/usr/include
export LDFLAGS=-L/workspace/.setup/sysroot/usr/lib/x86_64-linux-gnu
python3 tests/check_syntax.py
```

通用系统安装路径可以不设置 CPPFLAGS/LDFLAGS。语法检查覆盖每个源文件及独立头文件，不等同于算法正确性验证。

回归测试：

```bash
set -e
for test in regression containers; do
  g++ -std=c++17 -fsanitize=address,undefined -g tests/$test.cpp -o /tmp/stl-$test
  /tmp/stl-$test || exit 1
done
gcc -std=c11 -fsanitize=address,undefined tests/queue.c -o /tmp/stl-queue
/tmp/stl-queue
```

