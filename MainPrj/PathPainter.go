package main

import (
	"github.com/therecipe/qt/gui"
	"github.com/therecipe/qt/quick"
)

func init() {
	PathPainter_QmlRegisterType2("CustomViews", 1, 0, "PathPainter")
}

type PathPainter struct {
	quick.QQuickPaintedItem

	_ func() `constructor:"init"`

	_ string      `property:"name"`
	_ *gui.QColor `property:"color"`
}

func (p *PathPainter) init() {
	p.ConnectPaint(p.paint)
}

func (p *PathPainter) paint(painter *gui.QPainter) {
	
}