package main

//#include <stdint.h>
//#include <stdlib.h>
//#include <string.h>
//#include "moc.h"
import "C"
import (
	"strings"
	"unsafe"

	"github.com/therecipe/qt"
	std_core "github.com/therecipe/qt/core"
	std_gui "github.com/therecipe/qt/gui"
	std_quick "github.com/therecipe/qt/quick"
)

func cGoFreePacked(ptr unsafe.Pointer) { std_core.NewQByteArrayFromPointer(ptr).DestroyQByteArray() }
func cGoUnpackString(s C.struct_Moc_PackedString) string {
	defer cGoFreePacked(s.ptr)
	if int(s.len) == -1 {
		return C.GoString(s.data)
	}
	return C.GoStringN(s.data, C.int(s.len))
}
func cGoUnpackBytes(s C.struct_Moc_PackedString) []byte {
	defer cGoFreePacked(s.ptr)
	if int(s.len) == -1 {
		gs := C.GoString(s.data)
		return []byte(gs)
	}
	return C.GoBytes(unsafe.Pointer(s.data), C.int(s.len))
}
func unpackStringList(s string) []string {
	if len(s) == 0 {
		return make([]string, 0)
	}
	return strings.Split(s, "¡¦!")
}

type PathPainter_ITF interface {
	std_quick.QQuickPaintedItem_ITF
	PathPainter_PTR() *PathPainter
}

func (ptr *PathPainter) PathPainter_PTR() *PathPainter {
	return ptr
}

func (ptr *PathPainter) Pointer() unsafe.Pointer {
	if ptr != nil {
		return ptr.QQuickPaintedItem_PTR().Pointer()
	}
	return nil
}

func (ptr *PathPainter) SetPointer(p unsafe.Pointer) {
	if ptr != nil {
		ptr.QQuickPaintedItem_PTR().SetPointer(p)
	}
}

func PointerFromPathPainter(ptr PathPainter_ITF) unsafe.Pointer {
	if ptr != nil {
		return ptr.PathPainter_PTR().Pointer()
	}
	return nil
}

func NewPathPainterFromPointer(ptr unsafe.Pointer) (n *PathPainter) {
	if gPtr, ok := qt.Receive(ptr); !ok {
		n = new(PathPainter)
		n.SetPointer(ptr)
	} else {
		switch deduced := gPtr.(type) {
		case *PathPainter:
			n = deduced

		case *std_quick.QQuickPaintedItem:
			n = &PathPainter{QQuickPaintedItem: *deduced}

		default:
			n = new(PathPainter)
			n.SetPointer(ptr)
		}
	}
	return
}
func (this *PathPainter) Init() { this.init() }

//export callbackPathPainter5d80a6_Constructor
func callbackPathPainter5d80a6_Constructor(ptr unsafe.Pointer) {
	this := NewPathPainterFromPointer(ptr)
	qt.Register(ptr, this)
	this.init()
}

//export callbackPathPainter5d80a6_Name
func callbackPathPainter5d80a6_Name(ptr unsafe.Pointer) C.struct_Moc_PackedString {
	if signal := qt.GetSignal(ptr, "name"); signal != nil {
		tempVal := (*(*func() string)(signal))()
		return C.struct_Moc_PackedString{data: C.CString(tempVal), len: C.longlong(len(tempVal))}
	}
	tempVal := NewPathPainterFromPointer(ptr).NameDefault()
	return C.struct_Moc_PackedString{data: C.CString(tempVal), len: C.longlong(len(tempVal))}
}

func (ptr *PathPainter) ConnectName(f func() string) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "name"); signal != nil {
			f := func() string {
				(*(*func() string)(signal))()
				return f()
			}
			qt.ConnectSignal(ptr.Pointer(), "name", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "name", unsafe.Pointer(&f))
		}
	}
}

func (ptr *PathPainter) DisconnectName() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "name")
	}
}

func (ptr *PathPainter) Name() string {
	if ptr.Pointer() != nil {
		return cGoUnpackString(C.PathPainter5d80a6_Name(ptr.Pointer()))
	}
	return ""
}

func (ptr *PathPainter) NameDefault() string {
	if ptr.Pointer() != nil {
		return cGoUnpackString(C.PathPainter5d80a6_NameDefault(ptr.Pointer()))
	}
	return ""
}

//export callbackPathPainter5d80a6_SetName
func callbackPathPainter5d80a6_SetName(ptr unsafe.Pointer, name C.struct_Moc_PackedString) {
	if signal := qt.GetSignal(ptr, "setName"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(name))
	} else {
		NewPathPainterFromPointer(ptr).SetNameDefault(cGoUnpackString(name))
	}
}

func (ptr *PathPainter) ConnectSetName(f func(name string)) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "setName"); signal != nil {
			f := func(name string) {
				(*(*func(string))(signal))(name)
				f(name)
			}
			qt.ConnectSignal(ptr.Pointer(), "setName", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "setName", unsafe.Pointer(&f))
		}
	}
}

func (ptr *PathPainter) DisconnectSetName() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "setName")
	}
}

func (ptr *PathPainter) SetName(name string) {
	if ptr.Pointer() != nil {
		var nameC *C.char
		if name != "" {
			nameC = C.CString(name)
			defer C.free(unsafe.Pointer(nameC))
		}
		C.PathPainter5d80a6_SetName(ptr.Pointer(), C.struct_Moc_PackedString{data: nameC, len: C.longlong(len(name))})
	}
}

func (ptr *PathPainter) SetNameDefault(name string) {
	if ptr.Pointer() != nil {
		var nameC *C.char
		if name != "" {
			nameC = C.CString(name)
			defer C.free(unsafe.Pointer(nameC))
		}
		C.PathPainter5d80a6_SetNameDefault(ptr.Pointer(), C.struct_Moc_PackedString{data: nameC, len: C.longlong(len(name))})
	}
}

//export callbackPathPainter5d80a6_NameChanged
func callbackPathPainter5d80a6_NameChanged(ptr unsafe.Pointer, name C.struct_Moc_PackedString) {
	if signal := qt.GetSignal(ptr, "nameChanged"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(name))
	}

}

