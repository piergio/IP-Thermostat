#-------------------------------------------------
#
# Project created by QtCreator 2016-06-21T10:31:53
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MTempClient
TEMPLATE = app

INCLUDEPATH += ..\..\mplabx\include

SOURCES += main.cpp\
        MTempClient.cpp \
    MTempCommons.cpp \
    NetworkConfig.cpp \
    MClient.cpp \
    Loader.cpp \
    Login.cpp \
    GuiRoom.cpp \
    EditRoom.cpp

HEADERS  += MTempClient.h \
    MTempDefs.h \
    MTempCommons.h \
    NetworkConfig.h \
    MClient.h \
    Loader.h \
    Login.h \
    clientdefs.h \
    GuiRoom.h \
    EditRoom.h

FORMS    += MTempClient.ui \
    NetworkConfig.ui \
    Loader.ui \
    Login.ui \
    EditRoom.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
