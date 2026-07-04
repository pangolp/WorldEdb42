#ifndef PNGZONESDIALOG_H
#define PNGZONESDIALOG_H

#include <QDialog>

class World;

class PNGZonesDialog : public QDialog
{
    Q_OBJECT
public:
    explicit PNGZonesDialog(World *world, QWidget *parent = nullptr)
        : QDialog(parent) { Q_UNUSED(world); }
};

using PngZonesDialog = PNGZonesDialog;

#endif // PNGZONESDIALOG_H
