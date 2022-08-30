#ifndef CTEXTEDITOR_H
#define CTEXTEDITOR_H

#if defined _WIN32 || defined __CYGWIN__
#ifdef CIMGUI_NO_EXPORT
#define API
#else
#define API __declspec(dllexport)
#endif
#else
#ifdef __GNUC__
#define API  __attribute__((__visibility__("default")))
#else
#define API
#endif
#endif

#if defined __cplusplus
#define EXTERN extern "C"
#else
#include <stdarg.h>
#include <stdbool.h>
#define EXTERN extern
#endif

#define CIMGUI_API EXTERN API
#define CONST const

#include "TextEditor.h"

typedef TextEditor::PaletteIndex PaletteIndex;
typedef TextEditor::SelectionMode SelectionMode;
typedef struct TextEditor::Breakpoint Breakpoint;
typedef struct TextEditor::Coordinates Coordinates;
typedef struct TextEditor::Identifier Identifier;
typedef struct TextEditor::Glyph Glyph;
typedef ImU32* Palette;

CIMGUI_API Breakpoint* Breakpoint_Breakpoint(void);
CIMGUI_API void Breakpoint_Destroy(Breakpoint* ins);

CIMGUI_API Coordinates* Coordinates_Coordinates(void);
CIMGUI_API void Coordinates_Destroy(Coordinates* ins);

CIMGUI_API Identifier* Identifier_Identifier(char* aDeclaration);
CIMGUI_API void Identifier_Destroy(Identifier* ins);

CIMGUI_API Glyph* Glyph_Glyph(char aChar, PaletteIndex aColorIndex);
CIMGUI_API void Glyph_Destroy(Glyph* ins);

CIMGUI_API TextEditor* TextEditor_TextEditor(void);
CIMGUI_API void TextEditor_Destroy(TextEditor* ins);

CIMGUI_API const Palette igteGetPalette(TextEditor* ins);
CIMGUI_API void igteSetPalette(TextEditor* ins, const Palette aValue);

//SetErrorMarkers
//SetBreakpoints

CIMGUI_API void igteRender(TextEditor* ins, const char* aTitle, const ImVec2 aSize, bool aBorder);
CIMGUI_API void igteSetText(TextEditor* ins, const char* aText);
CIMGUI_API void igteSetTextLines(TextEditor* ins, const char** aLines, int aCount);
CIMGUI_API char* igteGetText(TextEditor* ins);
CIMGUI_API char** igteGetTextLines(TextEditor* ins);
CIMGUI_API char* igteGetSelectedText(TextEditor* ins);
CIMGUI_API char* igteGetCurrentLineText(TextEditor* ins);

CIMGUI_API int igteGetTotalLines(TextEditor* ins);
CIMGUI_API bool igteIsOverwrite(TextEditor* ins);

CIMGUI_API void igteSetReadOnly(TextEditor* ins, bool aValue);
CIMGUI_API bool igteIsReadOnly(TextEditor* ins);
CIMGUI_API bool igteIsTextChanged(TextEditor* ins);
CIMGUI_API bool igteIsCursorPositionChanged(TextEditor* ins);

CIMGUI_API void igteGetCursorPosition(TextEditor* ins, Coordinates* aResult);
CIMGUI_API void igteSetCursorPosition(TextEditor* ins, const Coordinates aPosition);

CIMGUI_API void igteInsertText(TextEditor* ins, const char* aValue);

CIMGUI_API void igteMoveUp(TextEditor* ins, int aAmount, bool aSelect);
CIMGUI_API void igteMoveDown(TextEditor* ins, int aAmount, bool aSelect);
CIMGUI_API void igteMoveLeft(TextEditor* ins, int aAmount, bool aSelect, bool aWordMode);
CIMGUI_API void igteMoveRight(TextEditor* ins, int aAmount, bool aSelect, bool aWordMode);
CIMGUI_API void igteMoveTop(TextEditor* ins, bool aSelect);
CIMGUI_API void igteMoveBottom(TextEditor* ins, bool aSelect);
CIMGUI_API void igteMoveHome(TextEditor* ins, bool aSelect);
CIMGUI_API void igteMoveEnd(TextEditor* ins, bool aSelect);

CIMGUI_API void igteSetSelectionStart(TextEditor* ins, const Coordinates aPosition);
CIMGUI_API void igteSetSelectionEnd(TextEditor* ins, const Coordinates aPosition);
CIMGUI_API void igteSetSelection(TextEditor* ins, const Coordinates aStart, const Coordinates aEnd, SelectionMode aMode);
CIMGUI_API void igteSelectWordUnderCursor(TextEditor* ins);
CIMGUI_API void igteSelectAll(TextEditor* ins);
CIMGUI_API bool igteHasSelection(TextEditor* ins);

CIMGUI_API void igteCopy(TextEditor* ins);
CIMGUI_API void igteCut(TextEditor* ins);
CIMGUI_API void igtePaste(TextEditor* ins);
CIMGUI_API void igteDelete(TextEditor* ins);

CIMGUI_API bool igteCanUndo(TextEditor* ins);
CIMGUI_API bool igteCanRedo(TextEditor* ins);
CIMGUI_API void igteUndo(TextEditor* ins, int aSteps);
CIMGUI_API void igteRedo(TextEditor* ins, int aSteps);

CIMGUI_API const Palette igteGetDarkPalette(void);
CIMGUI_API const Palette igteGetLightPalette(void);
CIMGUI_API const Palette igteGetRetroBluePalette(void);

CIMGUI_API void igteDeleteArray(void* ptr);
#endif // !CTEXTEDITOR_H
