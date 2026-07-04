set(EDITOR_SOURCES
    main.cpp
    ImageProcessor.cpp
    biomemapgeneratorDialog.cpp
    exportlotsprogressdialog.cpp
    generatelotsfailuredialog.cpp
    loadthumbnailsdialog.cpp
    logger.cpp
    lotfilesmanager256.cpp
    mainwindow.cpp
    InGameMap/clipper.cpp
    InGameMap/ingamemapcell.cpp
    InGameMap/ingamemapdock.cpp
    InGameMap/ingamemapfeaturegenerator.cpp
    InGameMap/ingamemapimagepyramidwindow.cpp
    InGameMap/ingamemappropertiesform.cpp
    InGameMap/ingamemappropertydialog.cpp
    InGameMap/ingamemapreader.cpp
    InGameMap/ingamemapscene.cpp
    InGameMap/ingamemapundo.cpp
    InGameMap/ingamemapwriter.cpp
    InGameMap/ingamemapwriterbinary.cpp
    navigation/chunkdatafile256.cpp
    navigation/isogridsquare256.cpp
    tilesetstxtfile.cpp
    worldview.cpp
    worldscene.cpp
    world.cpp
    worlddocument.cpp
    worldcell.cpp
    cellview.cpp
    cellscene.cpp
    document.cpp
    documentmanager.cpp
    celldocument.cpp
    mapcomposite.cpp
    mapsdock.cpp
    preferences.cpp
    mapimagemanager.cpp
    undoredo.cpp
    undodock.cpp
    mapmanager.cpp
    basegraphicsview.cpp
    progress.cpp
    zoomable.cpp
    scenetools.cpp
    worldwriter.cpp
    worldreader.cpp
    propertiesdock.cpp
    propertydefinitionsdialog.cpp
    templatesdialog.cpp
    basegraphicsscene.cpp
    lotsdock.cpp
    worldcellobject.cpp
    objectsdock.cpp
    toolmanager.cpp
    properties.cpp
    objecttypesdialog.cpp
    luatablewriter.cpp
    luawriter.cpp
    layersmodel.cpp
    layersdock.cpp
    preferencesdialog.cpp
    objectgroupsdialog.cpp
    colorbutton.cpp
    copypastedialog.cpp
    clipboard.cpp
    lotfilesmanager.cpp
    road.cpp
    roadsdock.cpp
    simplefile.cpp
    bmptotmx.cpp
    bmptotmxdialog.cpp
    generatelotsdialog.cpp
    filesystemwatcher.cpp
    bmptotmxconfirmdialog.cpp
    resizeworlddialog.cpp
    newworlddialog.cpp
    tilemetainfomgr.cpp
    tilesetmanager.cpp
    BuildingEditor/furnituregroups.cpp
    BuildingEditor/buildingtmx.cpp
    BuildingEditor/buildingtiles.cpp
    BuildingEditor/buildingobjects.cpp
    BuildingEditor/buildingmap.cpp
    BuildingEditor/buildingfloor.cpp
    BuildingEditor/building.cpp
    BuildingEditor/buildingwriter.cpp
    BuildingEditor/buildingreader.cpp
    BuildingEditor/buildingroomdef.cpp
    BuildingEditor/buildingtemplates.cpp
    BuildingEditor/roofhiding.cpp
    threads.cpp
    bmpblender.cpp
    lotpackwindow.cpp
    chunkmap.cpp
    fromtodialog.cpp
    unknowncolorsdialog.cpp
    gotodialog.cpp
    spawntooldialog.cpp
    propertyenumdialog.cpp
    writespawnpointsdialog.cpp
    mapbuildings.cpp
    pngbuildingdialog.cpp
    tiledeffile.cpp
    lootwindow.cpp
    sceneoverlay.cpp
    writeworldobjectsdialog.cpp
    tmxtobmp.cpp
    tmxtobmpdialog.cpp
    navigation/isochunk.cpp
    navigation/isogridsquare.cpp
    navigation/chunkdatafile.cpp
    searchdock.cpp
    defaultsfile.cpp
    waterflow.cpp
    # Header-only Q_OBJECT classes (AUTOMOC needs them listed)
    pngzonesdialog.h
    writeroomtonesdialog.h
    InGameMap/ingamemapimagedialog.h
    # Qt resource and UI files
    editor.qrc
    # UI forms (AUTOUIC handles these when listed as sources)
    mainwindow.ui
    biomemapgenerator.ui
    generatelotsfailuredialog.ui
    InGameMap/ingamemapimagepyramidwindow.ui
    InGameMap/ingamemappropertiesform.ui
    InGameMap/ingamemappropertydialog.ui
    loadthumbnailsdialog.ui
    propertiesview.ui
    propertiesdialog.ui
    templatesdialog.ui
    objecttypesdialog.ui
    preferencesdialog.ui
    objectgroupsdialog.ui
    copypastedialog.ui
    bmptotmxdialog.ui
    generatelotsdialog.ui
    bmptotmxconfirmdialog.ui
    resizeworlddialog.ui
    newworlddialog.ui
    lotpackwindow.ui
    fromtodialog.ui
    unknowncolorsdialog.ui
    gotodialog.ui
    spawntooldialog.ui
    propertyenumdialog.ui
    writespawnpointsdialog.ui
    pngbuildingdialog.ui
    lootwindow.ui
    writeworldobjectsdialog.ui
    tmxtobmpdialog.ui
    searchdock.ui
)

set_property(DIRECTORY PROPERTY AUTOUIC_SEARCH_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/InGameMap
    ${CMAKE_CURRENT_SOURCE_DIR}/BuildingEditor
    ${CMAKE_CURRENT_SOURCE_DIR}/navigation
)

qt_add_executable(PZWorldEd ${EDITOR_SOURCES})

target_include_directories(PZWorldEd PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/InGameMap
    ${CMAKE_CURRENT_SOURCE_DIR}/BuildingEditor
    ${CMAKE_CURRENT_SOURCE_DIR}/navigation
)

target_compile_definitions(PZWorldEd PRIVATE
    QT_NO_CAST_FROM_ASCII
    QT_NO_CAST_TO_ASCII
)

find_package(Qt6 REQUIRED COMPONENTS OpenGL OpenGLWidgets)

target_link_libraries(PZWorldEd PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Xml
    Qt6::OpenGL
    Qt6::OpenGLWidgets
    tiled
    quazip
    lua
    qtlockedfile
    zlib
)

# Windows-specific: embed icon and version info
if(WIN32)
    target_sources(PZWorldEd PRIVATE worlded.rc)
endif()

# macOS: make it a proper app bundle
if(APPLE)
    set_target_properties(PZWorldEd PROPERTIES MACOSX_BUNDLE TRUE)
endif()
