#include "MessageEdit.h"

MessageEdit::MessageEdit(QWidget *parent)
: QPlainTextEdit(parent) {
    setLineCount(1);
    connect(this, SIGNAL(textChanged()), this, SLOT(sizeToFit()));
}

void MessageEdit::sizeToFit() {
    QSize size = document()->documentLayout()->documentSize().toSize();
    setLineCount(size.height());
}

void MessageEdit::setLineCount(int rows) {
    int max = 10;
    rows = rows < 2?   1:   rows;
    rows = rows > max? max: rows;
    QFontMetrics m(font());
    int pad = 12;
    int s = m.lineSpacing();
    int h = pad + rows * s;
    setFixedHeight(h);
}
