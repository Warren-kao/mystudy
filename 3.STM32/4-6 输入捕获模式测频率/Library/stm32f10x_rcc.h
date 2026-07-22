/**
  ******************************************************************************
  * @file    stm32f10x_rcc.h
  * @author  MCD应用团队
  * @version V3.5.0
  * @date    2011年3月11日
  * @brief   本文件包含RCC固件库的所有函数原型。
  ******************************************************************************
  * @attention
  *
  * 本固件仅作指导用途，旨在为客户提供与其产品相关的编码信息，以节省客户时间。
  * 因此，对于因本固件内容和/或客户使用本文件所含编码信息而导致的任何直接、间接或后果性损害索赔，
  * 意法半导体不承担任何责任。
  *
  * <h2><center>&copy; 2011年意法半导体版权所有</center></h2>
  ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F10x_RCC_H
#define __STM32F10x_RCC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @addtogroup RCC
  * @{
  */

/** @defgroup RCC_Exported_Types
  * @{
  */

typedef struct
{
  uint32_t SYSCLK_Frequency;  /*!< returns SYSCLK clock frequency expressed in Hz */
  uint32_t HCLK_Frequency;    /*!< returns HCLK clock frequency expressed in Hz */
  uint32_t PCLK1_Frequency;   /*!< returns PCLK1 clock frequency expressed in Hz */
  uint32_t PCLK2_Frequency;   /*!< returns PCLK2 clock frequency expressed in Hz */
  uint32_t ADCCLK_Frequency;  /*!< returns ADCCLK clock frequency expressed in Hz */
}RCC_ClocksTypeDef;

/**
  * @}
  */

/** @defgroup RCC_Exported_Constants
  * @{
  */

/** @defgroup HSE_configuration 
  * @{
  */

#define RCC_HSE_OFF                      ((uint32_t)0x00000000)
#define RCC_HSE_ON                       ((uint32_t)0x00010000)
#define RCC_HSE_Bypass                   ((uint32_t)0x00040000)
#define IS_RCC_HSE(HSE) (((HSE) == RCC_HSE_OFF) || ((HSE) == RCC_HSE_ON) || \
                         ((HSE) == RCC_HSE_Bypass))

/**
  * @}
  */ 

/** @defgroup PLL_entry_clock_source 
  * @{
  */

#define RCC_PLLSource_HSI_Div2           ((uint32_t)0x00000000)

#if !defined (STM32F10X_LD_VL) && !defined (STM32F10X_MD_VL) && !defined (STM32F10X_HD_VL) && !defined (STM32F10X_CL)
 #define RCC_PLLSource_HSE_Div1           ((uint32_t)0x00010000)
 #define RCC_PLLSource_HSE_Div2           ((uint32_t)0x00030000)
 #define IS_RCC_PLL_SOURCE(SOURCE) (((SOURCE) == RCC_PLLSource_HSI_Div2) || \
                                   ((SOURCE) == RCC_PLLSource_HSE_Div1) || \
                                   ((SOURCE) == RCC_PLLSource_HSE_Div2))
#else
 #define RCC_PLLSource_PREDIV1            ((uint32_t)0x00010000)
 #define IS_RCC_PLL_SOURCE(SOURCE) (((SOURCE) == RCC_PLLSource_HSI_Div2) || \
                                   ((SOURCE) == RCC_PLLSource_PREDIV1))
#endif /* STM32F10X_CL */ 

/**
  * @}
  */ 

/** @defgroup PLL_multiplication_factor 
  * @{
  */
#ifndef STM32F10X_CL
 #define RCC_PLLMul_2                    ((uint32_t)0x00000000)
 #define RCC_PLLMul_3                    ((uint32_t)0x00040000)
 #define RCC_PLLMul_4                    ((uint32_t)0x00080000)
 #define RCC_PLLMul_5                    ((uint32_t)0x000C0000)
 #define RCC_PLLMul_6                    ((uint32_t)0x00100000)
 #define RCC_PLLMul_7                    ((uint32_t)0x00140000)
 #define RCC_PLLMul_8                    ((uint32_t)0x00180000)
 #define RCC_PLLMul_9                    ((uint32_t)0x001C0000)
 #define RCC_PLLMul_10                   ((uint32_t)0x00200000)
 #define RCC_PLLMul_11                   ((uint32_t)0x00240000)
 #define RCC_PLLMul_12                   ((uint32_t)0x00280000)
 #define RCC_PLLMul_13                   ((uint32_t)0x002C0000)
 #define RCC_PLLMul_14                   ((uint32_t)0x00300000)
 #define RCC_PLLMul_15                   ((uint32_t)0x00340000)
 #define RCC_PLLMul_16                   ((uint32_t)0x00380000)
 #define IS_RCC_PLL_MUL(MUL) (((MUL) == RCC_PLLMul_2) || ((MUL) == RCC_PLLMul_3)   || \
                              ((MUL) == RCC_PLLMul_4) || ((MUL) == RCC_PLLMul_5)   || \
                              ((MUL) == RCC_PLLMul_6) || ((MUL) == RCC_PLLMul_7)   || \
                              ((MUL) == RCC_PLLMul_8) || ((MUL) == RCC_PLLMul_9)   || \
                              ((MUL) == RCC_PLLMul_10) || ((MUL) == RCC_PLLMul_11) || \
                              ((MUL) == RCC_PLLMul_12) || ((MUL) == RCC_PLLMul_13) || \
                              ((MUL) == RCC_PLLMul_14) || ((MUL) == RCC_PLLMul_15) || \
                              ((MUL) == RCC_PLLMul_16))

