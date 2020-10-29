

#pragma once

#ifndef GO_MOC_5d80a6_H
#define GO_MOC_5d80a6_H

#include <stdint.h>

#ifdef __cplusplus
class PathPainter5d80a6;
void PathPainter5d80a6_PathPainter5d80a6_QRegisterMetaTypes();
extern "C" {
#endif

struct Moc_PackedString { char* data; long long len; void* ptr; };
struct Moc_PackedList { void* data; long long len; };
struct Moc_PackedString PathPainter5d80a6_Name(void* ptr);
struct Moc_PackedString PathPainter5d80a6_NameDefault(void* ptr);
void PathPainter5d80a6_SetName(void* ptr, struct Moc_PackedString name);
void PathPainter5d80a6_SetNameDefault(void* ptr, struct Moc_PackedString name);
void PathPainter5d80a6_ConnectNameChanged(void* ptr, long long t);
void PathPainter5d80a6_DisconnectNameChanged(void* ptr);
void PathPainter5d80a6_NameChanged(void* ptr, struct Moc_PackedString name);
void* PathPainter5d80a6_Color(void* ptr);
void* PathPainter5d80a6_ColorDefault(void* ptr);
void PathPainter5d80a6_SetColor(void* ptr, void* color);
void PathPainter5d80a6_SetColorDefault(void* ptr, void* color);
void PathPainter5d80a6_ConnectColorChanged(void* ptr, long long t);
void PathPainter5d80a6_DisconnectColorChanged(void* ptr);
void PathPainter5d80a6_ColorChanged(void* ptr, void* color);
int PathPainter5d80a6_PathPainter5d80a6_QRegisterMetaType();
int PathPainter5d80a6_PathPainter5d80a6_QRegisterMetaType2(char* typeName);
int PathPainter5d80a6_PathPainter5d80a6_QmlRegisterType();
int PathPainter5d80a6_PathPainter5d80a6_QmlRegisterType2(char* uri, int versionMajor, int versionMinor, char* qmlName);
int PathPainter5d80a6_PathPainter5d80a6_QmlRegisterUncreatableType(char* uri, int versionMajor, int versionMinor, char* qmlName, struct Moc_PackedString message);
int PathPainter5d80a6___grabTouchPoints_ids_atList(void* ptr, int i);
void PathPainter5d80a6___grabTouchPoints_ids_setList(void* ptr, int i);
void* PathPainter5d80a6___grabTouchPoints_ids_newList(void* ptr);
void* PathPainter5d80a6___childItems_atList(void* ptr, int i);
void PathPainter5d80a6___childItems_setList(void* ptr, void* i);
void* PathPainter5d80a6___childItems_newList(void* ptr);
void* PathPainter5d80a6___dynamicPropertyNames_atList(void* ptr, int i);
void PathPainter5d80a6___dynamicPropertyNames_setList(void* ptr, void* i);
void* PathPainter5d80a6___dynamicPropertyNames_newList(void* ptr);
void* PathPainter5d80a6___findChildren_atList2(void* ptr, int i);
void PathPainter5d80a6___findChildren_setList2(void* ptr, void* i);
void* PathPainter5d80a6___findChildren_newList2(void* ptr);
void* PathPainter5d80a6___findChildren_atList3(void* ptr, int i);
void PathPainter5d80a6___findChildren_setList3(void* ptr, void* i);
void* PathPainter5d80a6___findChildren_newList3(void* ptr);
void* PathPainter5d80a6___findChildren_atList(void* ptr, int i);
void PathPainter5d80a6___findChildren_setList(void* ptr, void* i);
void* PathPainter5d80a6___findChildren_newList(void* ptr);
void* PathPainter5d80a6___children_atList(void* ptr, int i);
void PathPainter5d80a6___children_setList(void* ptr, void* i);
void* PathPainter5d80a6___children_newList(void* ptr);
void* PathPainter5d80a6_NewPathPainter(void* parent);
void PathPainter5d80a6_DestroyPathPainter(void* ptr);
void PathPainter5d80a6_DestroyPathPainterDefault(void* ptr);
void PathPainter5d80a6_Paint(void* ptr, void* painter);
void PathPainter5d80a6_PaintDefault(void* ptr, void* painter);
void PathPainter5d80a6_ReleaseResourcesDefault(void* ptr);
void* PathPainter5d80a6_TextureProviderDefault(void* ptr);
char PathPainter5d80a6_IsTextureProviderDefault(void* ptr);
;
char PathPainter5d80a6_ChildMouseEventFilterDefault(void* ptr, void* item, void* event);
char PathPainter5d80a6_EventDefault(void* ptr, void* ev);
void PathPainter5d80a6_ClassBeginDefault(void* ptr);
void PathPainter5d80a6_ComponentCompleteDefault(void* ptr);
void PathPainter5d80a6_DragEnterEventDefault(void* ptr, void* event);
void PathPainter5d80a6_DragLeaveEventDefault(void* ptr, void* event);
void PathPainter5d80a6_DragMoveEventDefault(void* ptr, void* event);
void PathPainter5d80a6_DropEventDefault(void* ptr, void* event);
void PathPainter5d80a6_FocusInEventDefault(void* ptr, void* vqf);
void PathPainter5d80a6_FocusOutEventDefault(void* ptr, void* vqf);
void PathPainter5d80a6_GeometryChangedDefault(void* ptr, void* newGeometry, void* oldGeometry);
void PathPainter5d80a6_HoverEnterEventDefault(void* ptr, void* event);
void PathPainter5d80a6_HoverLeaveEventDefault(void* ptr, void* event);
void PathPainter5d80a6_HoverMoveEventDefault(void* ptr, void* event);
void PathPainter5d80a6_InputMethodEventDefault(void* ptr, void* event);
void PathPainter5d80a6_KeyPressEventDefault(void* ptr, void* event);
void PathPainter5d80a6_KeyReleaseEventDefault(void* ptr, void* event);
void PathPainter5d80a6_MouseDoubleClickEventDefault(void* ptr, void* event);
void PathPainter5d80a6_MouseMoveEventDefault(void* ptr, void* event);
void PathPainter5d80a6_MousePressEventDefault(void* ptr, void* event);
void PathPainter5d80a6_MouseReleaseEventDefault(void* ptr, void* event);
void PathPainter5d80a6_MouseUngrabEventDefault(void* ptr);
void PathPainter5d80a6_TouchEventDefault(void* ptr, void* event);
void PathPainter5d80a6_TouchUngrabEventDefault(void* ptr);
void PathPainter5d80a6_UpdatePolishDefault(void* ptr);
void PathPainter5d80a6_WheelEventDefault(void* ptr, void* event);
void* PathPainter5d80a6_InputMethodQueryDefault(void* ptr, long long query);
char PathPainter5d80a6_ContainsDefault(void* ptr, void* point);
char PathPainter5d80a6_EventFilterDefault(void* ptr, void* watched, void* event);
void PathPainter5d80a6_ChildEventDefault(void* ptr, void* event);
void PathPainter5d80a6_ConnectNotifyDefault(void* ptr, void* sign);
void PathPainter5d80a6_CustomEventDefault(void* ptr, void* event);
void PathPainter5d80a6_DeleteLaterDefault(void* ptr);
void PathPainter5d80a6_DisconnectNotifyDefault(void* ptr, void* sign);
void PathPainter5d80a6_TimerEventDefault(void* ptr, void* event);

#ifdef __cplusplus
}
#endif

#endif