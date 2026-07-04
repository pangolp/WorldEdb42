#include "exportlotsprogressdialog.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>

// ---- CellGridWidget --------------------------------------------------------

CellGridWidget::CellGridWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(CELL_PX + GAP, CELL_PX + GAP);
}

void CellGridWidget::setWorldSize(int w, int h)
{
    mWidth  = w;
    mHeight = h;
    mStatus.fill(CellStatus::Pending, w * h);
    int px = w * (CELL_PX + GAP) + GAP;
    int py = h * (CELL_PX + GAP) + GAP;
    setFixedSize(px, py);
    update();
}

void CellGridWidget::setCellStatus(int x, int y, CellStatus status)
{
    if (x < 0 || x >= mWidth || y < 0 || y >= mHeight)
        return;
    mStatus[y * mWidth + x] = status;
    int px = GAP + x * (CELL_PX + GAP);
    int py = GAP + y * (CELL_PX + GAP);
    update(px, py, CELL_PX, CELL_PX);
}

QSize CellGridWidget::sizeHint() const
{
    return QSize(mWidth * (CELL_PX + GAP) + GAP,
                 mHeight * (CELL_PX + GAP) + GAP);
}

void CellGridWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.fillRect(rect(), QColor(40, 40, 40));

    static const QColor colors[] = {
        QColor(120, 120, 120), // Pending  — gray
        QColor(180,  30,  30), // Failed   — red
        QColor( 30, 160,  70), // Exported — green
        QColor( 60,  60,  60), // Missing  — dark
    };

    for (int y = 0; y < mHeight; y++) {
        for (int x = 0; x < mWidth; x++) {
            int s = static_cast<int>(mStatus[y * mWidth + x]);
            int px = GAP + x * (CELL_PX + GAP);
            int py = GAP + y * (CELL_PX + GAP);
            p.fillRect(px, py, CELL_PX, CELL_PX, colors[s]);
        }
    }
}

// ---- ExportLotsProgressDialog ----------------------------------------------

ExportLotsProgressDialog::ExportLotsProgressDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Export Lots Progress"));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    mGrid = new CellGridWidget(this);

    mScrollArea = new QScrollArea(this);
    mScrollArea->setWidget(mGrid);
    mScrollArea->setWidgetResizable(false);
    mScrollArea->setMinimumSize(200, 120);

    mPrompt = new QLabel(this);
    mPrompt->setWordWrap(true);

    mCancelBtn = new QPushButton(tr("Cancel"), this);
    connect(mCancelBtn, &QPushButton::clicked, this, &ExportLotsProgressDialog::cancelled);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addStretch();
    btnLayout->addWidget(mCancelBtn);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(mScrollArea, 1);
    layout->addWidget(mPrompt);
    layout->addLayout(btnLayout);

    resize(400, 350);
}

void ExportLotsProgressDialog::setWorldSize(int w, int h)
{
    mGrid->setWorldSize(w, h);
    // Resize scroll area to fit small worlds, cap at a reasonable maximum
    int desiredW = qMin(w * (CellGridWidget::CELL_PX + CellGridWidget::GAP) + CellGridWidget::GAP + 20, 700);
    int desiredH = qMin(h * (CellGridWidget::CELL_PX + CellGridWidget::GAP) + CellGridWidget::GAP + 20, 500);
    mScrollArea->setMinimumSize(desiredW, desiredH);
    adjustSize();
    QApplication::processEvents();
}

void ExportLotsProgressDialog::setPrompt(const QString &text)
{
    mPrompt->setText(text);
    QApplication::processEvents();
}

void ExportLotsProgressDialog::setCellStatus(int x, int y, CellStatus status)
{
    mGrid->setCellStatus(x, y, status);
    QApplication::processEvents();
}