func (ptr *PathPainter) ConnectNameChanged(f func(name string)) {
	if ptr.Pointer() != nil {

		if !qt.ExistsSignal(ptr.Pointer(), "nameChanged") {
			C.PathPainter5d80a6_ConnectNameChanged(ptr.Pointer(), C.longlong(qt.ConnectionType(ptr.Pointer(), "nameChanged")))
		}

		if signal := qt.LendSignal(ptr.Pointer(), "nameChanged"); signal != nil {
			f := func(name string) {
				(*(*func(string))(signal))(name)
				f(name)
			}
			qt.ConnectSignal(ptr.Pointer(), "nameChanged", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "nameChanged", unsafe.Pointer(&f))
		}
	}
}

func (ptr *PathPainter) DisconnectNameChanged() {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_DisconnectNameChanged(ptr.Pointer())
		qt.DisconnectSignal(ptr.Pointer(), "nameChanged")
	}
}

func (ptr *PathPainter) NameChanged(name string) {
	if ptr.Pointer() != nil {
		var nameC *C.char
		if name != "" {
			nameC = C.CString(name)
			defer C.free(unsafe.Pointer(nameC))
		}
		C.PathPainter5d80a6_NameChanged(ptr.Pointer(), C.struct_Moc_PackedString{data: nameC, len: C.longlong(len(name))})
	}
}

//export callbackPathPainter5d80a6_Color
func callbackPathPainter5d80a6_Color(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "color"); signal != nil {
		return std_gui.PointerFromQColor((*(*func() *std_gui.QColor)(signal))())
	}

	return std_gui.PointerFromQColor(NewPathPainterFromPointer(ptr).ColorDefault())
}

func (ptr *PathPainter) ConnectColor(f func() *std_gui.QColor) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "color"); signal != nil {
			f := func() *std_gui.QColor {
				(*(*func() *std_gui.QColor)(signal))()
				return f()
			}
			qt.ConnectSignal(ptr.Pointer(), "color", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "color", unsafe.Pointer(&f))
		}
	}
}

func (ptr *PathPainter) DisconnectColor() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "color")
	}
}

func (ptr *PathPainter) Color() *std_gui.QColor {
	if ptr.Pointer() != nil {
		tmpValue := std_gui.NewQColorFromPointer(C.PathPainter5d80a6_Color(ptr.Pointer()))
		qt.SetFinalizer(tmpValue, (*std_gui.QColor).DestroyQColor)
		return tmpValue
	}
	return nil
}

func (ptr *PathPainter) ColorDefault() *std_gui.QColor {
	if ptr.Pointer() != nil {
		tmpValue := std_gui.NewQColorFromPointer(C.PathPainter5d80a6_ColorDefault(ptr.Pointer()))
		qt.SetFinalizer(tmpValue, (*std_gui.QColor).DestroyQColor)
		return tmpValue
	}
	return nil
}

//export callbackPathPainter5d80a6_SetColor
func callbackPathPainter5d80a6_SetColor(ptr unsafe.Pointer, color unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "setColor"); signal != nil {
		(*(*func(*std_gui.QColor))(signal))(func() *std_gui.QColor {
			tmpValue := std_gui.NewQColorFromPointer(color)
			qt.SetFinalizer(tmpValue, (*std_gui.QColor).DestroyQColor)
			return tmpValue
		}())
	} else {
		NewPathPainterFromPointer(ptr).SetColorDefault(func() *std_gui.QColor {
			tmpValue := std_gui.NewQColorFromPointer(color)
			qt.SetFinalizer(tmpValue, (*std_gui.QColor).DestroyQColor)
			return tmpValue
		}())
	}
}

func (ptr *PathPainter) ConnectSetColor(f func(color *std_gui.QColor)) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "setColor"); signal != nil {
			f := func(color *std_gui.QColor) {
				(*(*func(*std_gui.QColor))(signal))(color)
				f(color)
			}
			qt.ConnectSignal(ptr.Pointer(), "setColor", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "setColor", unsafe.Pointer(&f))
		}
	}
}

func (ptr *PathPainter) DisconnectSetColor() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "setColor")
	}
}

func (ptr *PathPainter) SetColor(color std_gui.QColor_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_SetColor(ptr.Pointer(), std_gui.PointerFromQColor(color))
	}
}

func (ptr *PathPainter) SetColorDefault(color std_gui.QColor_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_SetColorDefault(ptr.Pointer(), std_gui.PointerFromQColor(color))
	}
}

//export callbackPathPainter5d80a6_ColorChanged
func callbackPathPainter5d80a6_ColorChanged(ptr unsafe.Pointer, color unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "colorChanged"); signal != nil {
		(*(*func(*std_gui.QColor))(signal))(func() *std_gui.QColor {
			tmpValue := std_gui.NewQColorFromPointer(color)
			qt.SetFinalizer(tmpValue, (*std_gui.QColor).DestroyQColor)
			return tmpValue
		}())
	}

}

func (ptr *PathPainter) ConnectColorChanged(f func(color *std_gui.QColor)) {
	if ptr.Pointer() != nil {

		if !qt.ExistsSignal(ptr.Pointer(), "colorChanged") {
			C.PathPainter5d80a6_ConnectColorChanged(ptr.Pointer(), C.longlong(qt.ConnectionType(ptr.Pointer(), "colorChanged")))
		}

		if signal := qt.LendSignal(ptr.Pointer(), "colorChanged"); signal != nil {
			f := func(color *std_gui.QColor) {
				(*(*func(*std_gui.QColor))(signal))(color)
				f(color)
			}
			qt.ConnectSignal(ptr.Pointer(), "colorChanged", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "colorChanged", unsafe.Pointer(&f))
		}
	}
}

func (ptr *PathPainter) DisconnectColorChanged() {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_DisconnectColorChanged(ptr.Pointer())
		qt.DisconnectSignal(ptr.Pointer(), "colorChanged")
	}
}

