

#define protected public
#define private public

#include "moc.h"
#include "_cgo_export.h"

#include <QByteArray>
#include <QChildEvent>
#include <QColor>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QEvent>
#include <QFocusEvent>
#include <QHoverEvent>
#include <QInputMethodEvent>
#include <QKeyEvent>
#include <QMetaMethod>
#include <QMouseEvent>
#include <QObject>
#include <QPainter>
#include <QPointF>
#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QQuickWindow>
#include <QRectF>
#include <QSGTextureProvider>
#include <QString>
#include <QTimerEvent>
#include <QTouchEvent>
#include <QVariant>
#include <QVector>
#include <QWheelEvent>

#ifdef QT_QML_LIB
	#include <QQmlEngine>
#endif


class PathPainter5d80a6: public QQuickPaintedItem
{
Q_OBJECT
Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
public:
	PathPainter5d80a6(QQuickItem *parent = Q_NULLPTR) : QQuickPaintedItem(parent) {qRegisterMetaType<quintptr>("quintptr");PathPainter5d80a6_PathPainter5d80a6_QRegisterMetaType();PathPainter5d80a6_PathPainter5d80a6_QRegisterMetaTypes();callbackPathPainter5d80a6_Constructor(this);};
	QString name() { return ({ Moc_PackedString tempVal = callbackPathPainter5d80a6_Name(this); QString ret = QString::fromUtf8(tempVal.data, tempVal.len); free(tempVal.data); ret; }); };
	void setName(QString name) { QByteArray* t6ae999 = new QByteArray(name.toUtf8()); Moc_PackedString namePacked = { const_cast<char*>(t6ae999->prepend("WHITESPACE").constData()+10), t6ae999->size()-10, t6ae999 };callbackPathPainter5d80a6_SetName(this, namePacked); };
	void Signal_NameChanged(QString name) { QByteArray* t6ae999 = new QByteArray(name.toUtf8()); Moc_PackedString namePacked = { const_cast<char*>(t6ae999->prepend("WHITESPACE").constData()+10), t6ae999->size()-10, t6ae999 };callbackPathPainter5d80a6_NameChanged(this, namePacked); };
	QColor color() { return *static_cast<QColor*>(callbackPathPainter5d80a6_Color(this)); };
	void setColor(QColor color) { callbackPathPainter5d80a6_SetColor(this, new QColor(color)); };
	void Signal_ColorChanged(QColor color) { callbackPathPainter5d80a6_ColorChanged(this, new QColor(color)); };
	 ~PathPainter5d80a6() { callbackPathPainter5d80a6_DestroyPathPainter(this); };
	void Signal_ContentsScaleChanged() { callbackPathPainter5d80a6_ContentsScaleChanged(this); };
	void Signal_ContentsSizeChanged() { callbackPathPainter5d80a6_ContentsSizeChanged(this); };
	void Signal_FillColorChanged() { callbackPathPainter5d80a6_FillColorChanged(this); };
	void paint(QPainter * painter) { callbackPathPainter5d80a6_Paint(this, painter); };
	void releaseResources() { callbackPathPainter5d80a6_ReleaseResources(this); };
	void Signal_RenderTargetChanged() { callbackPathPainter5d80a6_RenderTargetChanged(this); };
	void Signal_TextureSizeChanged() { callbackPathPainter5d80a6_TextureSizeChanged(this); };
	QSGTextureProvider * textureProvider() const { return static_cast<QSGTextureProvider*>(callbackPathPainter5d80a6_TextureProvider(const_cast<void*>(static_cast<const void*>(this)))); };
	bool isTextureProvider() const { return callbackPathPainter5d80a6_IsTextureProvider(const_cast<void*>(static_cast<const void*>(this))) != 0; };
	bool childMouseEventFilter(QQuickItem * item, QEvent * event) { return callbackPathPainter5d80a6_ChildMouseEventFilter(this, item, event) != 0; };
	bool event(QEvent * ev) { return callbackPathPainter5d80a6_Event(this, ev) != 0; };
	void classBegin() { callbackPathPainter5d80a6_ClassBegin(this); };
	void componentComplete() { callbackPathPainter5d80a6_ComponentComplete(this); };
	void Signal_ContainmentMaskChanged() { callbackPathPainter5d80a6_ContainmentMaskChanged(this); };
	void dragEnterEvent(QDragEnterEvent * event) { callbackPathPainter5d80a6_DragEnterEvent(this, event); };
	void dragLeaveEvent(QDragLeaveEvent * event) { callbackPathPainter5d80a6_DragLeaveEvent(this, event); };
	void dragMoveEvent(QDragMoveEvent * event) { callbackPathPainter5d80a6_DragMoveEvent(this, event); };
	void dropEvent(QDropEvent * event) { callbackPathPainter5d80a6_DropEvent(this, event); };
	void focusInEvent(QFocusEvent * vqf) { callbackPathPainter5d80a6_FocusInEvent(this, vqf); };
	void focusOutEvent(QFocusEvent * vqf) { callbackPathPainter5d80a6_FocusOutEvent(this, vqf); };
	void geometryChanged(const QRectF & newGeometry, const QRectF & oldGeometry) { callbackPathPainter5d80a6_GeometryChanged(this, const_cast<QRectF*>(&newGeometry), const_cast<QRectF*>(&oldGeometry)); };
	void hoverEnterEvent(QHoverEvent * event) { callbackPathPainter5d80a6_HoverEnterEvent(this, event); };
	void hoverLeaveEvent(QHoverEvent * event) { callbackPathPainter5d80a6_HoverLeaveEvent(this, event); };
	void hoverMoveEvent(QHoverEvent * event) { callbackPathPainter5d80a6_HoverMoveEvent(this, event); };
	void inputMethodEvent(QInputMethodEvent * event) { callbackPathPainter5d80a6_InputMethodEvent(this, event); };
	void keyPressEvent(QKeyEvent * event) { callbackPathPainter5d80a6_KeyPressEvent(this, event); };
	void keyReleaseEvent(QKeyEvent * event) { callbackPathPainter5d80a6_KeyReleaseEvent(this, event); };
	void mouseDoubleClickEvent(QMouseEvent * event) { callbackPathPainter5d80a6_MouseDoubleClickEvent(this, event); };
	void mouseMoveEvent(QMouseEvent * event) { callbackPathPainter5d80a6_MouseMoveEvent(this, event); };
	void mousePressEvent(QMouseEvent * event) { callbackPathPainter5d80a6_MousePressEvent(this, event); };
	void mouseReleaseEvent(QMouseEvent * event) { callbackPathPainter5d80a6_MouseReleaseEvent(this, event); };
	void mouseUngrabEvent() { callbackPathPainter5d80a6_MouseUngrabEvent(this); };
	void touchEvent(QTouchEvent * event) { callbackPathPainter5d80a6_TouchEvent(this, event); };
	void touchUngrabEvent() { callbackPathPainter5d80a6_TouchUngrabEvent(this); };
	void updatePolish() { callbackPathPainter5d80a6_UpdatePolish(this); };
	void wheelEvent(QWheelEvent * event) { callbackPathPainter5d80a6_WheelEvent(this, event); };
	void Signal_WindowChanged(QQuickWindow * window) { callbackPathPainter5d80a6_WindowChanged(this, window); };
	QVariant inputMethodQuery(Qt::InputMethodQuery query) const { return *static_cast<QVariant*>(callbackPathPainter5d80a6_InputMethodQuery(const_cast<void*>(static_cast<const void*>(this)), query)); };
	bool contains(const QPointF & point) const { return callbackPathPainter5d80a6_Contains(const_cast<void*>(static_cast<const void*>(this)), const_cast<QPointF*>(&point)) != 0; };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackPathPainter5d80a6_EventFilter(this, watched, event) != 0; };
	void childEvent(QChildEvent * event) { callbackPathPainter5d80a6_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackPathPainter5d80a6_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackPathPainter5d80a6_CustomEvent(this, event); };
	void deleteLater() { callbackPathPainter5d80a6_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackPathPainter5d80a6_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackPathPainter5d80a6_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray* taa2c4f = new QByteArray(objectName.toUtf8()); Moc_PackedString objectNamePacked = { const_cast<char*>(taa2c4f->prepend("WHITESPACE").constData()+10), taa2c4f->size()-10, taa2c4f };callbackPathPainter5d80a6_ObjectNameChanged(this, objectNamePacked); };
	void timerEvent(QTimerEvent * event) { callbackPathPainter5d80a6_TimerEvent(this, event); };
	QString nameDefault() { return _name; };
	void setNameDefault(QString p) { if (p != _name) { _name = p; nameChanged(_name); } };
	QColor colorDefault() { return _color; };
	void setColorDefault(QColor p) { if (p != _color) { _color = p; colorChanged(_color); } };
