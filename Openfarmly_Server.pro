QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    qtmavfly.cpp \
    widget.cpp

HEADERS += \
    qtmavfly.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



unix:!macx: LIBS += -L$$PWD/MAVfly/lib/ -lmavfly
unix:!macx: LIBS += -L$$PWD/lib/ -lmavsdk

INCLUDEPATH += $$PWD/MAVfly/lib/includes
DEPENDPATH += $$PWD/MAVfly/lib/includes
INCLUDEPATH += $$PWD/MAVfly/lib/includes/mavsdk
#message("MAVfly Includes Path: $$PWD/MAVfly/lib/includes")

#QMAKE_LFLAGS += -Wl,-rpath,/opt/Openfarmly_Server/bin/
QMAKE_LFLAGS += -Wl,-rpath,\$$ORIGIN

RESOURCES += \
    res.qrc