#else
 #define RCC_PLLMul_4                    ((uint32_t)0x00080000)
 #define RCC_PLLMul_5                    ((uint32_t)0x000C0000)
 #define RCC_PLLMul_6                    ((uint32_t)0x00100000)
 #define RCC_PLLMul_7                    ((uint32_t)0x00140000)
 #define RCC_PLLMul_8                    ((uint32_t)0x00180000)
 #define RCC_PLLMul_9                    ((uint32_t)0x001C0000)
 #define RCC_PLLMul_6_5                  ((uint32_t)0x00340000)

 #define IS_RCC_PLL_MUL(MUL) (((MUL) == RCC_PLLMul_4) || ((MUL) == RCC_PLLMul_5) || \
                              ((MUL) == RCC_PLLMul_6) || ((MUL) == RCC_PLLMul_7) || \
                              ((MUL) == RCC_PLLMul_8) || ((MUL) == RCC_PLLMul_9) || \
                              ((MUL) == RCC_PLLMul_6_5))
#endif /* STM32F10X_CL */                              
/**
  * @}
  */

/** @defgroup PREDIV1_division_factor
  * @{
  */
#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL) || defined (STM32F10X_CL)
 #define  RCC_PREDIV1_Div1               ((uint32_t)0x00000000)
 #define  RCC_PREDIV1_Div2               ((uint32_t)0x00000001)
 #define  RCC_PREDIV1_Div3               ((uint32_t)0x00000002)
 #define  RCC_PREDIV1_Div4               ((uint32_t)0x00000003)
 #define  RCC_PREDIV1_Div5               ((uint32_t)0x00000004)
 #define  RCC_PREDIV1_Div6               ((uint32_t)0x00000005)
 #define  RCC_PREDIV1_Div7               ((uint32_t)0x00000006)
 #define  RCC_PREDIV1_Div8               ((uint32_t)0x00000007)
 #define  RCC_PREDIV1_Div9               ((uint32_t)0x00000008)
 #define  RCC_PREDIV1_Div10              ((uint32_t)0x00000009)
 #define  RCC_PREDIV1_Div11              ((uint32_t)0x0000000A)
 #define  RCC_PREDIV1_Div12              ((uint32_t)0x0000000B)
 #define  RCC_PREDIV1_Div13              ((uint32_t)0x0000000C)
 #define  RCC_PREDIV1_Div14              ((uint32_t)0x0000000D)
 #define  RCC_PREDIV1_Div15              ((uint32_t)0x0000000E)
 #define  RCC_PREDIV1_Div16              ((uint32_t)0x0000000F)

 #define IS_RCC_PREDIV1(PREDIV1) (((PREDIV1) == RCC_PREDIV1_Div1) || ((PREDIV1) == RCC_PREDIV1_Div2) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div3) || ((PREDIV1) == RCC_PREDIV1_Div4) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div5) || ((PREDIV1) == RCC_PREDIV1_Div6) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div7) || ((PREDIV1) == RCC_PREDIV1_Div8) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div9) || ((PREDIV1) == RCC_PREDIV1_Div10) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div11) || ((PREDIV1) == RCC_PREDIV1_Div12) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div13) || ((PREDIV1) == RCC_PREDIV1_Div14) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div15) || ((PREDIV1) == RCC_PREDIV1_Div16))
#endif
/**
  * @}
  */


/** @defgroup PREDIV1_clock_source
  * @{
  */
#ifdef STM32F10X_CL
/* PREDIV1 clock source (for STM32 connectivity line devices) */
 #define  RCC_PREDIV1_Source_HSE         ((uint32_t)0x00000000) 
 #define  RCC_PREDIV1_Source_PLL2        ((uint32_t)0x00010000) 

 #define IS_RCC_PREDIV1_SOURCE(SOURCE) (((SOURCE) == RCC_PREDIV1_Source_HSE) || \
                                        ((SOURCE) == RCC_PREDIV1_Source_PLL2)) 
#elif defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
/* PREDIV1 clock source (for STM32 Value line devices) */
 #define  RCC_PREDIV1_Source_HSE         ((uint32_t)0x00000000) 

 #define IS_RCC_PREDIV1_SOURCE(SOURCE) (((SOURCE) == RCC_PREDIV1_Source_HSE)) 
#endif
/**
  * @}
  */

#ifdef STM32F10X_CL
/** @defgroup PREDIV2_division_factor
  * @{
  */
  
 #define  RCC_PREDIV2_Div1               ((uint32_t)0x00000000)
 #define  RCC_PREDIV2_Div2               ((uint32_t)0x00000010)
 #define  RCC_PREDIV2_Div3               ((uint32_t)0x00000020)
 #define  RCC_PREDIV2_Div4               ((uint32_t)0x00000030)
 #define  RCC_PREDIV2_Div5               ((uint32_t)0x00000040)
 #define  RCC_PREDIV2_Div6               ((uint32_t)0x00000050)
 #define  RCC_PREDIV2_Div7               ((uint32_t)0x00000060)
 #define  RCC_PREDIV2_Div8               ((uint32_t)0x00000070)
 #define  RCC_PREDIV2_Div9               ((uint32_t)0x00000080)
 #define  RCC_PREDIV2_Div10              ((uint32_t)0x00000090)
 #define  RCC_PREDIV2_Div11              ((uint32_t)0x000000A0)
 #define  RCC_PREDIV2_Div12              ((uint32_t)0x000000B0)
 #define  RCC_PREDIV2_Div13              ((uint32_t)0x000000C0)
 #define  RCC_PREDIV2_Div14              ((uint32_t)0x000000D0)
 #define  RCC_PREDIV2_Div15              ((uint32_t)0x000000E0)
 #define  RCC_PREDIV2_Div16              ((uint32_t)0x000000F0)

 #define IS_RCC_PREDIV2(PREDIV2) (((PREDIV2) == RCC_PREDIV2_Div1) || ((PREDIV2) == RCC_PREDIV2_Div2) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div3) || ((PREDIV2) == RCC_PREDIV2_Div4) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div5) || ((PREDIV2) == RCC_PREDIV2_Div6) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div7) || ((PREDIV2) == RCC_PREDIV2_Div8) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div9) || ((PREDIV2) == RCC_PREDIV2_Div10) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div11) || ((PREDIV2) == RCC_PREDIV2_Div12) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div13) || ((PREDIV2) == RCC_PREDIV2_Div14) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div15) || ((PREDIV2) == RCC_PREDIV2_Div16))
