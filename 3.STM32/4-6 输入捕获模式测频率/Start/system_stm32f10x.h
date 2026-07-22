/**
  ******************************************************************************
  * @file    system_stm32f10x.h
  * @author  MCD 应用团队
  * @version V3.5.0
  * @date    2011年3月11日
  * @brief   CMSIS Cortex-M3 设备外设访问层系统头文件。
  ******************************************************************************
  * @attention
  *
  * 本固件仅作指导用途，旨在为客户提供与其产品相关的编码信息，以节省客户时间。
  * 因此，对于因本固件内容及/或客户使用本文件中包含的编码信息所引发的任何索赔，
  * 意法半导体不承担任何直接、间接或 CONSEQUENTIAL（间接）损害责任。
  *
  * <h2><center>&copy; 版权所有 2011 意法半导体</center></h2>
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f10x_system
  * @{
  */  
  
/**
  * @brief Define to prevent recursive inclusion
  */
#ifndef __SYSTEM_STM32F10X_H
#define __SYSTEM_STM32F10X_H

#ifdef __cplusplus
 extern "C" {
#endif 

/** @addtogroup STM32F10x_System_Includes
  * @{
  */

/**
  * @}
  */


/** @addtogroup STM32F10x_System_Exported_types
  * @{
  */

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */

/**
  * @}
  */

/** @addtogroup STM32F10x_System_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F10x_System_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F10x_System_Exported_Functions
  * @{
  */
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_STM32F10X_H */

/**
  * @}
  */
  
/**
  * @}
  */  
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