func (ptr *PathPainter) ColorChanged(color std_gui.QColor_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_ColorChanged(ptr.Pointer(), std_gui.PointerFromQColor(color))
	}
}

func PathPainter_QRegisterMetaType() int {
	return int(int32(C.PathPainter5d80a6_PathPainter5d80a6_QRegisterMetaType()))
}

func (ptr *PathPainter) QRegisterMetaType() int {
	return int(int32(C.PathPainter5d80a6_PathPainter5d80a6_QRegisterMetaType()))
}

func PathPainter_QRegisterMetaType2(typeName string) int {
	var typeNameC *C.char
	if typeName != "" {
		typeNameC = C.CString(typeName)
		defer C.free(unsafe.Pointer(typeNameC))
	}
	return int(int32(C.PathPainter5d80a6_PathPainter5d80a6_QRegisterMetaType2(typeNameC)))
}

func (ptr *PathPainter) QRegisterMetaType2(typeName string) int {
	var typeNameC *C.char
	if typeName != "" {
		typeNameC = C.CString(typeName)
		defer C.free(unsafe.Pointer(typeNameC))
	}
	return int(int32(C.PathPainter5d80a6_PathPainter5d80a6_QRegisterMetaType2(typeNameC)))
}

func PathPainter_QmlRegisterType() int {
	return int(int32(C.PathPainter5d80a6_PathPainter5d80a6_QmlRegisterType()))
}

func (ptr *PathPainter) QmlRegisterType() int {
	return int(int32(C.PathPainter5d80a6_PathPainter5d80a6_QmlRegisterType()))
}

func PathPainter_QmlRegisterType2(uri string, versionMajor int, versionMinor int, qmlName string) int {
	var uriC *C.char
	if uri != "" {
		uriC = C.CString(uri)
		defer C.free(unsafe.Pointer(uriC))
	}
	var qmlNameC *C.char
	if qmlName != "" {
		qmlNameC = C.CString(qmlName)
		defer C.free(unsafe.Pointer(qmlNameC))
	}
	return int(int32(C.PathPainter5d80a6_PathPainter5d80a6_QmlRegisterType2(uriC, C.int(int32(versionMajor)), C.int(int32(versionMinor)), qmlNameC)))
}

func (ptr *PathPainter) QmlRegisterType2(uri string, versionMajor int, versionMinor int, qmlName string) int {
	var uriC *C.char
	if uri != "" {
		uriC = C.CString(uri)
		defer C.free(unsafe.Pointer(uriC))
	}
	var qmlNameC *C.char
	if qmlName != "" {
		qmlNameC = C.CString(qmlName)
		defer C.free(unsafe.Pointer(qmlNameC))
	}
	return int(int32(C.PathPainter5d80a6_PathPainter5d80a6_QmlRegisterType2(uriC, C.int(int32(versionMajor)), C.int(int32(versionMinor)), qmlNameC)))
}

func PathPainter_QmlRegisterUncreatableType(uri string, versionMajor int, versionMinor int, qmlName string, message string) int {
	var uriC *C.char
	if uri != "" {
		uriC = C.CString(uri)
		defer C.free(unsafe.Pointer(uriC))
	}
	var qmlNameC *C.char
	if qmlName != "" {
		qmlNameC = C.CString(qmlName)
		defer C.free(unsafe.Pointer(qmlNameC))
	}
	var messageC *C.char
	if message != "" {
		messageC = C.CString(message)
		defer C.free(unsafe.Pointer(messageC))
	}
	return int(int32(C.PathPainter5d80a6_PathPainter5d80a6_QmlRegisterUncreatableType(uriC, C.int(int32(versionMajor)), C.int(int32(versionMinor)), qmlNameC, C.struct_Moc_PackedString{data: messageC, len: C.longlong(len(message))})))
}

func (ptr *PathPainter) QmlRegisterUncreatableType(uri string, versionMajor int, versionMinor int, qmlName string, message string) int {
	var uriC *C.char
	if uri != "" {
		uriC = C.CString(uri)
		defer C.free(unsafe.Pointer(uriC))
	}
	var qmlNameC *C.char
	if qmlName != "" {
		qmlNameC = C.CString(qmlName)
		defer C.free(unsafe.Pointer(qmlNameC))
	}
	var messageC *C.char
	if message != "" {
		messageC = C.CString(message)
		defer C.free(unsafe.Pointer(messageC))
	}
	return int(int32(C.PathPainter5d80a6_PathPainter5d80a6_QmlRegisterUncreatableType(uriC, C.int(int32(versionMajor)), C.int(int32(versionMinor)), qmlNameC, C.struct_Moc_PackedString{data: messageC, len: C.longlong(len(message))})))
}

func (ptr *PathPainter) __grabTouchPoints_ids_atList(i int) int {
	if ptr.Pointer() != nil {
		return int(int32(C.PathPainter5d80a6___grabTouchPoints_ids_atList(ptr.Pointer(), C.int(int32(i)))))
	}
	return 0
}

func (ptr *PathPainter) __grabTouchPoints_ids_setList(i int) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6___grabTouchPoints_ids_setList(ptr.Pointer(), C.int(int32(i)))
	}
}

func (ptr *PathPainter) __grabTouchPoints_ids_newList() unsafe.Pointer {
	return C.PathPainter5d80a6___grabTouchPoints_ids_newList(ptr.Pointer())
}

func (ptr *PathPainter) __childItems_atList(i int) *std_quick.QQuickItem {
	if ptr.Pointer() != nil {
		tmpValue := std_quick.NewQQuickItemFromPointer(C.PathPainter5d80a6___childItems_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *PathPainter) __childItems_setList(i std_quick.QQuickItem_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6___childItems_setList(ptr.Pointer(), std_quick.PointerFromQQuickItem(i))
	}
}

func (ptr *PathPainter) __childItems_newList() unsafe.Pointer {
	return C.PathPainter5d80a6___childItems_newList(ptr.Pointer())
}

func (ptr *PathPainter) __dynamicPropertyNames_atList(i int) *std_core.QByteArray {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQByteArrayFromPointer(C.PathPainter5d80a6___dynamicPropertyNames_atList(ptr.Pointer(), C.int(int32(i))))
		qt.SetFinalizer(tmpValue, (*std_core.QByteArray).DestroyQByteArray)
		return tmpValue
	}
	return nil
}