/**
  * @}
  */


/** @defgroup PLL2_multiplication_factor
  * @{
  */
  
 #define  RCC_PLL2Mul_8                  ((uint32_t)0x00000600)
 #define  RCC_PLL2Mul_9                  ((uint32_t)0x00000700)
 #define  RCC_PLL2Mul_10                 ((uint32_t)0x00000800)
 #define  RCC_PLL2Mul_11                 ((uint32_t)0x00000900)
 #define  RCC_PLL2Mul_12                 ((uint32_t)0x00000A00)
 #define  RCC_PLL2Mul_13                 ((uint32_t)0x00000B00)
 #define  RCC_PLL2Mul_14                 ((uint32_t)0x00000C00)
 #define  RCC_PLL2Mul_16                 ((uint32_t)0x00000E00)
 #define  RCC_PLL2Mul_20                 ((uint32_t)0x00000F00)

 #define IS_RCC_PLL2_MUL(MUL) (((MUL) == RCC_PLL2Mul_8) || ((MUL) == RCC_PLL2Mul_9)  || \
                               ((MUL) == RCC_PLL2Mul_10) || ((MUL) == RCC_PLL2Mul_11) || \
                               ((MUL) == RCC_PLL2Mul_12) || ((MUL) == RCC_PLL2Mul_13) || \
                               ((MUL) == RCC_PLL2Mul_14) || ((MUL) == RCC_PLL2Mul_16) || \
                               ((MUL) == RCC_PLL2Mul_20))
/**
  * @}
  */


/** @defgroup PLL3_multiplication_factor
  * @{
  */

 #define  RCC_PLL3Mul_8                  ((uint32_t)0x00006000)
 #define  RCC_PLL3Mul_9                  ((uint32_t)0x00007000)
 #define  RCC_PLL3Mul_10                 ((uint32_t)0x00008000)
 #define  RCC_PLL3Mul_11                 ((uint32_t)0x00009000)
 #define  RCC_PLL3Mul_12                 ((uint32_t)0x0000A000)
 #define  RCC_PLL3Mul_13                 ((uint32_t)0x0000B000)
 #define  RCC_PLL3Mul_14                 ((uint32_t)0x0000C000)
 #define  RCC_PLL3Mul_16                 ((uint32_t)0x0000E000)
 #define  RCC_PLL3Mul_20                 ((uint32_t)0x0000F000)

 #define IS_RCC_PLL3_MUL(MUL) (((MUL) == RCC_PLL3Mul_8) || ((MUL) == RCC_PLL3Mul_9)  || \
                               ((MUL) == RCC_PLL3Mul_10) || ((MUL) == RCC_PLL3Mul_11) || \
                               ((MUL) == RCC_PLL3Mul_12) || ((MUL) == RCC_PLL3Mul_13) || \
                               ((MUL) == RCC_PLL3Mul_14) || ((MUL) == RCC_PLL3Mul_16) || \
                               ((MUL) == RCC_PLL3Mul_20))
/**
  * @}
  */

#endif /* STM32F10X_CL */


/** @defgroup System_clock_source 
  * @{
  */

#define RCC_SYSCLKSource_HSI             ((uint32_t)0x00000000)
#define RCC_SYSCLKSource_HSE             ((uint32_t)0x00000001)
#define RCC_SYSCLKSource_PLLCLK          ((uint32_t)0x00000002)
#define IS_RCC_SYSCLK_SOURCE(SOURCE) (((SOURCE) == RCC_SYSCLKSource_HSI) || \
                                      ((SOURCE) == RCC_SYSCLKSource_HSE) || \
                                      ((SOURCE) == RCC_SYSCLKSource_PLLCLK))
/**
  * @}
  */

/** @defgroup AHB_clock_source 
  * @{
  */

#define RCC_SYSCLK_Div1                  ((uint32_t)0x00000000)
#define RCC_SYSCLK_Div2                  ((uint32_t)0x00000080)
#define RCC_SYSCLK_Div4                  ((uint32_t)0x00000090)
#define RCC_SYSCLK_Div8                  ((uint32_t)0x000000A0)
#define RCC_SYSCLK_Div16                 ((uint32_t)0x000000B0)
#define RCC_SYSCLK_Div64                 ((uint32_t)0x000000C0)
#define RCC_SYSCLK_Div128                ((uint32_t)0x000000D0)
#define RCC_SYSCLK_Div256                ((uint32_t)0x000000E0)
#define RCC_SYSCLK_Div512                ((uint32_t)0x000000F0)
#define IS_RCC_HCLK(HCLK) (((HCLK) == RCC_SYSCLK_Div1) || ((HCLK) == RCC_SYSCLK_Div2) || \
                           ((HCLK) == RCC_SYSCLK_Div4) || ((HCLK) == RCC_SYSCLK_Div8) || \
                           ((HCLK) == RCC_SYSCLK_Div16) || ((HCLK) == RCC_SYSCLK_Div64) || \
                           ((HCLK) == RCC_SYSCLK_Div128) || ((HCLK) == RCC_SYSCLK_Div256) || \
                           ((HCLK) == RCC_SYSCLK_Div512))
/**
  * @}
  */ 

/** @defgroup APB1_APB2_clock_source 
  * @{
  */

