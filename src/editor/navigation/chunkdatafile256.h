#ifndef CHUNKDATAFILE256_H
#define CHUNKDATAFILE256_H

class GenerateLotsSettings;
class MapComposite;
class CombinedCellMaps;

namespace LotFile {
class RoomRect;
template <class T> class RectLookup;
}

namespace Navigate {

class ChunkDataFile256
{
public:
    ChunkDataFile256();
    void fromMap(CombinedCellMaps &combinedMaps, MapComposite *mapComposite,
                 LotFile::RectLookup<LotFile::RoomRect> &roomRectLookup,
                 const GenerateLotsSettings &settings);
};

} // namespace Navigate

#endif // CHUNKDATAFILE256_H