func (ptr *PathPainter) __dynamicPropertyNames_setList(i std_core.QByteArray_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6___dynamicPropertyNames_setList(ptr.Pointer(), std_core.PointerFromQByteArray(i))
	}
}

func (ptr *PathPainter) __dynamicPropertyNames_newList() unsafe.Pointer {
	return C.PathPainter5d80a6___dynamicPropertyNames_newList(ptr.Pointer())
}

func (ptr *PathPainter) __findChildren_atList2(i int) *std_core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQObjectFromPointer(C.PathPainter5d80a6___findChildren_atList2(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *PathPainter) __findChildren_setList2(i std_core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6___findChildren_setList2(ptr.Pointer(), std_core.PointerFromQObject(i))
	}
}

func (ptr *PathPainter) __findChildren_newList2() unsafe.Pointer {
	return C.PathPainter5d80a6___findChildren_newList2(ptr.Pointer())
}

func (ptr *PathPainter) __findChildren_atList3(i int) *std_core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQObjectFromPointer(C.PathPainter5d80a6___findChildren_atList3(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *PathPainter) __findChildren_setList3(i std_core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6___findChildren_setList3(ptr.Pointer(), std_core.PointerFromQObject(i))
	}
}

func (ptr *PathPainter) __findChildren_newList3() unsafe.Pointer {
	return C.PathPainter5d80a6___findChildren_newList3(ptr.Pointer())
}

func (ptr *PathPainter) __findChildren_atList(i int) *std_core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQObjectFromPointer(C.PathPainter5d80a6___findChildren_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *PathPainter) __findChildren_setList(i std_core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6___findChildren_setList(ptr.Pointer(), std_core.PointerFromQObject(i))
	}
}

func (ptr *PathPainter) __findChildren_newList() unsafe.Pointer {
	return C.PathPainter5d80a6___findChildren_newList(ptr.Pointer())
}

func (ptr *PathPainter) __children_atList(i int) *std_core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQObjectFromPointer(C.PathPainter5d80a6___children_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *PathPainter) __children_setList(i std_core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6___children_setList(ptr.Pointer(), std_core.PointerFromQObject(i))
	}
}

func (ptr *PathPainter) __children_newList() unsafe.Pointer {
	return C.PathPainter5d80a6___children_newList(ptr.Pointer())
}

func NewPathPainter(parent std_quick.QQuickItem_ITF) *PathPainter {
	PathPainter_QRegisterMetaType()
	tmpValue := NewPathPainterFromPointer(C.PathPainter5d80a6_NewPathPainter(std_quick.PointerFromQQuickItem(parent)))
	if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
		tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
	}
	return tmpValue
}

//export callbackPathPainter5d80a6_DestroyPathPainter
func callbackPathPainter5d80a6_DestroyPathPainter(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "~PathPainter"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewPathPainterFromPointer(ptr).DestroyPathPainterDefault()
	}
}

func (ptr *PathPainter) ConnectDestroyPathPainter(f func()) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "~PathPainter"); signal != nil {
			f := func() {
				(*(*func())(signal))()
				f()
			}
			qt.ConnectSignal(ptr.Pointer(), "~PathPainter", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "~PathPainter", unsafe.Pointer(&f))
		}
	}
}

func (ptr *PathPainter) DisconnectDestroyPathPainter() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "~PathPainter")
	}
}

func (ptr *PathPainter) DestroyPathPainter() {
	if ptr.Pointer() != nil {

		qt.SetFinalizer(ptr, nil)
		C.PathPainter5d80a6_DestroyPathPainter(ptr.Pointer())
		ptr.SetPointer(nil)
	}
}

func (ptr *PathPainter) DestroyPathPainterDefault() {
	if ptr.Pointer() != nil {

		qt.SetFinalizer(ptr, nil)
		C.PathPainter5d80a6_DestroyPathPainterDefault(ptr.Pointer())
		ptr.SetPointer(nil)
	}
}

//export callbackPathPainter5d80a6_ContentsScaleChanged
func callbackPathPainter5d80a6_ContentsScaleChanged(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "contentsScaleChanged"); signal != nil {
		(*(*func())(signal))()
	}

}

//export callbackPathPainter5d80a6_ContentsSizeChanged
func callbackPathPainter5d80a6_ContentsSizeChanged(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "contentsSizeChanged"); signal != nil {
		(*(*func())(signal))()
	}

}

//export callbackPathPainter5d80a6_FillColorChanged
func callbackPathPainter5d80a6_FillColorChanged(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "fillColorChanged"); signal != nil {
		(*(*func())(signal))()
	}

}

//export callbackPathPainter5d80a6_Paint
func callbackPathPainter5d80a6_Paint(ptr unsafe.Pointer, painter unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "paint"); signal != nil {
		(*(*func(*std_gui.QPainter))(signal))(std_gui.NewQPainterFromPointer(painter))
	} else {
		NewPathPainterFromPointer(ptr).PaintDefault(std_gui.NewQPainterFromPointer(painter))
	}
}

func (ptr *PathPainter) Paint(painter std_gui.QPainter_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_Paint(ptr.Pointer(), std_gui.PointerFromQPainter(painter))
	}
}

func (ptr *PathPainter) PaintDefault(painter std_gui.QPainter_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_PaintDefault(ptr.Pointer(), std_gui.PointerFromQPainter(painter))
	}
}

//export callbackPathPainter5d80a6_ReleaseResources
func callbackPathPainter5d80a6_ReleaseResources(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "releaseResources"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewPathPainterFromPointer(ptr).ReleaseResourcesDefault()
	}
}

func (ptr *PathPainter) ReleaseResourcesDefault() {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_ReleaseResourcesDefault(ptr.Pointer())
	}
}