#define RCC_HCLK_Div1                    ((uint32_t)0x00000000)
#define RCC_HCLK_Div2                    ((uint32_t)0x00000400)
#define RCC_HCLK_Div4                    ((uint32_t)0x00000500)
#define RCC_HCLK_Div8                    ((uint32_t)0x00000600)
#define RCC_HCLK_Div16                   ((uint32_t)0x00000700)
#define IS_RCC_PCLK(PCLK) (((PCLK) == RCC_HCLK_Div1) || ((PCLK) == RCC_HCLK_Div2) || \
                           ((PCLK) == RCC_HCLK_Div4) || ((PCLK) == RCC_HCLK_Div8) || \
                           ((PCLK) == RCC_HCLK_Div16))
/**
  * @}
  */

/** @defgroup RCC_Interrupt_source 
  * @{
  */

#define RCC_IT_LSIRDY                    ((uint8_t)0x01)
#define RCC_IT_LSERDY                    ((uint8_t)0x02)
#define RCC_IT_HSIRDY                    ((uint8_t)0x04)
#define RCC_IT_HSERDY                    ((uint8_t)0x08)
#define RCC_IT_PLLRDY                    ((uint8_t)0x10)
#define RCC_IT_CSS                       ((uint8_t)0x80)

#ifndef STM32F10X_CL
 #define IS_RCC_IT(IT) ((((IT) & (uint8_t)0xE0) == 0x00) && ((IT) != 0x00))
 #define IS_RCC_GET_IT(IT) (((IT) == RCC_IT_LSIRDY) || ((IT) == RCC_IT_LSERDY) || \
                            ((IT) == RCC_IT_HSIRDY) || ((IT) == RCC_IT_HSERDY) || \
                            ((IT) == RCC_IT_PLLRDY) || ((IT) == RCC_IT_CSS))
 #define IS_RCC_CLEAR_IT(IT) ((((IT) & (uint8_t)0x60) == 0x00) && ((IT) != 0x00))
#else
 #define RCC_IT_PLL2RDY                  ((uint8_t)0x20)
 #define RCC_IT_PLL3RDY                  ((uint8_t)0x40)
 #define IS_RCC_IT(IT) ((((IT) & (uint8_t)0x80) == 0x00) && ((IT) != 0x00))
 #define IS_RCC_GET_IT(IT) (((IT) == RCC_IT_LSIRDY) || ((IT) == RCC_IT_LSERDY) || \
                            ((IT) == RCC_IT_HSIRDY) || ((IT) == RCC_IT_HSERDY) || \
                            ((IT) == RCC_IT_PLLRDY) || ((IT) == RCC_IT_CSS) || \
                            ((IT) == RCC_IT_PLL2RDY) || ((IT) == RCC_IT_PLL3RDY))
 #define IS_RCC_CLEAR_IT(IT) ((IT) != 0x00)
#endif /* STM32F10X_CL */ 


/**
  * @}
  */

#ifndef STM32F10X_CL
/** @defgroup USB_Device_clock_source 
  * @{
  */

 #define RCC_USBCLKSource_PLLCLK_1Div5   ((uint8_t)0x00)
 #define RCC_USBCLKSource_PLLCLK_Div1    ((uint8_t)0x01)

 #define IS_RCC_USBCLK_SOURCE(SOURCE) (((SOURCE) == RCC_USBCLKSource_PLLCLK_1Div5) || \
                                      ((SOURCE) == RCC_USBCLKSource_PLLCLK_Div1))
/**
  * @}
  */
#else
/** @defgroup USB_OTG_FS_clock_source 
  * @{
  */
 #define RCC_OTGFSCLKSource_PLLVCO_Div3    ((uint8_t)0x00)
 #define RCC_OTGFSCLKSource_PLLVCO_Div2    ((uint8_t)0x01)

 #define IS_RCC_OTGFSCLK_SOURCE(SOURCE) (((SOURCE) == RCC_OTGFSCLKSource_PLLVCO_Div3) || \
                                         ((SOURCE) == RCC_OTGFSCLKSource_PLLVCO_Div2))
/**
  * @}
  */
#endif /* STM32F10X_CL */ 


#ifdef STM32F10X_CL
/** @defgroup I2S2_clock_source 
  * @{
  */
 #define RCC_I2S2CLKSource_SYSCLK        ((uint8_t)0x00)
 #define RCC_I2S2CLKSource_PLL3_VCO      ((uint8_t)0x01)

 #define IS_RCC_I2S2CLK_SOURCE(SOURCE) (((SOURCE) == RCC_I2S2CLKSource_SYSCLK) || \
                                        ((SOURCE) == RCC_I2S2CLKSource_PLL3_VCO))
/**
  * @}
  */

/** @defgroup I2S3_clock_source 
  * @{
  */
 #define RCC_I2S3CLKSource_SYSCLK        ((uint8_t)0x00)
 #define RCC_I2S3CLKSource_PLL3_VCO      ((uint8_t)0x01)

 #define IS_RCC_I2S3CLK_SOURCE(SOURCE) (((SOURCE) == RCC_I2S3CLKSource_SYSCLK) || \
                                        ((SOURCE) == RCC_I2S3CLKSource_PLL3_VCO))    
/**
  * @}
  */
#endif /* STM32F10X_CL */  
  

/** @defgroup ADC_clock_source 
  * @{
  */

#define RCC_PCLK2_Div2                   ((uint32_t)0x00000000)
#define RCC_PCLK2_Div4                   ((uint32_t)0x00004000)
#define RCC_PCLK2_Div6                   ((uint32_t)0x00008000)
#define RCC_PCLK2_Div8                   ((uint32_t)0x0000C000)
#define IS_RCC_ADCCLK(ADCCLK) (((ADCCLK) == RCC_PCLK2_Div2) || ((ADCCLK) == RCC_PCLK2_Div4) || \
                               ((ADCCLK) == RCC_PCLK2_Div6) || ((ADCCLK) == RCC_PCLK2_Div8))
/**
  * @}
  */

/** @defgroup LSE_configuration 
  * @{
  */

