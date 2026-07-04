#ifndef WRITEROOMTONESDIALOG_H
#define WRITEROOMTONESDIALOG_H

#include <QDialog>

class WorldDocument;

class WriteRoomTonesDialog : public QDialog
{
    Q_OBJECT
public:
    explicit WriteRoomTonesDialog(WorldDocument *doc, QWidget *parent = nullptr)
        : QDialog(parent) { Q_UNUSED(doc); }
};

#endif // WRITEROOMTONESDIALOG_H