signals:
	void nameChanged(QString name);
	void colorChanged(QColor color);
public slots:
private:
	QString _name;
	QColor _color;
};

Q_DECLARE_METATYPE(PathPainter5d80a6*)


void PathPainter5d80a6_PathPainter5d80a6_QRegisterMetaTypes() {
	qRegisterMetaType<QString>();
	qRegisterMetaType<QColor>();
}

struct Moc_PackedString PathPainter5d80a6_Name(void* ptr)
{
	return ({ QByteArray* t65a13c = new QByteArray(static_cast<PathPainter5d80a6*>(ptr)->name().toUtf8()); Moc_PackedString { const_cast<char*>(t65a13c->prepend("WHITESPACE").constData()+10), t65a13c->size()-10, t65a13c }; });
}

struct Moc_PackedString PathPainter5d80a6_NameDefault(void* ptr)
{
	return ({ QByteArray* t4d8b72 = new QByteArray(static_cast<PathPainter5d80a6*>(ptr)->nameDefault().toUtf8()); Moc_PackedString { const_cast<char*>(t4d8b72->prepend("WHITESPACE").constData()+10), t4d8b72->size()-10, t4d8b72 }; });
}

void PathPainter5d80a6_SetName(void* ptr, struct Moc_PackedString name)
{
	static_cast<PathPainter5d80a6*>(ptr)->setName(QString::fromUtf8(name.data, name.len));
}