#define RCC_LSE_OFF                      ((uint8_t)0x00)
#define RCC_LSE_ON                       ((uint8_t)0x01)
#define RCC_LSE_Bypass                   ((uint8_t)0x04)
#define IS_RCC_LSE(LSE) (((LSE) == RCC_LSE_OFF) || ((LSE) == RCC_LSE_ON) || \
                         ((LSE) == RCC_LSE_Bypass))
/**
  * @}
  */

/** @defgroup RTC_clock_source 
  * @{
  */

#define RCC_RTCCLKSource_LSE             ((uint32_t)0x00000100)
#define RCC_RTCCLKSource_LSI             ((uint32_t)0x00000200)
#define RCC_RTCCLKSource_HSE_Div128      ((uint32_t)0x00000300)
#define IS_RCC_RTCCLK_SOURCE(SOURCE) (((SOURCE) == RCC_RTCCLKSource_LSE) || \
                                      ((SOURCE) == RCC_RTCCLKSource_LSI) || \
                                      ((SOURCE) == RCC_RTCCLKSource_HSE_Div128))
/**
  * @}
  */

/** @defgroup AHB_peripheral 
  * @{
  */

#define RCC_AHBPeriph_DMA1               ((uint32_t)0x00000001)
#define RCC_AHBPeriph_DMA2               ((uint32_t)0x00000002)
#define RCC_AHBPeriph_SRAM               ((uint32_t)0x00000004)
#define RCC_AHBPeriph_FLITF              ((uint32_t)0x00000010)
#define RCC_AHBPeriph_CRC                ((uint32_t)0x00000040)

#ifndef STM32F10X_CL
 #define RCC_AHBPeriph_FSMC              ((uint32_t)0x00000100)
 #define RCC_AHBPeriph_SDIO              ((uint32_t)0x00000400)
 #define IS_RCC_AHB_PERIPH(PERIPH) ((((PERIPH) & 0xFFFFFAA8) == 0x00) && ((PERIPH) != 0x00))
#else
 #define RCC_AHBPeriph_OTG_FS            ((uint32_t)0x00001000)
 #define RCC_AHBPeriph_ETH_MAC           ((uint32_t)0x00004000)
 #define RCC_AHBPeriph_ETH_MAC_Tx        ((uint32_t)0x00008000)
 #define RCC_AHBPeriph_ETH_MAC_Rx        ((uint32_t)0x00010000)

 #define IS_RCC_AHB_PERIPH(PERIPH) ((((PERIPH) & 0xFFFE2FA8) == 0x00) && ((PERIPH) != 0x00))
 #define IS_RCC_AHB_PERIPH_RESET(PERIPH) ((((PERIPH) & 0xFFFFAFFF) == 0x00) && ((PERIPH) != 0x00))
#endif /* STM32F10X_CL */
/**
  * @}
  */

/** @defgroup APB2_peripheral 
  * @{
  */

#define RCC_APB2Periph_AFIO              ((uint32_t)0x00000001)
#define RCC_APB2Periph_GPIOA             ((uint32_t)0x00000004)
#define RCC_APB2Periph_GPIOB             ((uint32_t)0x00000008)
#define RCC_APB2Periph_GPIOC             ((uint32_t)0x00000010)
#define RCC_APB2Periph_GPIOD             ((uint32_t)0x00000020)
#define RCC_APB2Periph_GPIOE             ((uint32_t)0x00000040)
#define RCC_APB2Periph_GPIOF             ((uint32_t)0x00000080)
#define RCC_APB2Periph_GPIOG             ((uint32_t)0x00000100)
#define RCC_APB2Periph_ADC1              ((uint32_t)0x00000200)
#define RCC_APB2Periph_ADC2              ((uint32_t)0x00000400)
#define RCC_APB2Periph_TIM1              ((uint32_t)0x00000800)
#define RCC_APB2Periph_SPI1              ((uint32_t)0x00001000)
#define RCC_APB2Periph_TIM8              ((uint32_t)0x00002000)
#define RCC_APB2Periph_USART1            ((uint32_t)0x00004000)
#define RCC_APB2Periph_ADC3              ((uint32_t)0x00008000)
#define RCC_APB2Periph_TIM15             ((uint32_t)0x00010000)
#define RCC_APB2Periph_TIM16             ((uint32_t)0x00020000)
#define RCC_APB2Periph_TIM17             ((uint32_t)0x00040000)
#define RCC_APB2Periph_TIM9              ((uint32_t)0x00080000)
#define RCC_APB2Periph_TIM10             ((uint32_t)0x00100000)
#define RCC_APB2Periph_TIM11             ((uint32_t)0x00200000)

#define IS_RCC_APB2_PERIPH(PERIPH) ((((PERIPH) & 0xFFC00002) == 0x00) && ((PERIPH) != 0x00))
/**
  * @}
  */ 

/** @defgroup APB1_peripheral 
  * @{
  */

#define RCC_APB1Periph_TIM2              ((uint32_t)0x00000001)
#define RCC_APB1Periph_TIM3              ((uint32_t)0x00000002)
#define RCC_APB1Periph_TIM4              ((uint32_t)0x00000004)
#define RCC_APB1Periph_TIM5              ((uint32_t)0x00000008)
#define RCC_APB1Periph_TIM6              ((uint32_t)0x00000010)
#define RCC_APB1Periph_TIM7              ((uint32_t)0x00000020)
#define RCC_APB1Periph_TIM12             ((uint32_t)0x00000040)
#define RCC_APB1Periph_TIM13             ((uint32_t)0x00000080)
#define RCC_APB1Periph_TIM14             ((uint32_t)0x00000100)
#define RCC_APB1Periph_WWDG              ((uint32_t)0x00000800)
#define RCC_APB1Periph_SPI2              ((uint32_t)0x00004000)
#define RCC_APB1Periph_SPI3              ((uint32_t)0x00008000)
#define RCC_APB1Periph_USART2            ((uint32_t)0x00020000)
#define RCC_APB1Periph_USART3            ((uint32_t)0x00040000)
#define RCC_APB1Periph_UART4             ((uint32_t)0x00080000)
#define RCC_APB1Periph_UART5             ((uint32_t)0x00100000)
#define RCC_APB1Periph_I2C1              ((uint32_t)0x00200000)
#define RCC_APB1Periph_I2C2              ((uint32_t)0x00400000)
#define RCC_APB1Periph_USB               ((uint32_t)0x00800000)
#define RCC_APB1Periph_CAN1              ((uint32_t)0x02000000)
#define RCC_APB1Periph_CAN2              ((uint32_t)0x04000000)
#define RCC_APB1Periph_BKP               ((uint32_t)0x08000000)
#define RCC_APB1Periph_PWR               ((uint32_t)0x10000000)
#define RCC_APB1Periph_DAC               ((uint32_t)0x20000000)
#define RCC_APB1Periph_CEC               ((uint32_t)0x40000000)
 
