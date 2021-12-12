# pow-miner-gpu-wingui

TON wallet address for donations: <br />
__EQAvRnuckR42aEE29_WCDCTOwEci1ZKo8a5ul4ncYWaqxA2q__

Install prerequisites before start:
1. __Microsoft .NET Framework 4 (offline installator)__ - https://www.microsoft.com/ru-ru/download/details.aspx?id=17718

How to use:
1. Download and extract __to path with no Cyrillic symbols__ or use __.MSI or .EXE installers__! If you will use an installer then <br />
the __default installation directory will be "C:\TON Community\pow-miner-gpu-wingui"__. If you will change the directory for instance to <br />
__"C:\Program Files\TON Community\pow-miner-gpu-wingui"__ then for any file operations like update or dumps __you will need to start <br />
application with administrative rights__. So, please, left default installation directory.
2. Execute pow-miner-gpu-wingui.exe
3. Go to "file->update tools"
4. It will update "miner-tools-*" and "global.config.json"
5. Close "update tools subwindow"
6. Press button "Search CUDA/OpenCL devices"
7. Select device int the list by pressing mouse left key
8. Press "Use device"
9. Type "Wallet address"
10. Press "Start" or "Start all" button
11. In File->Settings you can also configure AUTO START ALL MINERS after GUI start! It can be very helpfull if your rig reboots sometimes.
12. In File->Settings you can also configure AUTO LOGS/ERRORS DUMP to files FEATURE.
13. Enjoy!

If you have any problems with DLLs on start try to install:
1. __Microsoft Visual C++ Visual Studio 2015-2019 Redistributable x64 (offline installator)__ - https://go.microsoft.com/fwlink/?LinkId=746572
2. __Microsoft Visual C++ Visual Studio 2015-2019 Redistributable x86 (offline installator)__ - https://go.microsoft.com/fwlink/?LinkId=746571
