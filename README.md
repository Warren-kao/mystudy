# 嵌入式学习仓库

[![](https://img.shields.io/badge/%E4%B8%BB%E9%A1%B5-Warren--kao/mystudy-orange)](https://github.com/Warren-kao/mystudy)
[![](https://img.shields.io/badge/语言-C%2C%20C%2B%2B-blue)](https://github.com/Warren-kao/mystudy)
[![](https://img.shields.io/badge/平台-C51%2C%20STM32%2C%20FreeRTOS-brightgreen)](https://github.com/Warren-kao/mystudy)

本仓库是个人学习嵌入式过程中的代码记录，涵盖从基础语法到单片机、实时操作系统等多个层次。

## 目录

- [背景](#背景)
- [安装](#安装)
- [用法](#用法)
- [目录结构](#目录结构)
- [相关项目](#相关项目)
- [主要项目负责人](#主要项目负责人)
- [参与贡献方式](#参与贡献方式)
    - [贡献人员](#贡献人员)
- [开源协议](#开源协议)

## 背景

嵌入式学习路线通常包括：C 语言基础 → 8位单片机（如 C51）→ 32位 ARM（如 STM32）→ 实时操作系统（如 FreeRTOS）。为了系统地记录学习过程中的代码和笔记，本仓库按模块组织所有练习例程，方便日后查阅和复用。

主要内容包括：
- **C 语言基础**：指针、结构体、内存管理、数据结构和算法练习
- **C51 单片机**：基于 Keil C51 的 LED、数码管、按键、中断、定时器、串口通信等
- **STM32 开发**：基于标准库 / HAL 库的 GPIO、USART、I2C、SPI、ADC、DMA、定时器、外部中断等
- **FreeRTOS**：在 STM32 上移植 FreeRTOS，实现任务创建、消息队列、信号量、互斥量、软件定时器等
- 其他：常用传感器（DHT11、DS18B20、OLED、MPU6050 等）驱动封装

## 安装

### 获取代码
```bash
git clone https://github.com/Warren-kao/mystudy.git
cd mystudy
```

开发环境要求

- C 语言基础：任何支持 C99 的编译器（GCC、Clang、MSVC），推荐使用 Visual Studio 2022
- C51 开发：Keil C51（uVision） + STC-ISP 烧录工具（或其他 C51 烧录软件）
- STM32 开发：Keil MDK / STM32CubeIDE + ST-Link / J-Link 调试器
- FreeRTOS：在 STM32 工程基础上包含 FreeRTOS 源码包（仓库已提供）
- 通用工具：Make、Git、串口调试助手（XCOM、Minicom、PuTTY）

各子目录下通常包含独立的 README 或 工程文件，请按需打开。

用法

1. C 语言基础练习
      进入 1.C语言/ 目录，使用 gcc 编译运行：
      gcc main.c -o example && ./example
2. C51 单片机例程
      进入 2.C51/ 对应子目录，用 Keil C51 打开 .uvproj 工程，编译后下载到 C51 开发板（如 STC89C52）。
3. STM32 裸机例程
      进入 3.STM32/ 对应例程目录，使用 Keil MDK 打开 .uvprojx 工程，编译并下载至目标板。
4. FreeRTOS 例程
      进入 4.FreeRTOS/ 目录，基于 STM32 工程，通过串口打印任务运行日志，观察任务调度。

详细使用方法请参考各子文件夹内的说明文档。

目录结构

```
mystudy/
├── 1.C语言/               # C 语言基础语法、指针、内存管理、算法练习
├── 2.C51/                 # C51 单片机外设例程（LED、数码管、按键、中断、串口等）
├── 3.STM32/               # STM32 裸机例程（标准库/HAL库）
├── 4.FreeRTOS/            # FreeRTOS 移植与应用（任务、队列、信号量等）
├── Sensors/                # 传感器驱动（DHT11、DS18B20、OLED、MPU6050等）
├── Tools/                  # 辅助脚本、链接脚本、配置文件
└── LICENSE
```

相关项目

## 相关项目

- [Keil MDK-Arm](https://www.keil.com/support/man/docs/armasm/) - 官方 Keil MDK 文档及例程参考
- [STM32Cube MCU Packages](https://github.com/STMicroelectronics) - ST 官方 STM32 HAL 库及 LL 库（GitHub 组织）
- [FreeRTOS-Kernel](https://github.com/FreeRTOS/FreeRTOS-Kernel) - FreeRTOS 官方内核源码
- [STC-ISP](http://www.stcmcu.com/) - STC 单片机官方烧录工具及手册

## 主要项目负责人

[@Warren-kao](https://github.com/Warren-kao)

## 参与贡献方式

本项目为个人学习记录，暂不接受直接贡献。如果你发现了错误或有改进建议，欢迎提交 Issue 或通过邮件联系。

### 贡献人员

[@Warren-kao](https://github.com/Warren-kao) – 主要代码编写与维护

## 开源协议

[MIT](LICENSE) © Warren-kao
