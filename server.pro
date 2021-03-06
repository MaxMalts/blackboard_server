QT += core
QT -= gui
QT += network
QT += widgets

CONFIG += c++11

TARGET = server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    client_api.cpp \
    graphics_items.cpp \
    layer.cpp \
    packagereadmanager.cpp \
    serializable_types.cpp \
    serializers.cpp \
    server.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    client_api.h \
    cyclic_stack.h \
    graphics_items.h \
    layer.h \
    packagereadmanager.h \
    serializable_types.h \
    serializers.h \
    server.h

