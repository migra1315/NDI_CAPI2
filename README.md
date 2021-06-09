和NDI_CAPI相同，改为用共享内存实现两个进程之间的数据传输。

# button/功能介绍

## NDI_CAPI中：

1. Config

   建立连接，导入*.rom

 2. Track

    与NDI通过串口通信，将数据以Json格式存入共享内存

 3. TrackSimulate

    将模拟数据以Json格式存入共享内存

## readShareMemory中

1. 读取数据

   将数据以Json格式读出，并显示在ListWedgit中
   
   ![display](.\image_for_markdown\display.png)

# 需要说明的地方

关于与NDI连接时的配置日志信息，仍然是以emit Signals 形式发出，一个对应的Slot qDebug()<<"log"

# 文件内容结构

- NDI_CAPI2
	- README.md
	- image_for_markdown
	- NDI_CAPI
	  - res	#存储NDI描述文件
	  - .pro/.sln/.h/.cpp……
	- readSharedMemory
	  - .pro/.sln/.h/.cpp……
	- dll_store
	  - 两个进程的Debug/Release发布的.exe及其依赖库
	- 3rd （链接：https://pan.baidu.com/s/17_-1snLo6mBgBR_Z0gQlog 提取码：4db9  ）


​    

