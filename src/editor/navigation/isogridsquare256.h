#ifndef ISOGRIDSQUARE256_H
#define ISOGRIDSQUARE256_H

#include "tiledeffile.h"
#include <QList>
#include <QString>

class GenerateLotsSettings;

namespace Navigate {

class IsoGridSquare256
{
public:
    static QList<TileDefFile*> mTileDefFiles;
    static bool loadTileDefFiles(const GenerateLotsSettings &settings, QString &error);
};

} // namespace Navigate

#endif // ISOGRIDSQUARE256_H