#define IS_RCC_APB1_PERIPH(PERIPH) ((((PERIPH) & 0x81013600) == 0x00) && ((PERIPH) != 0x00))

/**
  * @}
  */

/** @defgroup Clock_source_to_output_on_MCO_pin 
  * @{
  */

#define RCC_MCO_NoClock                  ((uint8_t)0x00)
#define RCC_MCO_SYSCLK                   ((uint8_t)0x04)
#define RCC_MCO_HSI                      ((uint8_t)0x05)
#define RCC_MCO_HSE                      ((uint8_t)0x06)
#define RCC_MCO_PLLCLK_Div2              ((uint8_t)0x07)

#ifndef STM32F10X_CL
 #define IS_RCC_MCO(MCO) (((MCO) == RCC_MCO_NoClock) || ((MCO) == RCC_MCO_HSI) || \
                          ((MCO) == RCC_MCO_SYSCLK)  || ((MCO) == RCC_MCO_HSE) || \
                          ((MCO) == RCC_MCO_PLLCLK_Div2))
#else
 #define RCC_MCO_PLL2CLK                 ((uint8_t)0x08)
 #define RCC_MCO_PLL3CLK_Div2            ((uint8_t)0x09)
 #define RCC_MCO_XT1                     ((uint8_t)0x0A)
 #define RCC_MCO_PLL3CLK                 ((uint8_t)0x0B)

 #define IS_RCC_MCO(MCO) (((MCO) == RCC_MCO_NoClock) || ((MCO) == RCC_MCO_HSI) || \
                          ((MCO) == RCC_MCO_SYSCLK)  || ((MCO) == RCC_MCO_HSE) || \
                          ((MCO) == RCC_MCO_PLLCLK_Div2) || ((MCO) == RCC_MCO_PLL2CLK) || \
                          ((MCO) == RCC_MCO_PLL3CLK_Div2) || ((MCO) == RCC_MCO_XT1) || \
                          ((MCO) == RCC_MCO_PLL3CLK))
#endif /* STM32F10X_CL */ 

/**
  * @}
  */

/** @defgroup RCC_Flag 
  * @{
  */

#define RCC_FLAG_HSIRDY                  ((uint8_t)0x21)
#define RCC_FLAG_HSERDY                  ((uint8_t)0x31)
#define RCC_FLAG_PLLRDY                  ((uint8_t)0x39)
#define RCC_FLAG_LSERDY                  ((uint8_t)0x41)
#define RCC_FLAG_LSIRDY                  ((uint8_t)0x61)
#define RCC_FLAG_PINRST                  ((uint8_t)0x7A)
#define RCC_FLAG_PORRST                  ((uint8_t)0x7B)
#define RCC_FLAG_SFTRST                  ((uint8_t)0x7C)
#define RCC_FLAG_IWDGRST                 ((uint8_t)0x7D)
#define RCC_FLAG_WWDGRST                 ((uint8_t)0x7E)
#define RCC_FLAG_LPWRRST                 ((uint8_t)0x7F)

#ifndef STM32F10X_CL
 #define IS_RCC_FLAG(FLAG) (((FLAG) == RCC_FLAG_HSIRDY) || ((FLAG) == RCC_FLAG_HSERDY) || \
                            ((FLAG) == RCC_FLAG_PLLRDY) || ((FLAG) == RCC_FLAG_LSERDY) || \
                            ((FLAG) == RCC_FLAG_LSIRDY) || ((FLAG) == RCC_FLAG_PINRST) || \
                            ((FLAG) == RCC_FLAG_PORRST) || ((FLAG) == RCC_FLAG_SFTRST) || \
                            ((FLAG) == RCC_FLAG_IWDGRST)|| ((FLAG) == RCC_FLAG_WWDGRST)|| \
                            ((FLAG) == RCC_FLAG_LPWRRST))
#else
 #define RCC_FLAG_PLL2RDY                ((uint8_t)0x3B) 
 #define RCC_FLAG_PLL3RDY                ((uint8_t)0x3D) 
 #define IS_RCC_FLAG(FLAG) (((FLAG) == RCC_FLAG_HSIRDY) || ((FLAG) == RCC_FLAG_HSERDY) || \
                            ((FLAG) == RCC_FLAG_PLLRDY) || ((FLAG) == RCC_FLAG_LSERDY) || \
                            ((FLAG) == RCC_FLAG_PLL2RDY) || ((FLAG) == RCC_FLAG_PLL3RDY) || \
                            ((FLAG) == RCC_FLAG_LSIRDY) || ((FLAG) == RCC_FLAG_PINRST) || \
                            ((FLAG) == RCC_FLAG_PORRST) || ((FLAG) == RCC_FLAG_SFTRST) || \
                            ((FLAG) == RCC_FLAG_IWDGRST)|| ((FLAG) == RCC_FLAG_WWDGRST)|| \
                            ((FLAG) == RCC_FLAG_LPWRRST))
