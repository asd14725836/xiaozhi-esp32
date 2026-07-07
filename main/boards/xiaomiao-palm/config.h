// 小喵掌机 (xiaomiao-palm) 板子配置
// 基于 esp32-cgc 修改，适配 160x128 ST7735S + 6键
// 硬件来源：用户提供的小喵掌机规格 (2026-07-07)

#pragma once

#include <driver/gpio.h>

// ============ 音频配置 ============
// 无硬件I2S，使用 NoAudioCodec 静默模式
#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// ============ 显示配置（关键！引脚必须严格匹配） ============
// ST7735S, 160x128, SPI通信, RGB565
// CS  = GPIO5
// DC  = GPIO4
// RST = GPIO19
// BL  = GPIO4 (独立PWM背光控制)

#define DISPLAY_CS_PIN          GPIO_NUM_5
#define DISPLAY_DC_PIN          GPIO_NUM_4
#define DISPLAY_RESET_PIN       GPIO_NUM_19
#define DISPLAY_BACKLIGHT_PIN   GPIO_NUM_4

#define DISPLAY_SCLK_PIN        GPIO_NUM_18
#define DISPLAY_MOSI_PIN        GPIO_NUM_23
#define DISPLAY_SPI_SCLK_HZ     (20 * 1000 * 1000)

// 分辨率由 config.json 的 CONFIG_LCD_ST7735_128X160 控制
// 已在 esp32-cgc 的 config.h 中预定义好参数

// ============ 按键配置（待确认具体GPIO编号） ============
// 掌机有6个物理按键 + 独立RESET
// 已知：BOOT=GPIO0（默认下载模式按键）
// 其他5个按键（方向4键 + A/B功能键 + 菜单键）的GPIO编号待机器到手后确认
//
// 临时占位值（基于esp32-cgc默认）：
#define BOOT_BUTTON_GPIO        GPIO_NUM_0   // 确认键 / 唤醒键
#define ASR_BUTTON_GPIO         GPIO_NUM_13  // 语音键 / 备用

// TODO: 机器到手后根据实际 PCB 走线补充以下按键
// #define KEY_UP_GPIO           TBD
// #define KEY_DOWN_GPIO         TBD
// #define KEY_LEFT_GPIO         TBD
// #define KEY_RIGHT_GPIO        TBD
// #define KEY_A_GPIO            TBD
// #define KEY_B_GPIO            TBD
// #define KEY_MENU_GPIO         TBD

// ============ MPU6050（六轴） ============
// 通过 I2C 连接，具体引脚待机器到手后测
// #define MPU6050_SDA_GPIO      TBD
// #define MPU6050_SCL_GPIO      TBD

// ============ 无I2S配置 ============
#define AUDIO_I2S_METHOD_SIMPLEX

// 无 I2S 引脚，全部注释掉
// #define AUDIO_I2S_MIC_GPIO_WS
// #define AUDIO_I2S_MIC_GPIO_SCK
// #define AUDIO_I2S_MIC_GPIO_DIN
// #define AUDIO_I2S_SPK_GPIO_DOUT
// #define AUDIO_I2S_SPK_GPIO_BCLK
// #define AUDIO_I2S_SPK_GPIO_LRCK

// ============ MCP 测试设备 ============
// 暂不启用
// #define LAMP_GPIO             GPIO_NUM_12