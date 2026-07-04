#include "chunkdatafile256.h"
#include "../lotfilesmanager.h"
#include "../lotfilesmanager256.h"
#include "../world.h"

#include <QDataStream>
#include <QDebug>
#include <QFile>

namespace Navigate {

ChunkDataFile256::ChunkDataFile256() {}

void ChunkDataFile256::fromMap(CombinedCellMaps &combinedMaps, MapComposite *, LotFile::RectLookup<LotFile::RoomRect> &, const GenerateLotsSettings &settings)
{
    QString lotsDirectory = settings.exportDir;
    QString filePath = lotsDirectory + QString::fromLatin1("/chunkdata_%1_%2.bin")
               .arg(combinedMaps.mCell256X).arg(combinedMaps.mCell256Y);
    qDebug() << "ChunkDataFile256::fromMap path=" << filePath;
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "ChunkDataFile256::fromMap FAILED to open:" << file.errorString();
        return;
    }
    qDebug() << "ChunkDataFile256::fromMap opened OK";

    QDataStream out(&file); // BigEndian by default, Java DataInputStream also BigEndian

    int FILE_VERSION = 1;
    out << qint16(FILE_VERSION);

    const int REGULAR_CHUNK = 2;
    const quint8 DEFAULT_BITS = 4;

    quint8 bitsArray[CHUNK_SIZE_256 * CHUNK_SIZE_256];
    for (int i = 0; i < CHUNK_SIZE_256 * CHUNK_SIZE_256; i++)
        bitsArray[i] = DEFAULT_BITS;

    for (int yy = 0; yy < CHUNKS_PER_CELL_256; yy++) {
        for (int xx = 0; xx < CHUNKS_PER_CELL_256; xx++) {
            out << quint8(REGULAR_CHUNK);
            for (int i = 0; i < CHUNK_SIZE_256 * CHUNK_SIZE_256; i++)
                out << bitsArray[i];
        }
    }

    file.close();
}

} // namespace Navigate
