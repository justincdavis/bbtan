QT += widgets
QT += multimedia

CONFIG += gui
CONFIG += c++11

SOURCES += \
    main.cpp \
    vec2d.cpp \
    graphics.cpp \
    vec3d.cpp \
    plugin.cpp \
    balls.cpp \
    world.cpp \
    grid.cpp \
    robot.cpp

HEADERS  += \
    graphics.h \
    vec2d.h \
    graphics.h \
    window.h \
    vec3d.h \
    plugin.h \
    balls.h \
    world.h \
    grid.h \
    robot.h \
    celltype.h

DISTFILES += \
    data/ShortLaser.wav \
    data/comp.png

ASSETS_DIR = data

CONFIG(debug, debug|release) {
    DATADIR = debug/$$ASSETS_DIR
} else {
    DATADIR = release/$$ASSETS_DIR
}

copydata.commands = $(COPY_DIR) \"$$shell_path($$absolute_path("$$ASSETS_DIR", $$_PRO_FILE_PWD_))\" \"$$shell_path($$absolute_path($$DATADIR, $$OUT_PWD))\"
first.depends = $(first) copydata

export(first.depends)
export(copydata.commands)

QMAKE_EXTRA_TARGETS += first copydata
