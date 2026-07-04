#include "isogridsquare256.h"

namespace Navigate {

QList<TileDefFile*> IsoGridSquare256::mTileDefFiles;

bool IsoGridSquare256::loadTileDefFiles(const GenerateLotsSettings &, QString &)
{
    return true;
}

} // namespace Navigate