void PathPainter5d80a6_SetNameDefault(void* ptr, struct Moc_PackedString name)
{
	static_cast<PathPainter5d80a6*>(ptr)->setNameDefault(QString::fromUtf8(name.data, name.len));
}

void PathPainter5d80a6_ConnectNameChanged(void* ptr, long long t)
{
	QObject::connect(static_cast<PathPainter5d80a6*>(ptr), static_cast<void (PathPainter5d80a6::*)(QString)>(&PathPainter5d80a6::nameChanged), static_cast<PathPainter5d80a6*>(ptr), static_cast<void (PathPainter5d80a6::*)(QString)>(&PathPainter5d80a6::Signal_NameChanged), static_cast<Qt::ConnectionType>(t));
}

void PathPainter5d80a6_DisconnectNameChanged(void* ptr)
{
	QObject::disconnect(static_cast<PathPainter5d80a6*>(ptr), static_cast<void (PathPainter5d80a6::*)(QString)>(&PathPainter5d80a6::nameChanged), static_cast<PathPainter5d80a6*>(ptr), static_cast<void (PathPainter5d80a6::*)(QString)>(&PathPainter5d80a6::Signal_NameChanged));
}

void PathPainter5d80a6_NameChanged(void* ptr, struct Moc_PackedString name)
{
	static_cast<PathPainter5d80a6*>(ptr)->nameChanged(QString::fromUtf8(name.data, name.len));
}

