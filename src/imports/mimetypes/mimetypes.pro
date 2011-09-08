CONFIG   += qt plugin
TEMPLATE = lib
TARGET   = declarative_mimetypes

# QtCore/qlist.h uses /usr/include/limits.h which uses does not compile with -pedantic.
# QtDeclarative/qdeclarativeprivate.h will not compile with -pedantic.
#MAKE_CXXFLAGS += -W -Wall -Wextra -Werror -ansi -pedantic -Wshadow -Wno-long-long -Wnon-virtual-dtor
QMAKE_CXXFLAGS += -W -Wall -Wextra -Werror -ansi           -Wshadow -Wno-long-long -Wnon-virtual-dtor
mac|darwin: {
} else {
    QMAKE_CXXFLAGS += -Wc++0x-compat
}

# dependency management
QMAKE_CXXFLAGS += -MMD
include_dependencies.target = include_dependencies
include_dependencies.commands = @if grep \"^-include \\*.d\" Makefile >/dev/null 2>&1; then echo \"Dependency files are already included.\"; else echo \"-include *.d\" >> Makefile; echo \"Please rerun make because dependency files will be included next time.\"; fi
QMAKE_EXTRA_TARGETS += include_dependencies
POST_TARGETDEPS += include_dependencies

LIBS += -L ../../mimetypes -lQtAddOnMimeTypes


API_DIR = ../../..

INCLUDEPATH += $$API_DIR/src/mimetypes


SOURCES += $$API_DIR/src/imports/mimetypes/mimetypes.cpp

# No headers


SOURCES += $$API_DIR/src/imports/mimetypes/qdeclarativemimetype.cpp \
           $$API_DIR/src/imports/mimetypes/qdeclarativemimetyperegistry.cpp \
           $$API_DIR/src/imports/mimetypes/qdeclarativeserviceaction.cpp

HEADERS += $$API_DIR/src/imports/mimetypes/qdeclarativemimetype_p.h \
           $$API_DIR/src/imports/mimetypes/qdeclarativemimetyperegistry_p.h \
           $$API_DIR/src/imports/mimetypes/qdeclarativeserviceaction_p.h


qmldir.files += $$PWD/qmldir


INSTALLS += qmldir target
