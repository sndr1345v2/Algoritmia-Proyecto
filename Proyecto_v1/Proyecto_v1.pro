QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        articulo.cpp \
        cliente.cpp \
        encuesta.cpp \
        main.cpp \
        menu_dialog.cpp \
        principal.cpp \
        venta.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    articulo.h \
    cliente.h \
    encuesta.h \
    menu_dialog.h \
    principal.h \
    venta.h

FORMS += \
    menu_dialog.ui