#endif /* STM32F10X_CL */ 

#define IS_RCC_CALIBRATION_VALUE(VALUE) ((VALUE) <= 0x1F)
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup RCC_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup RCC_Exported_Functions
  * @{
  */

void RCC_DeInit(void);
void RCC_HSEConfig(uint32_t RCC_HSE);
ErrorStatus RCC_WaitForHSEStartUp(void);
void RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue);
void RCC_HSICmd(FunctionalState NewState);
void RCC_PLLConfig(uint32_t RCC_PLLSource, uint32_t RCC_PLLMul);
void RCC_PLLCmd(FunctionalState NewState);

#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL) || defined (STM32F10X_CL)
 void RCC_PREDIV1Config(uint32_t RCC_PREDIV1_Source, uint32_t RCC_PREDIV1_Div);
#endif

#ifdef  STM32F10X_CL
 void RCC_PREDIV2Config(uint32_t RCC_PREDIV2_Div);
 void RCC_PLL2Config(uint32_t RCC_PLL2Mul);
 void RCC_PLL2Cmd(FunctionalState NewState);
 void RCC_PLL3Config(uint32_t RCC_PLL3Mul);
 void RCC_PLL3Cmd(FunctionalState NewState);
#endif /* STM32F10X_CL */ 

void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource);
uint8_t RCC_GetSYSCLKSource(void);
void RCC_HCLKConfig(uint32_t RCC_SYSCLK);
void RCC_PCLK1Config(uint32_t RCC_HCLK);
void RCC_PCLK2Config(uint32_t RCC_HCLK);
void RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState);

#ifndef STM32F10X_CL
 void RCC_USBCLKConfig(uint32_t RCC_USBCLKSource);
#else
 void RCC_OTGFSCLKConfig(uint32_t RCC_OTGFSCLKSource);
#endif /* STM32F10X_CL */ 

void RCC_ADCCLKConfig(uint32_t RCC_PCLK2);

#ifdef STM32F10X_CL
 void RCC_I2S2CLKConfig(uint32_t RCC_I2S2CLKSource);                                  
 void RCC_I2S3CLKConfig(uint32_t RCC_I2S3CLKSource);
#endif /* STM32F10X_CL */ 

/**
  * @brief  配置低速外部时钟（LSE）
  * @param  RCC_LSE : LSE 工作模式选择
  *         可选值:
  *           RCC_LSE_OFF       (关闭 LSE)
  *           RCC_LSE_ON        (启用 LSE)
  *           RCC_LSE_Bypass    (旁路模式，使用外部时钟源)
  * @note   用于驱动 RTC 和/或独立看门狗
  * @retval 无
  */
void RCC_LSEConfig(uint8_t RCC_LSE);

/**
  * @brief  使能或禁用低速内部时钟（LSI）
  * @param  NewState : LSI 状态
  *         可选值: ENABLE (启动 LSI) / DISABLE (关闭 LSI)
  * @note   LSI 用于驱动独立看门狗和 RTC
  *         启动后需等待稳定（约 128 μs）
  * @retval 无
  */
void RCC_LSICmd(FunctionalState NewState);

/**
  * @brief  选择 RTC 时钟源
  * @param  RCC_RTCCLKSource : RTC 时钟源选择
  *         可选值:
  *           RCC_RTCCLKSource_LSE   (外部低速晶振)
  *           RCC_RTCCLKSource_LSI   (内部低速 RC)
  *           RCC_RTCCLKSource_HSE_DivX (HSE 分频，X 取决于具体型号)
  * @note   必须在 RTC 禁用状态下配置
  * @retval 无
  */
void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource);

/**
  * @brief  使能或禁用 RTC 时钟
  * @param  NewState : RTC 时钟状态
  *         可选值: ENABLE (使能) / DISABLE (禁用)
  * @note   使能后无法更改时钟源
  *         需先通过 RCC_RTCCLKConfig() 配置时钟源
  * @retval 无
  */
void RCC_RTCCLKCmd(FunctionalState NewState);

/**
  * @brief  获取系统时钟频率
  * @param  RCC_Clocks : 存储时钟频率的结构体指针
  *         结构体包含:
  *           SYSCLK_Frequency  (系统时钟频率)
  *           HCLK_Frequency    (AHB 总线时钟频率)
  *           PCLK1_Frequency   (APB1 总线时钟频率)
  *           PCLK2_Frequency   (APB2 总线时钟频率)
  *           ADCCLK_Frequency  (ADC 时钟频率，部分型号)
  * @retval 无
  */
void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks);

/**
  * @brief  使能或禁用 AHB 外设时钟
  * @param  RCC_AHBPeriph : 选择 AHB 外设
  *         (可组合使用 | 操作符选择多个外设)
  *         常见值:
  *           RCC_AHBPeriph_DMA1
  *           RCC_AHBPeriph_DMA2
  *           RCC_AHBPeriph_SRAM
  *           RCC_AHBPeriph_FLITF
  *           RCC_AHBPeriph_CRC
  *           RCC_AHBPeriph_FSMC (部分型号)
  *           RCC_AHBPeriph_SDIO (部分型号)
  * @param  NewState : 时钟状态 (ENABLE/DISABLE)
  * @retval 无
  */
void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);

/**
  * @brief  使能或禁用 APB2 外设时钟
  * @param  RCC_APB2Periph : 选择 APB2 外设
  *         (可组合使用 | 操作符选择多个外设)
  *         常见值:
  *           RCC_APB2Periph_AFIO
  *           RCC_APB2Periph_GPIOA-GPIOG
  *           RCC_APB2Periph_ADC1
  *           RCC_APB2Periph_ADC2
  *           RCC_APB2Periph_TIM1
  *           RCC_APB2Periph_SPI1
  *           RCC_APB2Periph_USART1
  * @param  NewState : 时钟状态 (ENABLE/DISABLE)
  * @retval 无
  */
