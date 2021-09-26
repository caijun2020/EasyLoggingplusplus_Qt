QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x

DEFINES += ELPP_NO_DEFAULT_LOG_FILE ELPP_QT_LOGGING

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    easyloggingpp/easylogging++.cc \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h \
    easyloggingpp/easylogging++.h

FORMS += \
    MainWindow.ui

INCLUDEPATH += $$PWD/easyloggingpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