void* PathPainter5d80a6_Color(void* ptr)
{
	return new QColor(static_cast<PathPainter5d80a6*>(ptr)->color());
}

void* PathPainter5d80a6_ColorDefault(void* ptr)
{
	return new QColor(static_cast<PathPainter5d80a6*>(ptr)->colorDefault());
}

void PathPainter5d80a6_SetColor(void* ptr, void* color)
{
	static_cast<PathPainter5d80a6*>(ptr)->setColor(*static_cast<QColor*>(color));
}

void PathPainter5d80a6_SetColorDefault(void* ptr, void* color)
{
	static_cast<PathPainter5d80a6*>(ptr)->setColorDefault(*static_cast<QColor*>(color));
}

void PathPainter5d80a6_ConnectColorChanged(void* ptr, long long t)
{
	QObject::connect(static_cast<PathPainter5d80a6*>(ptr), static_cast<void (PathPainter5d80a6::*)(QColor)>(&PathPainter5d80a6::colorChanged), static_cast<PathPainter5d80a6*>(ptr), static_cast<void (PathPainter5d80a6::*)(QColor)>(&PathPainter5d80a6::Signal_ColorChanged), static_cast<Qt::ConnectionType>(t));
}

void PathPainter5d80a6_DisconnectColorChanged(void* ptr)
{
	QObject::disconnect(static_cast<PathPainter5d80a6*>(ptr), static_cast<void (PathPainter5d80a6::*)(QColor)>(&PathPainter5d80a6::colorChanged), static_cast<PathPainter5d80a6*>(ptr), static_cast<void (PathPainter5d80a6::*)(QColor)>(&PathPainter5d80a6::Signal_ColorChanged));
}

void PathPainter5d80a6_ColorChanged(void* ptr, void* color)
{
	static_cast<PathPainter5d80a6*>(ptr)->colorChanged(*static_cast<QColor*>(color));
}

int PathPainter5d80a6_PathPainter5d80a6_QRegisterMetaType()
{
	return qRegisterMetaType<PathPainter5d80a6*>();
}

int PathPainter5d80a6_PathPainter5d80a6_QRegisterMetaType2(char* typeName)
{
	return qRegisterMetaType<PathPainter5d80a6*>(const_cast<const char*>(typeName));
}

int PathPainter5d80a6_PathPainter5d80a6_QmlRegisterType()
{
#ifdef QT_QML_LIB
	return qmlRegisterType<PathPainter5d80a6>();
#else
	return 0;
#endif
}

int PathPainter5d80a6_PathPainter5d80a6_QmlRegisterType2(char* uri, int versionMajor, int versionMinor, char* qmlName)
{
#ifdef QT_QML_LIB
	return qmlRegisterType<PathPainter5d80a6>(const_cast<const char*>(uri), versionMajor, versionMinor, const_cast<const char*>(qmlName));
#else
	return 0;
#endif
}

int PathPainter5d80a6_PathPainter5d80a6_QmlRegisterUncreatableType(char* uri, int versionMajor, int versionMinor, char* qmlName, struct Moc_PackedString message)
{
#ifdef QT_QML_LIB
	return qmlRegisterUncreatableType<PathPainter5d80a6>(const_cast<const char*>(uri), versionMajor, versionMinor, const_cast<const char*>(qmlName), QString::fromUtf8(message.data, message.len));
#else
	return 0;
#endif
}

int PathPainter5d80a6___grabTouchPoints_ids_atList(void* ptr, int i)
{
	return ({int tmp = static_cast<QVector<int>*>(ptr)->at(i); if (i == static_cast<QVector<int>*>(ptr)->size()-1) { static_cast<QVector<int>*>(ptr)->~QVector(); free(ptr); }; tmp; });
}

void PathPainter5d80a6___grabTouchPoints_ids_setList(void* ptr, int i)
{
	static_cast<QVector<int>*>(ptr)->append(i);
}

