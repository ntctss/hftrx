#pragma once
#ifndef HEADER_00003039_INCLUDED
#define HEADER_00003039_INCLUDED
#include <stdint.h>


/* IRQs */

typedef enum IRQn
{
    SGI0_IRQn = 0,                                    /*!<   Interrupt */
    SGI1_IRQn = 1,                                    /*!<   Interrupt */
    SGI2_IRQn = 2,                                    /*!<   Interrupt */
    SGI3_IRQn = 3,                                    /*!<   Interrupt */
    SGI4_IRQn = 4,                                    /*!<   Interrupt */
    SGI5_IRQn = 5,                                    /*!<   Interrupt */
    SGI6_IRQn = 6,                                    /*!<   Interrupt */
    SGI7_IRQn = 7,                                    /*!<   Interrupt */
    SGI8_IRQn = 8,                                    /*!<   Interrupt */
    SGI9_IRQn = 9,                                    /*!<   Interrupt */
    SGI10_IRQn = 10,                                  /*!<   Interrupt */
    SGI11_IRQn = 11,                                  /*!<   Interrupt */
    SGI12_IRQn = 12,                                  /*!<   Interrupt */
    SGI13_IRQn = 13,                                  /*!<   Interrupt */
    SGI14_IRQn = 14,                                  /*!<   Interrupt */
    SGI15_IRQn = 15,                                  /*!<   Interrupt */
    VirtualMaintenanceInterrupt_IRQn = 25,            /*!<   Interrupt */
    HypervisorTimer_IRQn = 26,                        /*!<   Interrupt */
    VirtualTimer_IRQn = 27,                           /*!<   Interrupt */
    Legacy_nFIQ_IRQn = 28,                            /*!<   Interrupt */
    SecurePhysicalTimer_IRQn = 29,                    /*!<   Interrupt */
    NonSecurePhysicalTimer_IRQn = 30,                 /*!<   Interrupt */
    Legacy_nIRQ_IRQn = 31,                            /*!<   Interrupt */
    UART0_IRQn = 96,                                  /*!< UART Universal Asynchronous Receiver-Transmitter Interrupt */
    UART1_IRQn = 97,                                  /*!< UART Universal Asynchronous Receiver-Transmitter Interrupt */
    UART2_IRQn = 98,                                  /*!< UART Universal Asynchronous Receiver-Transmitter Interrupt */
    UART3_IRQn = 99,                                  /*!< UART Universal Asynchronous Receiver-Transmitter Interrupt */

    MAX_IRQ_n,
    Force_IRQn_enum_size = 1048 /* Dummy entry to ensure IRQn_Type is more than 8 bits. Otherwise GIC init loop would fail */
} IRQn_Type;


/* Peripheral and RAM base address */

#define UART0_BASE ((uintptr_t) 0x38028000)           /*!< UART Base */
#define UART1_BASE ((uintptr_t) 0x38029000)           /*!< UART Base */
#define UART2_BASE ((uintptr_t) 0x3802A000)           /*!< UART Base */
#define UART3_BASE ((uintptr_t) 0x3802B000)           /*!< UART Base */
#define CMCTR_BASE ((uintptr_t) 0x38094000)           /*!< CMCTR Base */
#define PMCTR_BASE ((uintptr_t) 0x38095000)           /*!< PMCTR Base */
#define SMCTR_BASE ((uintptr_t) 0x38096000)           /*!< SMCTR Base */
#define GIC_INTERFACE_BASE ((uintptr_t) 0x39000100)   /*!<  Base */
#define GIC_DISTRIBUTOR_BASE ((uintptr_t) 0x39001000) /*!<  Base */

/*
 * @brief PMCTR
 */
