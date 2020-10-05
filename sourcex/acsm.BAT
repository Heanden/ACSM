SET PATH=C:\Keil\ARM\ARMCC\bin\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\Git\cmd;C:\Users\Heang\AppData\Local\Microsoft\WindowsApps;;C:\Users\Heang\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files\Bandizip\
SET CPU_TYPE=STM32F103C8
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=acsm
SET CPU_CLOCK=0x007A1200
"C:\Keil\ARM\ARMCC\bin\ArmAsm" --Via ".\startup_stm32f10x_md._ia"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\misc.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\stm32f10x_exti.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\stm32f10x_gpio.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\stm32f10x_rcc.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\core_cm3.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\system_stm32f10x.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\key.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\leddt.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\main.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\stm32f10x_it.__i"
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\systick.__i"
"C:\Keil\ARM\ARMCC\bin\ArmLink" --Via ".\acsm.lnp"
C:\Keil\ARM\ARMCC\bin\fromelf.exe ".\acsm.axf" --i32combined --output ".\acsm.hex"
