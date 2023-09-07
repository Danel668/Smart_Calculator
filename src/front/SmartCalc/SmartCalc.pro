QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    credit.cpp \
    main.cpp \
    mainwindow.cpp \
    ../../calc_controlller.c \
    ../../back/c_stack.c \
    ../../back/calculate.c \
    ../../back/input_validation.c \
    ../../back/parser.c \
    ../../back/To_Reverse_Polish_Notation.c \
    plot.cpp \
    qcustomplot.cpp

HEADERS += \
    credit.h \
    mainwindow.h \
    ../../calc_controlller.h \
    ../../back/c_stack.h \
    ../../back/calculate.h \
    ../../back/input_validation.h \
    ../../back/pars.h \
    ../../back/To_Reverse_Polish_Notation.h \
    plot.h \
    qcustomplot.h

FORMS += \
    credit.ui \
    mainwindow.ui \
    plot.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