/*!< PMCTR Контроллер управления энергопотреблением */
typedef struct PMCTR_Type
{
             uint32_t reserved_0x000 [0x0003];
    volatile uint32_t SYS_PWR_STATUS;                 /*!< Offset 0x00C Регистр статуса доменов */
    volatile uint32_t SYS_PWR_IMASK;                  /*!< Offset 0x010 Регистр маски прерывания SYS_PWR_INT */
    volatile uint32_t SYS_PWR_IRSTAT;                 /*!< Offset 0x014 Регистр наличного статуса прерывания SYS_PWR_ISTAT */
    volatile uint32_t SYS_PWR_INT;                    /*!< Offset 0x018 Регистр статуса прерывания SYS_PWR_INT */
    volatile uint32_t SYS_PWR_ICLR;                   /*!< Offset 0x01C Регистр очистки статуса прерывания SYS_PWR_INT */
    volatile uint32_t SYS_PWR_DELAY;                  /*!< Offset 0x020 Регистр задания задержек автоматов */
    volatile uint32_t DDR_PIN_RET;                    /*!< Offset 0x024 Регистр перевода выводов DDR в режим хранения состояния */
    volatile uint32_t DDR_INIT_END;                   /*!< Offset 0x028 Регистр вывода контроллеров DDRMC0, DDRMC1 из режима инициализации */
    volatile uint32_t WARM_RST_EN;                    /*!< Offset 0x02C Регистр разрешения «теплого» сброса */
             uint32_t reserved_0x030 [0x0004];
    volatile uint32_t SW_RST;                         /*!< Offset 0x040 Регистр программного «теплого» сброса */
    volatile uint32_t WARM_RST_STATUS;                /*!< Offset 0x044 Регистр статуса последнего сброса */
    volatile uint32_t PDM_RST_STATUS;                 /*!< Offset 0x048 Регистр статуса сброса доменов питания */
    volatile uint32_t NVMODE;                         /*!< Offset 0x04C Регистр управления сигналами NVMODE */
    volatile uint32_t CPU0_WKP_MASK [0x004];          /*!< Offset 0x050 Регистр маски включения домена CPU0 по прерываниям */
    volatile uint32_t CPU1_WKP_MASK [0x004];          /*!< Offset 0x060 Регистр маски включения домена CPU1 по прерываниям */
    volatile uint32_t ALWAYS_MISC0;                   /*!< Offset 0x070 Регистр общего назначения, не сбрасываемый при «теплом» сбросе */
    volatile uint32_t ALWAYS_MISC1;                   /*!< Offset 0x074 Регистр общего назначения, не сбрасываемый при «теплом» сбросе */
    volatile uint32_t WARM_BOOT_OVRD;                 /*!< Offset 0x078 Регистр управления загрузкой при «теплом» сбросе */
             uint32_t reserved_0x07C;
    volatile uint32_t CORE_PWR_UP;                    /*!< Offset 0x080 Регистр включения доменов */
    volatile uint32_t CORE_PWR_DOWN;                  /*!< Offset 0x084 Регистр выключения доменов */
             uint32_t reserved_0x088;
    volatile uint32_t CORE_PWR_STATUS;                /*!< Offset 0x08C Регистр статуса доменов */
    volatile uint32_t CORE_PWR_IMASK;                 /*!< Offset 0x090 Регистр маски прерывания CORE_PWR_INT */
    volatile uint32_t CORE_PWR_IRSTAT;                /*!< Offset 0x094 Регистр наличного статуса прерывания CORE_PWR_INT */
    volatile uint32_t CORE_PWR_ISTAT;                 /*!< Offset 0x098 Регистр статуса прерывания CORE_PWR_INT */
    volatile uint32_t CORE_PWR_ICLR;                  /*!< Offset 0x09C Регистр очистки статуса прерывания CORE_PWR_INT */
    volatile uint32_t CORE_PWR_DELAY;                 /*!< Offset 0x0A0 Регистр задания задержек автоматов доменов */
} PMCTR_TypeDef; /* size of structure = 0x0A4 */
/*
 * @brief SMCTR
 */
