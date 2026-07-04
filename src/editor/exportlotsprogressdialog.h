#ifndef EXPORTLOTSPROGRESSDIALOG_H
#define EXPORTLOTSPROGRESSDIALOG_H

#include <QDialog>
#include <QVector>

class QLabel;
class QPushButton;
class QScrollArea;

class CellGridWidget : public QWidget
{
    Q_OBJECT
public:
    enum class CellStatus { Pending, Failed, Exported, Missing };

    explicit CellGridWidget(QWidget *parent = nullptr);
    void setWorldSize(int w, int h);
    void setCellStatus(int x, int y, CellStatus status);

protected:
    QSize sizeHint() const override;
    void paintEvent(QPaintEvent *) override;

private:
    int mWidth = 0;
    int mHeight = 0;
    QVector<CellStatus> mStatus;
    static const int CELL_PX = 14;
    static const int GAP = 1;
};

class ExportLotsProgressDialog : public QDialog
{
    Q_OBJECT
public:
    using CellStatus = CellGridWidget::CellStatus;

    explicit ExportLotsProgressDialog(QWidget *parent = nullptr);

    void setWorldSize(int w, int h);
    void setPrompt(const QString &text);
    void setCellStatus(int x, int y, CellStatus status);

signals:
    void cancelled();

private:
    CellGridWidget *mGrid;
    QLabel        *mPrompt;
    QPushButton   *mCancelBtn;
    QScrollArea   *mScrollArea;
};

#endif // EXPORTLOTSPROGRESSDIALOG_H
