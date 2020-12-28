这是一个我的机械臂项目的上位机程序。

~~采用go+qtquick~~ nolonger use go qt，because it compiles too slow，and it has a bad support to qml.

~~基于的是https://github.com/therecipe/qt 这个超级多star的大佬项目（golang的qt bind）~~

# 主机端

### qt版本：5.12.0

使用的是 qml来做界面，因为要比qwidget好看的多，而且有硬件加速

#### 主要的项目放在RobotMaster_qt

golang 版的在废弃文件夹里安静的躺着。

# 从机端

机械臂嵌入式从机端[pa-CommonLib-parts/pa_RobotArm: robot arm project, based on pa_CommonLib, currently developing on stm32 h7 (github.com)](https://github.com/pa-CommonLib-parts/pa_RobotArm)

从机端程序是模块化设计的，非常便于移植到不同平台上，依赖于我的单片机通用库 pa_CommonLib [ActivePeter/pa_CommonLib: My commonLib for MCUs (github.com)](https://github.com/ActivePeter/pa_CommonLib)