/*!< SMCTR общиме системные настройки микросхемы */
typedef struct SMCTR_Type
{
    volatile uint32_t BOOT;                           /*!< Offset 0x000 Регистр отображения сигналов BOOT[1:0] микросхемы */
    volatile uint32_t BOOT_REMAP;                     /*!< Offset 0x004 Регистр управления картой памяти при начальной загрузке */
    volatile uint32_t MPU_CFGNMFI;                    /*!< Offset 0x008 Регистр разрешения немаскируемого FIQ в MPU */
    volatile uint32_t DDR_REMAP;                      /*!< Offset 0x00C Регистр управления картой памяти для DDR */
             uint32_t reserved_0x010 [0x0005];
    volatile uint32_t MIPI_MUX;                       /*!< Offset 0x024 Регистр мультиплексирования MIPI DSI */
    volatile uint32_t CHIP_ID;                        /*!< Offset 0x028 ID микросхемы */
    volatile uint32_t CHIP_CONFIG;                    /*!< Offset 0x02C Регистр конфигурации микросхемы */
    volatile uint32_t EMA_ARM;                        /*!< Offset 0x030 Регистр подстройки памятей в ARM MPU */
    volatile uint32_t EMA_L2;                         /*!< Offset 0x034 Регистр подстройки памятей в L2CACHE */
    volatile uint32_t EMA_DSP;                        /*!< Offset 0x038 Регистр подстройки памятей в DSP и VPU */
    volatile uint32_t EMA_CORE;                       /*!< Offset 0x03C Регистр подстройки памятей в CORE */
    volatile uint32_t IOPULL_CTR;                     /*!< Offset 0x040 Регистры управления подтягивающими резисторами контактных площадок микросхемы */
    volatile uint32_t COMM_DLOCK;                     /*!< Offset 0x044 Регистр индикации зависания коммутатора микросхемы */
} SMCTR_TypeDef; /* size of structure = 0x048 */
/*
 * @brief CMCTR
 */
/*!< CMCTR Контроллер управления синхронизацией */
typedef struct CMCTR_Type
{
             uint32_t reserved_0x000;
    volatile uint32_t DIV_MPU_CTR;                    /*!< Offset 0x004 Регистр делителя частоты MPUCLK */
    volatile uint32_t DIV_ATB_CTR;                    /*!< Offset 0x008 Регистр делителя частоты ATCLK */
    volatile uint32_t DIV_APB_CTR;                    /*!< Offset 0x00C Регистр делителя частоты APCLK */
    volatile uint32_t CHIP_REVISION;                  /*!< Offset 0x010 Регистр ревизии микросхемы */
    volatile uint32_t GATE_MPU_CTR;                   /*!< Offset 0x014 Регистр по управлению отключением частот в CMCTR_MPU */
             uint32_t reserved_0x018 [0x0005];
    volatile uint32_t DIV_GPU_CTR;                    /*!< Offset 0x02C Регистр делителя частоты GPU_ACLK */
    volatile uint32_t DIV_DDR0_CTR;                   /*!< Offset 0x030 Регистр делителя частоты DDR0_SCLK */
    volatile uint32_t DIV_DDR1_CTR;                   /*!< Offset 0x034 Регистр делителя частоты DDR1_SCLK */
    volatile uint32_t DIV_NFC_CTR;                    /*!< Offset 0x038 Регистр делителя частоты NFC_SCLK */
    volatile uint32_t DIV_NOR_CTR;                    /*!< Offset 0x03C Регистр делителя частоты NOR_SCLK */
    volatile uint32_t DIV_SYS0_CTR;                   /*!< Offset 0x040 Регистр делителя частоты L1_HCLK и связанных с ней частот */
    volatile uint32_t DIV_SYS1_CTR;                   /*!< Offset 0x044 Регистр делителя частоты L3_PCLK и связанных с ней частот */
    volatile uint32_t GATE_CORE_CTR;                  /*!< Offset 0x048 Регистр по управлению отключением частот в CMCTR_CORE */
    volatile uint32_t GATE_SYS_CTR;                   /*!< Offset 0x04C Регистр по управлению отключением частот в CMCTR_SYS */
             uint32_t reserved_0x050 [0x0006];
    volatile uint32_t GATE_DSP_CTR;                   /*!< Offset 0x068 Регистр по управлению отключением частот в CMCTR_DSP */
             uint32_t reserved_0x06C [0x0005];
    volatile uint32_t MUX_CLKOUT;                     /*!< Offset 0x080 Регистр выбора частоты для вывода CLKOUT */
    volatile uint32_t DIV_CLKOUT;                     /*!< Offset 0x084 Регистр делителя частоты для вывода CLKOUT */
    volatile uint32_t GATE_CLKOUT;                    /*!< Offset 0x088 Регистр управления отключением частоты для вывода CLKOUT */
             uint32_t reserved_0x08C;
    volatile uint32_t LS_ENABLE;                      /*!< Offset 0x090 Регистр контроля функции LightSleep памятей микросхемы */
             uint32_t reserved_0x094 [0x001B];
    volatile uint32_t SEL_APLL;                       /*!< Offset 0x100 Регистр контроля APLL */
    volatile uint32_t SEL_CPLL;                       /*!< Offset 0x104 Регистр контроля CPLL */
    volatile uint32_t SEL_DPLL;                       /*!< Offset 0x108 Регистр контроля DPLL */
    volatile uint32_t SEL_SPLL;                       /*!< Offset 0x10C Регистр контроля SPLL */
    volatile uint32_t SEL_VPLL;                       /*!< Offset 0x110 Регистр контроля VPLL */
    volatile uint32_t SEL_UPLL;                       /*!< Offset 0x114 Регистр контроля UPLL */
} CMCTR_TypeDef; /* size of structure = 0x118 */
/*
 * @brief UART
 */