void* PathPainter5d80a6___grabTouchPoints_ids_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QVector<int>();
}

void* PathPainter5d80a6___childItems_atList(void* ptr, int i)
{
	return ({QQuickItem * tmp = static_cast<QList<QQuickItem *>*>(ptr)->at(i); if (i == static_cast<QList<QQuickItem *>*>(ptr)->size()-1) { static_cast<QList<QQuickItem *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void PathPainter5d80a6___childItems_setList(void* ptr, void* i)
{
	static_cast<QList<QQuickItem *>*>(ptr)->append(static_cast<QQuickItem*>(i));
}

void* PathPainter5d80a6___childItems_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QQuickItem *>();
}

void* PathPainter5d80a6___dynamicPropertyNames_atList(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void PathPainter5d80a6___dynamicPropertyNames_setList(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* PathPainter5d80a6___dynamicPropertyNames_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

void* PathPainter5d80a6___findChildren_atList2(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void PathPainter5d80a6___findChildren_setList2(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* PathPainter5d80a6___findChildren_newList2(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* PathPainter5d80a6___findChildren_atList3(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void PathPainter5d80a6___findChildren_setList3(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* PathPainter5d80a6___findChildren_newList3(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* PathPainter5d80a6___findChildren_atList(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void PathPainter5d80a6___findChildren_setList(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* PathPainter5d80a6___findChildren_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* PathPainter5d80a6___children_atList(void* ptr, int i)
{
	return ({QObject * tmp = static_cast<QList<QObject *>*>(ptr)->at(i); if (i == static_cast<QList<QObject *>*>(ptr)->size()-1) { static_cast<QList<QObject *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void PathPainter5d80a6___children_setList(void* ptr, void* i)
{
	static_cast<QList<QObject *>*>(ptr)->append(static_cast<QObject*>(i));
}

void* PathPainter5d80a6___children_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject *>();
}

void* PathPainter5d80a6_NewPathPainter(void* parent)
{
		return new PathPainter5d80a6(static_cast<QQuickItem*>(parent));
}

void PathPainter5d80a6_DestroyPathPainter(void* ptr)
{
	static_cast<PathPainter5d80a6*>(ptr)->~PathPainter5d80a6();
}

void PathPainter5d80a6_DestroyPathPainterDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

void PathPainter5d80a6_Paint(void* ptr, void* painter)
{
	Q_UNUSED(ptr);
	Q_UNUSED(painter);

}

void PathPainter5d80a6_PaintDefault(void* ptr, void* painter)
{
	Q_UNUSED(ptr);
	Q_UNUSED(painter);

}

void PathPainter5d80a6_ReleaseResourcesDefault(void* ptr)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::releaseResources();
}

void* PathPainter5d80a6_TextureProviderDefault(void* ptr)
{
	return static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::textureProvider();
}

char PathPainter5d80a6_IsTextureProviderDefault(void* ptr)
{
	return static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::isTextureProvider();
}



char PathPainter5d80a6_ChildMouseEventFilterDefault(void* ptr, void* item, void* event)
{
	return static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::childMouseEventFilter(static_cast<QQuickItem*>(item), static_cast<QEvent*>(event));
}

char PathPainter5d80a6_EventDefault(void* ptr, void* ev)
{
	return static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::event(static_cast<QEvent*>(ev));
}

void PathPainter5d80a6_ClassBeginDefault(void* ptr)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::classBegin();
}

void PathPainter5d80a6_ComponentCompleteDefault(void* ptr)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::componentComplete();
}

void PathPainter5d80a6_DragEnterEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::dragEnterEvent(static_cast<QDragEnterEvent*>(event));
}

void PathPainter5d80a6_DragLeaveEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::dragLeaveEvent(static_cast<QDragLeaveEvent*>(event));
}

void PathPainter5d80a6_DragMoveEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::dragMoveEvent(static_cast<QDragMoveEvent*>(event));
}

void PathPainter5d80a6_DropEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::dropEvent(static_cast<QDropEvent*>(event));
}

void PathPainter5d80a6_FocusInEventDefault(void* ptr, void* vqf)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::focusInEvent(static_cast<QFocusEvent*>(vqf));
}

void PathPainter5d80a6_FocusOutEventDefault(void* ptr, void* vqf)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::focusOutEvent(static_cast<QFocusEvent*>(vqf));
}

void PathPainter5d80a6_GeometryChangedDefault(void* ptr, void* newGeometry, void* oldGeometry)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::geometryChanged(*static_cast<QRectF*>(newGeometry), *static_cast<QRectF*>(oldGeometry));
}

void PathPainter5d80a6_HoverEnterEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::hoverEnterEvent(static_cast<QHoverEvent*>(event));
}

void PathPainter5d80a6_HoverLeaveEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::hoverLeaveEvent(static_cast<QHoverEvent*>(event));
}

void PathPainter5d80a6_HoverMoveEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::hoverMoveEvent(static_cast<QHoverEvent*>(event));
}

void PathPainter5d80a6_InputMethodEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::inputMethodEvent(static_cast<QInputMethodEvent*>(event));
}

void PathPainter5d80a6_KeyPressEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::keyPressEvent(static_cast<QKeyEvent*>(event));
}

void PathPainter5d80a6_KeyReleaseEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::keyReleaseEvent(static_cast<QKeyEvent*>(event));
}

