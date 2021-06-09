#-------------------------------------------------
#
# Project created by QtCreator 2021-05-31T15:14:45
#
#-------------------------------------------------

#QT       += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += "../3rd/Qt5.10.1/include/QtWidgets/"
INCLUDEPATH += "../3rd/Qt5.10.1/include/QtCore/"
INCLUDEPATH += "../3rd/Qt5.10.1/include/QtGui/"
INCLUDEPATH += "../3rd/NDI/include/"
INCLUDEPATH += "../3rd/NDI/src/"
INCLUDEPATH += "../3rd/NDI/src/include/"


CONFIG(debug, debug|release): {
LIBS += -L../3rd/Qt5.10.1/lib \
-lQt5Cored \
-lQt5Guid \
-lQt5Widgetsd \
-lqtmaind \
} else:CONFIG(release, debug|release): {
LIBS += -L../3rd/Qt5.10.1/lib \
-lQt5Cored \
-lQt5Guid \
-lQt5Widgetsd \
-lqtmaind \
}

#预宏定义
DEFINES += CAPICOMMON_EXPORTS
#使用多字节字符集
DEFINES  -= UNICODE
DEFINES  += UMBCS

TARGET = NDI_CAPI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    ../3rd/NDI/src/BufferedReader.cpp \
    ../3rd/NDI/src/CombinedApi.cpp \
   ../3rd/NDI/src/ComConnection.cpp \
    ../3rd/NDI/src/GbfButton1D.cpp \
    ../3rd/NDI/src/GbfComponent.cpp \
    ../3rd/NDI/src/GbfContainer.cpp \
    ../3rd/NDI/src/GbfData3D.cpp \
    ../3rd/NDI/src/GbfData6D.cpp \
    ../3rd/NDI/src/GbfFrame.cpp \
    ../3rd/NDI/src/GbfSystemAlert.cpp \
    ../3rd/NDI/src/MarkerData.cpp \
    ../3rd/NDI/src/PortHandleInfo.cpp \
    ../3rd/NDI/src/SystemAlert.cpp \
    ../3rd/NDI/src/SystemCRC.cpp \
    ../3rd/NDI/src/ToolData.cpp \
    ../3rd/NDI/src/Transform.cpp \
    mainwindow.cpp \
    processtrackingdata.cpp

HEADERS += \
    ../3rd/NDI/include/CombinedApi.h \
    ../3rd/NDI/include/MarkerData.h \
    ../3rd/NDI/include/PortHandleInfo.h \
    ../3rd/NDI/include/SystemAlert.h \
    ../3rd/NDI/include/ToolData.h \
    ../3rd/NDI/include/Transform.h \
    ../3rd/NDI/src/include/BufferedReader.h \
    ../3rd/NDI/src/include/ComConnection.h \
    ../3rd/NDI/src/include/Connection.h \
    ../3rd/NDI/src/include/GbfButton1D.h \
    ../3rd/NDI/src/include/GbfComponent.h \
    ../3rd/NDI/src/include/GbfContainer.h \
    ../3rd/NDI/src/include/GbfData3D.h \
    ../3rd/NDI/src/include/GbfData6D.h \
    ../3rd/NDI/src/include/GbfFrame.h \
    ../3rd/NDI/src/include/GbfSystemAlert.h \
    ../3rd/NDI/src/include/qinfofile.h \
    ../3rd/NDI/src/include/SystemCRC.h \
    mainwindow.h \
    processtrackingdata.h

FORMS += \
    mainwindow.ui
