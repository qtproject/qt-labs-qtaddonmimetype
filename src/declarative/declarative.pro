CONFIG   += qt plugin
TEMPLATE = lib
TARGET   = declarative_mimetypes
DESTDIR  = ../../imports/com/nokia/MimeTypes

# QtCore/qlist.h uses /usr/include/limits.h which uses does not compile with -pedantic.
# QtDeclarative/qdeclarativeprivate.h will not compile with -pedantic.
#MAKE_CXXFLAGS += -W -Wall -Wextra -Werror -ansi -pedantic -Wshadow -Wno-long-long -Wnon-virtual-dtor -Wc++0x-compat
QMAKE_CXXFLAGS += -W -Wall -Wextra -Werror -ansi           -Wshadow -Wno-long-long -Wnon-virtual-dtor -Wc++0x-compat

# dependency management
QMAKE_CXXFLAGS += -MMD
include_dependencies.target = include_dependencies
include_dependencies.commands = @if grep \"^include \\*.d\" Makefile >/dev/null 2>&1; then echo \"Dependency files are already included.\"; else echo \"include *.d\" >> Makefile; echo \"Please rerun make because dependency files will be included next time.\"; fi
QMAKE_EXTRA_TARGETS += include_dependencies
POST_TARGETDEPS += include_dependencies


API_DIR = ../..

INCLUDEPATH += $$API_DIR/src/mimetypes


SOURCES += $$API_DIR/src/declarative/declarative_mimetypes.cpp

HEADERS += $$API_DIR/src/declarative/declarative_mimetypes.h


SOURCES += $$API_DIR/src/declarative/declarativemimetype.cpp \
           $$API_DIR/src/declarative/declarativemimetyperegistry.cpp \
           $$API_DIR/src/declarative/declarativeserviceaction.cpp

HEADERS += $$API_DIR/src/declarative/declarativemimetype_p.h \
           $$API_DIR/src/declarative/declarativemimetyperegistry_p.h \
           $$API_DIR/src/declarative/declarativeserviceaction_p.h


qmldir.files += $$PWD/qmldir
qmldir.path += ../../imports/com/nokia/MimeTypes

INSTALLS += qmldir