void PathPainter5d80a6_MouseDoubleClickEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::mouseDoubleClickEvent(static_cast<QMouseEvent*>(event));
}

void PathPainter5d80a6_MouseMoveEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::mouseMoveEvent(static_cast<QMouseEvent*>(event));
}

void PathPainter5d80a6_MousePressEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::mousePressEvent(static_cast<QMouseEvent*>(event));
}

void PathPainter5d80a6_MouseReleaseEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::mouseReleaseEvent(static_cast<QMouseEvent*>(event));
}

void PathPainter5d80a6_MouseUngrabEventDefault(void* ptr)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::mouseUngrabEvent();
}

void PathPainter5d80a6_TouchEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::touchEvent(static_cast<QTouchEvent*>(event));
}

void PathPainter5d80a6_TouchUngrabEventDefault(void* ptr)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::touchUngrabEvent();
}

void PathPainter5d80a6_UpdatePolishDefault(void* ptr)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::updatePolish();
}

void PathPainter5d80a6_WheelEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::wheelEvent(static_cast<QWheelEvent*>(event));
}

void* PathPainter5d80a6_InputMethodQueryDefault(void* ptr, long long query)
{
	return new QVariant(static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::inputMethodQuery(static_cast<Qt::InputMethodQuery>(query)));
}

char PathPainter5d80a6_ContainsDefault(void* ptr, void* point)
{
	return static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::contains(*static_cast<QPointF*>(point));
}

char PathPainter5d80a6_EventFilterDefault(void* ptr, void* watched, void* event)
{
	return static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

void PathPainter5d80a6_ChildEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::childEvent(static_cast<QChildEvent*>(event));
}

void PathPainter5d80a6_ConnectNotifyDefault(void* ptr, void* sign)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::connectNotify(*static_cast<QMetaMethod*>(sign));
}

void PathPainter5d80a6_CustomEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::customEvent(static_cast<QEvent*>(event));
}

void PathPainter5d80a6_DeleteLaterDefault(void* ptr)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::deleteLater();
}

void PathPainter5d80a6_DisconnectNotifyDefault(void* ptr, void* sign)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::disconnectNotify(*static_cast<QMetaMethod*>(sign));
}

void PathPainter5d80a6_TimerEventDefault(void* ptr, void* event)
{
	static_cast<PathPainter5d80a6*>(ptr)->QQuickPaintedItem::timerEvent(static_cast<QTimerEvent*>(event));
}

#include "moc_moc.h"