//export callbackPathPainter5d80a6_RenderTargetChanged
func callbackPathPainter5d80a6_RenderTargetChanged(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "renderTargetChanged"); signal != nil {
		(*(*func())(signal))()
	}

}

//export callbackPathPainter5d80a6_TextureSizeChanged
func callbackPathPainter5d80a6_TextureSizeChanged(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "textureSizeChanged"); signal != nil {
		(*(*func())(signal))()
	}

}

//export callbackPathPainter5d80a6_TextureProvider
func callbackPathPainter5d80a6_TextureProvider(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "textureProvider"); signal != nil {
		return std_quick.PointerFromQSGTextureProvider((*(*func() *std_quick.QSGTextureProvider)(signal))())
	}

	return std_quick.PointerFromQSGTextureProvider(NewPathPainterFromPointer(ptr).TextureProviderDefault())
}

func (ptr *PathPainter) TextureProviderDefault() *std_quick.QSGTextureProvider {
	if ptr.Pointer() != nil {
		tmpValue := std_quick.NewQSGTextureProviderFromPointer(C.PathPainter5d80a6_TextureProviderDefault(ptr.Pointer()))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*std_core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

//export callbackPathPainter5d80a6_IsTextureProvider
func callbackPathPainter5d80a6_IsTextureProvider(ptr unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "isTextureProvider"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func() bool)(signal))())))
	}

	return C.char(int8(qt.GoBoolToInt(NewPathPainterFromPointer(ptr).IsTextureProviderDefault())))
}

func (ptr *PathPainter) IsTextureProviderDefault() bool {
	if ptr.Pointer() != nil {
		return int8(C.PathPainter5d80a6_IsTextureProviderDefault(ptr.Pointer())) != 0
	}
	return false
}

//export callbackPathPainter5d80a6_ChildMouseEventFilter
func callbackPathPainter5d80a6_ChildMouseEventFilter(ptr unsafe.Pointer, item unsafe.Pointer, event unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "childMouseEventFilter"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*std_quick.QQuickItem, *std_core.QEvent) bool)(signal))(std_quick.NewQQuickItemFromPointer(item), std_core.NewQEventFromPointer(event)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewPathPainterFromPointer(ptr).ChildMouseEventFilterDefault(std_quick.NewQQuickItemFromPointer(item), std_core.NewQEventFromPointer(event)))))
}

func (ptr *PathPainter) ChildMouseEventFilterDefault(item std_quick.QQuickItem_ITF, event std_core.QEvent_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.PathPainter5d80a6_ChildMouseEventFilterDefault(ptr.Pointer(), std_quick.PointerFromQQuickItem(item), std_core.PointerFromQEvent(event))) != 0
	}
	return false
}

//export callbackPathPainter5d80a6_Event
func callbackPathPainter5d80a6_Event(ptr unsafe.Pointer, ev unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "event"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*std_core.QEvent) bool)(signal))(std_core.NewQEventFromPointer(ev)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewPathPainterFromPointer(ptr).EventDefault(std_core.NewQEventFromPointer(ev)))))
}

func (ptr *PathPainter) EventDefault(ev std_core.QEvent_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.PathPainter5d80a6_EventDefault(ptr.Pointer(), std_core.PointerFromQEvent(ev))) != 0
	}
	return false
}

//export callbackPathPainter5d80a6_ClassBegin
func callbackPathPainter5d80a6_ClassBegin(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "classBegin"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewPathPainterFromPointer(ptr).ClassBeginDefault()
	}
}

func (ptr *PathPainter) ClassBeginDefault() {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_ClassBeginDefault(ptr.Pointer())
	}
}

//export callbackPathPainter5d80a6_ComponentComplete
func callbackPathPainter5d80a6_ComponentComplete(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "componentComplete"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewPathPainterFromPointer(ptr).ComponentCompleteDefault()
	}
}

func (ptr *PathPainter) ComponentCompleteDefault() {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_ComponentCompleteDefault(ptr.Pointer())
	}
}

//export callbackPathPainter5d80a6_ContainmentMaskChanged
func callbackPathPainter5d80a6_ContainmentMaskChanged(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "containmentMaskChanged"); signal != nil {
		(*(*func())(signal))()
	}

}

//export callbackPathPainter5d80a6_DragEnterEvent
func callbackPathPainter5d80a6_DragEnterEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "dragEnterEvent"); signal != nil {
		(*(*func(*std_gui.QDragEnterEvent))(signal))(std_gui.NewQDragEnterEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).DragEnterEventDefault(std_gui.NewQDragEnterEventFromPointer(event))
	}
}

func (ptr *PathPainter) DragEnterEventDefault(event std_gui.QDragEnterEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_DragEnterEventDefault(ptr.Pointer(), std_gui.PointerFromQDragEnterEvent(event))
	}
}

//export callbackPathPainter5d80a6_DragLeaveEvent
func callbackPathPainter5d80a6_DragLeaveEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "dragLeaveEvent"); signal != nil {
		(*(*func(*std_gui.QDragLeaveEvent))(signal))(std_gui.NewQDragLeaveEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).DragLeaveEventDefault(std_gui.NewQDragLeaveEventFromPointer(event))
	}
}

func (ptr *PathPainter) DragLeaveEventDefault(event std_gui.QDragLeaveEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_DragLeaveEventDefault(ptr.Pointer(), std_gui.PointerFromQDragLeaveEvent(event))
	}
}

//export callbackPathPainter5d80a6_DragMoveEvent
func callbackPathPainter5d80a6_DragMoveEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "dragMoveEvent"); signal != nil {
		(*(*func(*std_gui.QDragMoveEvent))(signal))(std_gui.NewQDragMoveEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).DragMoveEventDefault(std_gui.NewQDragMoveEventFromPointer(event))
	}
}

func (ptr *PathPainter) DragMoveEventDefault(event std_gui.QDragMoveEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_DragMoveEventDefault(ptr.Pointer(), std_gui.PointerFromQDragMoveEvent(event))
	}
}

