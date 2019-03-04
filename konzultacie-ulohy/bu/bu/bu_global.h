#ifndef BU_GLOBAL_H
#define BU_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BU_LIBRARY)
#  define BUSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BUSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BU_GLOBAL_H