/*!< UART Universal Asynchronous Receiver-Transmitter */
typedef struct UART_Type
{
    volatile uint32_t UART_RBR_THR_DLL;               /*!< Offset 0x000 UART Receive Buffer Register/Transmit Holding Register */
    volatile uint32_t UART_DLH_IER;                   /*!< Offset 0x004  */
    volatile uint32_t UART_IIR_FCR;                   /*!< Offset 0x008 UART Interrupt Identity Register/UART FIFO Control Register */
    volatile uint32_t UART_LCR;                       /*!< Offset 0x00C UART Line Control Register */
    volatile uint32_t UART_MCR;                       /*!< Offset 0x010 UART Modem Control Register */
    volatile uint32_t UART_LSR;                       /*!< Offset 0x014 UART Line Status Register */
    volatile uint32_t UART_MSR;                       /*!< Offset 0x018 UART Modem Status Register */
    volatile uint32_t UART_SCR;                       /*!< Offset 0x01C UART Scratch Register */
             uint32_t reserved_0x020 [0x0004];
    volatile uint32_t UART_SRBR_STHR [0x010];         /*!< Offset 0x030  */
             uint32_t reserved_0x070 [0x0003];
    volatile uint32_t UART_USR;                       /*!< Offset 0x07C  */
    volatile uint32_t UART_TFL;                       /*!< Offset 0x080  */
    volatile uint32_t UART_RFL;                       /*!< Offset 0x084  */
    volatile uint32_t UART_SRR;                       /*!< Offset 0x088  */
    volatile uint32_t UART_SRTS;                      /*!< Offset 0x08C  */
    volatile uint32_t UART_SBCR;                      /*!< Offset 0x090 check address (was: 0x80)  */
             uint32_t reserved_0x094;
    volatile uint32_t UART_SFE;                       /*!< Offset 0x098  */
    volatile uint32_t UART_SRT;                       /*!< Offset 0x09C  */
    volatile uint32_t UART_STET;                      /*!< Offset 0x0A0  */
    volatile uint32_t UART_HTX;                       /*!< Offset 0x0A4  */
} UART_TypeDef; /* size of structure = 0x0A8 */


/* Access pointers */

#define UART0 ((UART_TypeDef *) UART0_BASE)           /*!< UART0 Universal Asynchronous Receiver-Transmitter register set access pointer */
#define UART1 ((UART_TypeDef *) UART1_BASE)           /*!< UART1 Universal Asynchronous Receiver-Transmitter register set access pointer */
#define UART2 ((UART_TypeDef *) UART2_BASE)           /*!< UART2 Universal Asynchronous Receiver-Transmitter register set access pointer */
#define UART3 ((UART_TypeDef *) UART3_BASE)           /*!< UART3 Universal Asynchronous Receiver-Transmitter register set access pointer */
#define CMCTR ((CMCTR_TypeDef *) CMCTR_BASE)          /*!< CMCTR Контроллер управления синхронизацией register set access pointer */
#define PMCTR ((PMCTR_TypeDef *) PMCTR_BASE)          /*!< PMCTR Контроллер управления энергопотреблением register set access pointer */
#define SMCTR ((SMCTR_TypeDef *) SMCTR_BASE)          /*!< SMCTR общиме системные настройки микросхемы register set access pointer */
#define GIC_INTERFACE ((_TypeDef *) GIC_INTERFACE_BASE)/*!< GIC_INTERFACE  register set access pointer */
#define GIC_DISTRIBUTOR ((_TypeDef *) GIC_DISTRIBUTOR_BASE)/*!< GIC_DISTRIBUTOR  register set access pointer */


#endif /* HEADER_00003039_INCLUDED */