//export callbackPathPainter5d80a6_DropEvent
func callbackPathPainter5d80a6_DropEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "dropEvent"); signal != nil {
		(*(*func(*std_gui.QDropEvent))(signal))(std_gui.NewQDropEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).DropEventDefault(std_gui.NewQDropEventFromPointer(event))
	}
}

func (ptr *PathPainter) DropEventDefault(event std_gui.QDropEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_DropEventDefault(ptr.Pointer(), std_gui.PointerFromQDropEvent(event))
	}
}

//export callbackPathPainter5d80a6_FocusInEvent
func callbackPathPainter5d80a6_FocusInEvent(ptr unsafe.Pointer, vqf unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "focusInEvent"); signal != nil {
		(*(*func(*std_gui.QFocusEvent))(signal))(std_gui.NewQFocusEventFromPointer(vqf))
	} else {
		NewPathPainterFromPointer(ptr).FocusInEventDefault(std_gui.NewQFocusEventFromPointer(vqf))
	}
}

func (ptr *PathPainter) FocusInEventDefault(vqf std_gui.QFocusEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_FocusInEventDefault(ptr.Pointer(), std_gui.PointerFromQFocusEvent(vqf))
	}
}

//export callbackPathPainter5d80a6_FocusOutEvent
func callbackPathPainter5d80a6_FocusOutEvent(ptr unsafe.Pointer, vqf unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "focusOutEvent"); signal != nil {
		(*(*func(*std_gui.QFocusEvent))(signal))(std_gui.NewQFocusEventFromPointer(vqf))
	} else {
		NewPathPainterFromPointer(ptr).FocusOutEventDefault(std_gui.NewQFocusEventFromPointer(vqf))
	}
}

func (ptr *PathPainter) FocusOutEventDefault(vqf std_gui.QFocusEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_FocusOutEventDefault(ptr.Pointer(), std_gui.PointerFromQFocusEvent(vqf))
	}
}

//export callbackPathPainter5d80a6_GeometryChanged
func callbackPathPainter5d80a6_GeometryChanged(ptr unsafe.Pointer, newGeometry unsafe.Pointer, oldGeometry unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "geometryChanged"); signal != nil {
		(*(*func(*std_core.QRectF, *std_core.QRectF))(signal))(std_core.NewQRectFFromPointer(newGeometry), std_core.NewQRectFFromPointer(oldGeometry))
	} else {
		NewPathPainterFromPointer(ptr).GeometryChangedDefault(std_core.NewQRectFFromPointer(newGeometry), std_core.NewQRectFFromPointer(oldGeometry))
	}
}

func (ptr *PathPainter) GeometryChangedDefault(newGeometry std_core.QRectF_ITF, oldGeometry std_core.QRectF_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_GeometryChangedDefault(ptr.Pointer(), std_core.PointerFromQRectF(newGeometry), std_core.PointerFromQRectF(oldGeometry))
	}
}

//export callbackPathPainter5d80a6_HoverEnterEvent
func callbackPathPainter5d80a6_HoverEnterEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "hoverEnterEvent"); signal != nil {
		(*(*func(*std_gui.QHoverEvent))(signal))(std_gui.NewQHoverEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).HoverEnterEventDefault(std_gui.NewQHoverEventFromPointer(event))
	}
}

func (ptr *PathPainter) HoverEnterEventDefault(event std_gui.QHoverEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_HoverEnterEventDefault(ptr.Pointer(), std_gui.PointerFromQHoverEvent(event))
	}
}

//export callbackPathPainter5d80a6_HoverLeaveEvent
func callbackPathPainter5d80a6_HoverLeaveEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "hoverLeaveEvent"); signal != nil {
		(*(*func(*std_gui.QHoverEvent))(signal))(std_gui.NewQHoverEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).HoverLeaveEventDefault(std_gui.NewQHoverEventFromPointer(event))
	}
}

func (ptr *PathPainter) HoverLeaveEventDefault(event std_gui.QHoverEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_HoverLeaveEventDefault(ptr.Pointer(), std_gui.PointerFromQHoverEvent(event))
	}
}

//export callbackPathPainter5d80a6_HoverMoveEvent
func callbackPathPainter5d80a6_HoverMoveEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "hoverMoveEvent"); signal != nil {
		(*(*func(*std_gui.QHoverEvent))(signal))(std_gui.NewQHoverEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).HoverMoveEventDefault(std_gui.NewQHoverEventFromPointer(event))
	}
}

func (ptr *PathPainter) HoverMoveEventDefault(event std_gui.QHoverEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_HoverMoveEventDefault(ptr.Pointer(), std_gui.PointerFromQHoverEvent(event))
	}
}

//export callbackPathPainter5d80a6_InputMethodEvent
func callbackPathPainter5d80a6_InputMethodEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "inputMethodEvent"); signal != nil {
		(*(*func(*std_gui.QInputMethodEvent))(signal))(std_gui.NewQInputMethodEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).InputMethodEventDefault(std_gui.NewQInputMethodEventFromPointer(event))
	}
}

func (ptr *PathPainter) InputMethodEventDefault(event std_gui.QInputMethodEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_InputMethodEventDefault(ptr.Pointer(), std_gui.PointerFromQInputMethodEvent(event))
	}
}

//export callbackPathPainter5d80a6_KeyPressEvent
func callbackPathPainter5d80a6_KeyPressEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "keyPressEvent"); signal != nil {
		(*(*func(*std_gui.QKeyEvent))(signal))(std_gui.NewQKeyEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).KeyPressEventDefault(std_gui.NewQKeyEventFromPointer(event))
	}
}

func (ptr *PathPainter) KeyPressEventDefault(event std_gui.QKeyEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_KeyPressEventDefault(ptr.Pointer(), std_gui.PointerFromQKeyEvent(event))
	}
}

//export callbackPathPainter5d80a6_KeyReleaseEvent
func callbackPathPainter5d80a6_KeyReleaseEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "keyReleaseEvent"); signal != nil {
		(*(*func(*std_gui.QKeyEvent))(signal))(std_gui.NewQKeyEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).KeyReleaseEventDefault(std_gui.NewQKeyEventFromPointer(event))
	}
}

