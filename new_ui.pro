QT       += core gui network sql location widgets quick quickwidgets positioning

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

QMAKE_CXXFLAGS += -Wa,-mbig-obj

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    datetime.cpp \
    futureweather.cpp \
    intermediatewindow.cpp \
    logicmaths.cpp \
    main.cpp \
    mainwindow.cpp \
    pastgraph.cpp \
    qcustomplot.cpp \
    todaysweather.cpp \
    weatherdata.cpp

HEADERS += \
    fetchcurrentaddress.h \
    datetime.h \
    futureweather.h \
    intermediatewindow.h \
    logicmaths.h \
    mainwindow.h \
    pastgraph.h \
    qcustomplot.h \
    todaysweather.h \
    weatherdata.h

FORMS += \
    intermediatewindow.ui \
    mainwindow.ui \
    pastgraph.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resouces.qrc \
    resources.qrc