void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);

/**
  * @brief  使能或禁用 APB1 外设时钟
  * @param  RCC_APB1Periph : 选择 APB1 外设
  *         (可组合使用 | 操作符选择多个外设)
  *         常见值:
  *           RCC_APB1Periph_TIM2-TIM7
  *           RCC_APB1Periph_WWDG
  *           RCC_APB1Periph_SPI2
  *           RCC_APB1Periph_USART2-USART5
  *           RCC_APB1Periph_I2C1-I2C2
  *           RCC_APB1Periph_USB
  *           RCC_APB1Periph_CAN
  *           RCC_APB1Periph_BKP
  *           RCC_APB1Periph_PWR
  *           RCC_APB1Periph_DAC
  * @param  NewState : 时钟状态 (ENABLE/DISABLE)
  * @note   APB1 最大时钟频率通常低于 APB2（例如 36MHz vs 72MHz）
  * @retval 无
  */
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);






#ifdef STM32F10X_CL
void RCC_AHBPeriphResetCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);
#endif /* STM32F10X_CL */ 

/**
  * @brief  控制 APB2 外设复位（高级外设总线 2）
  * @param  RCC_APB2Periph : 选择要复位的 APB2 外设
  *         (可组合使用 | 操作符选择多个外设)
  *         例如: RCC_APB2Periph_USART1 | RCC_APB2Periph_SPI1
  * @param  NewState : 外设复位状态
  *         可选值: ENABLE (复位外设) / DISABLE (释放复位)
  * @retval 无
  */
void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);

/**
  * @brief  控制 APB1 外设复位（高级外设总线 1）
  * @param  RCC_APB1Periph : 选择要复位的 APB1 外设
  *         (可组合使用 | 操作符选择多个外设)
  *         例如: RCC_APB1Periph_USART2 | RCC_APB1Periph_TIM2
  * @param  NewState : 外设复位状态
  *         可选值: ENABLE (复位外设) / DISABLE (释放复位)
  * @retval 无
  */
void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);

/**
  * @brief  控制备份域复位（包括 RTC 和备份寄存器）
  * @param  NewState : 备份域复位状态
  *         可选值: ENABLE (触发备份域复位) / DISABLE (无操作)
  * @note   复位后备份域处于保护状态，需先使能访问权限
  * @retval 无
  */
void RCC_BackupResetCmd(FunctionalState NewState);

/**
  * @brief  使能或禁用时钟安全系统（CSS）
  * @param  NewState : CSS 功能状态
  *         可选值: ENABLE (启用时钟监控) / DISABLE (关闭监控)
  * @note   当外部时钟失效时，CSS 会触发 NMI 中断和系统复位
  * @retval 无
  */
void RCC_ClockSecuritySystemCmd(FunctionalState NewState);

/**
  * @brief  配置微控制器时钟输出（MCO）
  * @param  RCC_MCO : 选择输出到 MCO 引脚的时钟源
  *         可选值:
  *           RCC_MCO_NoClock    (无输出)
  *           RCC_MCO_SYSCLK     (系统时钟)
  *           RCC_MCO_HSI        (内部高速时钟)
  *           RCC_MCO_HSE        (外部高速时钟)
  *           RCC_MCO_PLLCLK     (PLL 输出时钟)
  * @note   需在外部引脚配置为复用功能模式下使用
  * @retval 无
  */
void RCC_MCOConfig(uint8_t RCC_MCO);

/**
  * @brief  检查指定的 RCC 标志位状态
  * @param  RCC_FLAG : 要检查的标志位
  *         可选值:
  *           RCC_FLAG_HSIRDY   (HSI 时钟就绪)
  *           RCC_FLAG_HSERDY   (HSE 时钟就绪)
  *           RCC_FLAG_PLLRDY   (PLL 就绪)
  *           RCC_FLAG_LSERDY   (LSE 时钟就绪)
  *           RCC_FLAG_LSIRDY   (LSI 时钟就绪)
  *           RCC_FLAG_BORRST   (欠压复位标志)
  *           RCC_FLAG_PINRST   (引脚复位标志)
  *           RCC_FLAG_PORRST   (上电复位标志)
  *           RCC_FLAG_SFTRST   (软件复位标志)
  *           RCC_FLAG_IWDGRST  (独立看门狗复位标志)
  *           RCC_FLAG_WWDGRST  (窗口看门狗复位标志)
  *           RCC_FLAG_LPWRRST  (低功耗复位标志)
  * @retval FlagStatus : 标志位状态 (SET 或 RESET)
  */
FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG);

/**
  * @brief  清除所有 RCC 复位标志
  * @note   用于清除电源控制/状态寄存器(PWR_CSR)中的复位标志位
  * @retval 无
  */
void RCC_ClearFlag(void);

/**
  * @brief  检查指定的 RCC 中断是否发生
  * @param  RCC_IT : 要检查的中断源
  *         可选值:
  *           RCC_IT_LSIRDY    (LSI 就绪中断)
  *           RCC_IT_LSERDY    (LSE 就绪中断)
  *           RCC_IT_HSIRDY    (HSI 就绪中断)
  *           RCC_IT_HSERDY    (HSE 就绪中断)
  *           RCC_IT_PLLRDY    (PLL 就绪中断)
  *           RCC_IT_CSS       (时钟安全系统中断)
  * @retval ITStatus : 中断状态 (SET 表示中断发生，RESET 表示未发生)
  */
ITStatus RCC_GetITStatus(uint8_t RCC_IT);

/**
  * @brief  清除 RCC 的中断挂起位
  * @param  RCC_IT : 要清除的中断源
  *         可选值: @ref RCC_GetITStatus 中的中断源
  * @retval 无
  */
void RCC_ClearITPendingBit(uint8_t RCC_IT);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F10x_RCC_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