func (ptr *PathPainter) KeyReleaseEventDefault(event std_gui.QKeyEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_KeyReleaseEventDefault(ptr.Pointer(), std_gui.PointerFromQKeyEvent(event))
	}
}

//export callbackPathPainter5d80a6_MouseDoubleClickEvent
func callbackPathPainter5d80a6_MouseDoubleClickEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "mouseDoubleClickEvent"); signal != nil {
		(*(*func(*std_gui.QMouseEvent))(signal))(std_gui.NewQMouseEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).MouseDoubleClickEventDefault(std_gui.NewQMouseEventFromPointer(event))
	}
}

func (ptr *PathPainter) MouseDoubleClickEventDefault(event std_gui.QMouseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_MouseDoubleClickEventDefault(ptr.Pointer(), std_gui.PointerFromQMouseEvent(event))
	}
}

//export callbackPathPainter5d80a6_MouseMoveEvent
func callbackPathPainter5d80a6_MouseMoveEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "mouseMoveEvent"); signal != nil {
		(*(*func(*std_gui.QMouseEvent))(signal))(std_gui.NewQMouseEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).MouseMoveEventDefault(std_gui.NewQMouseEventFromPointer(event))
	}
}

func (ptr *PathPainter) MouseMoveEventDefault(event std_gui.QMouseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_MouseMoveEventDefault(ptr.Pointer(), std_gui.PointerFromQMouseEvent(event))
	}
}

//export callbackPathPainter5d80a6_MousePressEvent
func callbackPathPainter5d80a6_MousePressEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "mousePressEvent"); signal != nil {
		(*(*func(*std_gui.QMouseEvent))(signal))(std_gui.NewQMouseEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).MousePressEventDefault(std_gui.NewQMouseEventFromPointer(event))
	}
}

func (ptr *PathPainter) MousePressEventDefault(event std_gui.QMouseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_MousePressEventDefault(ptr.Pointer(), std_gui.PointerFromQMouseEvent(event))
	}
}

//export callbackPathPainter5d80a6_MouseReleaseEvent
func callbackPathPainter5d80a6_MouseReleaseEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "mouseReleaseEvent"); signal != nil {
		(*(*func(*std_gui.QMouseEvent))(signal))(std_gui.NewQMouseEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).MouseReleaseEventDefault(std_gui.NewQMouseEventFromPointer(event))
	}
}

func (ptr *PathPainter) MouseReleaseEventDefault(event std_gui.QMouseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_MouseReleaseEventDefault(ptr.Pointer(), std_gui.PointerFromQMouseEvent(event))
	}
}

//export callbackPathPainter5d80a6_MouseUngrabEvent
func callbackPathPainter5d80a6_MouseUngrabEvent(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "mouseUngrabEvent"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewPathPainterFromPointer(ptr).MouseUngrabEventDefault()
	}
}

func (ptr *PathPainter) MouseUngrabEventDefault() {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_MouseUngrabEventDefault(ptr.Pointer())
	}
}

//export callbackPathPainter5d80a6_TouchEvent
func callbackPathPainter5d80a6_TouchEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "touchEvent"); signal != nil {
		(*(*func(*std_gui.QTouchEvent))(signal))(std_gui.NewQTouchEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).TouchEventDefault(std_gui.NewQTouchEventFromPointer(event))
	}
}

func (ptr *PathPainter) TouchEventDefault(event std_gui.QTouchEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_TouchEventDefault(ptr.Pointer(), std_gui.PointerFromQTouchEvent(event))
	}
}

//export callbackPathPainter5d80a6_TouchUngrabEvent
func callbackPathPainter5d80a6_TouchUngrabEvent(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "touchUngrabEvent"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewPathPainterFromPointer(ptr).TouchUngrabEventDefault()
	}
}

func (ptr *PathPainter) TouchUngrabEventDefault() {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_TouchUngrabEventDefault(ptr.Pointer())
	}
}

//export callbackPathPainter5d80a6_UpdatePolish
func callbackPathPainter5d80a6_UpdatePolish(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "updatePolish"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewPathPainterFromPointer(ptr).UpdatePolishDefault()
	}
}

func (ptr *PathPainter) UpdatePolishDefault() {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_UpdatePolishDefault(ptr.Pointer())
	}
}

//export callbackPathPainter5d80a6_WheelEvent
func callbackPathPainter5d80a6_WheelEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "wheelEvent"); signal != nil {
		(*(*func(*std_gui.QWheelEvent))(signal))(std_gui.NewQWheelEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).WheelEventDefault(std_gui.NewQWheelEventFromPointer(event))
	}
}

func (ptr *PathPainter) WheelEventDefault(event std_gui.QWheelEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_WheelEventDefault(ptr.Pointer(), std_gui.PointerFromQWheelEvent(event))
	}
}

//export callbackPathPainter5d80a6_WindowChanged
func callbackPathPainter5d80a6_WindowChanged(ptr unsafe.Pointer, window unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "windowChanged"); signal != nil {
		(*(*func(*std_quick.QQuickWindow))(signal))(std_quick.NewQQuickWindowFromPointer(window))
	}

}

//export callbackPathPainter5d80a6_InputMethodQuery
func callbackPathPainter5d80a6_InputMethodQuery(ptr unsafe.Pointer, query C.longlong) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "inputMethodQuery"); signal != nil {
		return std_core.PointerFromQVariant((*(*func(std_core.Qt__InputMethodQuery) *std_core.QVariant)(signal))(std_core.Qt__InputMethodQuery(query)))
	}

	return std_core.PointerFromQVariant(NewPathPainterFromPointer(ptr).InputMethodQueryDefault(std_core.Qt__InputMethodQuery(query)))
}

func (ptr *PathPainter) InputMethodQueryDefault(query std_core.Qt__InputMethodQuery) *std_core.QVariant {
	if ptr.Pointer() != nil {
		tmpValue := std_core.NewQVariantFromPointer(C.PathPainter5d80a6_InputMethodQueryDefault(ptr.Pointer(), C.longlong(query)))
		qt.SetFinalizer(tmpValue, (*std_core.QVariant).DestroyQVariant)
		return tmpValue
	}
	return nil
}

