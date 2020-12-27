QT += quick\
 quickcontrols2
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    PathPainter/PathPainter.cpp \
    PathBuilder/PathBuilder.cpp \
    pa_CommonLibOnOS/DataConv/ImgConv/ImgConv.cpp \
    pa_CommonLibOnOS/DataConv/StrConv/StrConv.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    PathPainter/PathPainter.h \
    PathBuilder/PathBuilder.h \
    pa_CommonLibOnOS/DataConv/ImgConv/ImgConv.h \
    pa_CommonLibOnOS/DataConv/StrConv/StrConv.h

#INCLUDEPATH +=C:\opencv450mingw\build\install\include
#LIBS += C:\opencv450mingw\build\install\x64\mingw\lib\libopencv_*.a


#LIBS += C:/opencv450mingw/build/install/x64/mingw/bin/libopencv_core*.dll


#INCLUDEPATH += C:/opencv450mingw/build/install/include
#DEPENDPATH += C:/opencv450mingw/build/install/include



unix|win32: LIBS += -LC:/opencv450mingw/build/install/x64/mingw/lib/ -llibopencv_core450.dll
unix|win32: LIBS += -LC:/opencv450mingw/build/install/x64/mingw/lib/ -llibopencv_highgui450.dll
unix|win32: LIBS += -LC:/opencv450mingw/build/install/x64/mingw/lib/ -llibopencv_imgcodecs450.dll
unix|win32: LIBS += -LC:/opencv450mingw/build/install/x64/mingw/lib/ -llibopencv_imgproc450.dll

INCLUDEPATH += C:/opencv450mingw/build/install/include
DEPENDPATH += C:/opencv450mingw/build/install/include
