SET PATH=C:\Keil\ARM\ARMCC\bin\;C:\Program Files\Common Files\Siemens\Automation\Simatic OAM\bin;C:\Program Files\VanDyke Software\Clients\;C:\Program Files (x86)\Common Files\Intel\Shared Libraries\redist\intel64_win\compiler;C:\Program Files (x86)\Common Files\Intel\Shared Libraries\redist\intel64\compiler;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\Intel\OpenCL SDK\3.0\bin\x86;C:\Program Files (x86)\Intel\OpenCL SDK\3.0\bin\x64;C:\Program Files\Polyspace\R2019a\runtime\win64;C:\Program Files\Polyspace\R2019a\bin;C:\Program Files\Polyspace\R2019a\polyspace\bin;C:\Program Files\Pandoc\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\dotnet\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\Git\cmd;C:\Users\gavin\AppData\Local\Programs\Python\Python38\Scripts\;C:\Users\gavin\AppData\Local\Programs\Python\Python38\;C:\Users\gavin\AppData\Local\Programs\Python\Python38-32\Scripts\;C:\Users\gavin\AppData\Local\Programs\Python\Python38-32\;C:\Program Files\Bandizip\;C:\altera\13.0\modelsim_ase\win32aloem;C:\Users\gavin\AppData\Local\Microsoft\WindowsApps;C:\MinGW\bin;C:\glo663wb\bin;C:\Users\gavin\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files\Git\bin;C:\Users\gavin\AppData\Local\Microsoft\WindowsApps
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