//export callbackPathPainter5d80a6_Contains
func callbackPathPainter5d80a6_Contains(ptr unsafe.Pointer, point unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "contains"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*std_core.QPointF) bool)(signal))(std_core.NewQPointFFromPointer(point)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewPathPainterFromPointer(ptr).ContainsDefault(std_core.NewQPointFFromPointer(point)))))
}

func (ptr *PathPainter) ContainsDefault(point std_core.QPointF_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.PathPainter5d80a6_ContainsDefault(ptr.Pointer(), std_core.PointerFromQPointF(point))) != 0
	}
	return false
}

//export callbackPathPainter5d80a6_EventFilter
func callbackPathPainter5d80a6_EventFilter(ptr unsafe.Pointer, watched unsafe.Pointer, event unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "eventFilter"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*std_core.QObject, *std_core.QEvent) bool)(signal))(std_core.NewQObjectFromPointer(watched), std_core.NewQEventFromPointer(event)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewPathPainterFromPointer(ptr).EventFilterDefault(std_core.NewQObjectFromPointer(watched), std_core.NewQEventFromPointer(event)))))
}

func (ptr *PathPainter) EventFilterDefault(watched std_core.QObject_ITF, event std_core.QEvent_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.PathPainter5d80a6_EventFilterDefault(ptr.Pointer(), std_core.PointerFromQObject(watched), std_core.PointerFromQEvent(event))) != 0
	}
	return false
}

//export callbackPathPainter5d80a6_ChildEvent
func callbackPathPainter5d80a6_ChildEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "childEvent"); signal != nil {
		(*(*func(*std_core.QChildEvent))(signal))(std_core.NewQChildEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).ChildEventDefault(std_core.NewQChildEventFromPointer(event))
	}
}

func (ptr *PathPainter) ChildEventDefault(event std_core.QChildEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_ChildEventDefault(ptr.Pointer(), std_core.PointerFromQChildEvent(event))
	}
}

//export callbackPathPainter5d80a6_ConnectNotify
func callbackPathPainter5d80a6_ConnectNotify(ptr unsafe.Pointer, sign unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "connectNotify"); signal != nil {
		(*(*func(*std_core.QMetaMethod))(signal))(std_core.NewQMetaMethodFromPointer(sign))
	} else {
		NewPathPainterFromPointer(ptr).ConnectNotifyDefault(std_core.NewQMetaMethodFromPointer(sign))
	}
}

func (ptr *PathPainter) ConnectNotifyDefault(sign std_core.QMetaMethod_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_ConnectNotifyDefault(ptr.Pointer(), std_core.PointerFromQMetaMethod(sign))
	}
}

//export callbackPathPainter5d80a6_CustomEvent
func callbackPathPainter5d80a6_CustomEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "customEvent"); signal != nil {
		(*(*func(*std_core.QEvent))(signal))(std_core.NewQEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).CustomEventDefault(std_core.NewQEventFromPointer(event))
	}
}

func (ptr *PathPainter) CustomEventDefault(event std_core.QEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_CustomEventDefault(ptr.Pointer(), std_core.PointerFromQEvent(event))
	}
}

//export callbackPathPainter5d80a6_DeleteLater
func callbackPathPainter5d80a6_DeleteLater(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "deleteLater"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewPathPainterFromPointer(ptr).DeleteLaterDefault()
	}
}

func (ptr *PathPainter) DeleteLaterDefault() {
	if ptr.Pointer() != nil {

		qt.SetFinalizer(ptr, nil)
		C.PathPainter5d80a6_DeleteLaterDefault(ptr.Pointer())
	}
}

//export callbackPathPainter5d80a6_Destroyed
func callbackPathPainter5d80a6_Destroyed(ptr unsafe.Pointer, obj unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "destroyed"); signal != nil {
		(*(*func(*std_core.QObject))(signal))(std_core.NewQObjectFromPointer(obj))
	}
	qt.Unregister(ptr)

}

//export callbackPathPainter5d80a6_DisconnectNotify
func callbackPathPainter5d80a6_DisconnectNotify(ptr unsafe.Pointer, sign unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "disconnectNotify"); signal != nil {
		(*(*func(*std_core.QMetaMethod))(signal))(std_core.NewQMetaMethodFromPointer(sign))
	} else {
		NewPathPainterFromPointer(ptr).DisconnectNotifyDefault(std_core.NewQMetaMethodFromPointer(sign))
	}
}

func (ptr *PathPainter) DisconnectNotifyDefault(sign std_core.QMetaMethod_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_DisconnectNotifyDefault(ptr.Pointer(), std_core.PointerFromQMetaMethod(sign))
	}
}

//export callbackPathPainter5d80a6_ObjectNameChanged
func callbackPathPainter5d80a6_ObjectNameChanged(ptr unsafe.Pointer, objectName C.struct_Moc_PackedString) {
	if signal := qt.GetSignal(ptr, "objectNameChanged"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(objectName))
	}

}

//export callbackPathPainter5d80a6_TimerEvent
func callbackPathPainter5d80a6_TimerEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "timerEvent"); signal != nil {
		(*(*func(*std_core.QTimerEvent))(signal))(std_core.NewQTimerEventFromPointer(event))
	} else {
		NewPathPainterFromPointer(ptr).TimerEventDefault(std_core.NewQTimerEventFromPointer(event))
	}
}

func (ptr *PathPainter) TimerEventDefault(event std_core.QTimerEvent_ITF) {
	if ptr.Pointer() != nil {
		C.PathPainter5d80a6_TimerEventDefault(ptr.Pointer(), std_core.PointerFromQTimerEvent(event))
	}
}

func init() {
	qt.ItfMap["main.PathPainter_ITF"] = PathPainter{}
	qt.FuncMap["main.NewPathPainter"] = NewPathPainter
}
