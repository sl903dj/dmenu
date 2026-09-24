#ifndef INPUTMETHOD_H
#define INPUTMETHOD_H

#include <stddef.h>
#include <X11/Xlib.h>

/* 全局变量声明 (加 extern，定义移到 .c 中) */
extern int composing;
extern char preview[512];

/* 供 dmenu.c 调用的核心初始化函数 */
void init_input_method(XIM xim);

/* 内部工具函数与 IM 回调函数声明 */
size_t nextrunetext(const char *text, size_t position, int inc);
size_t runebytes(const char *text, size_t n);
size_t runechars(const char *text, size_t n);

void preeditcaret(XIC xic, XPointer clientdata, XPointer calldata);
int preeditstart(XIC xic, XPointer clientdata, XPointer calldata);
void preeditdone(XIC xic, XPointer clientdata, XPointer calldata);
void preeditdraw(XIC xic, XPointer clientdata, XPointer calldata);

#endif
