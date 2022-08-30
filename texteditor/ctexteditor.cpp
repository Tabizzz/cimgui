
#include "ctexteditor.h"

const Palette igtPalettePointer(TextEditor::Palette palette)
{
	auto size = palette.size();
	Palette ret = new ImU32[size];
	for (size_t i = 0; i < size; i++)
	{
		ret[i] = palette[i];
	}
	return ret;
}

CIMGUI_API Breakpoint* Breakpoint_Breakpoint(void)
{
	return IM_NEW(Breakpoint);
}
CIMGUI_API void Breakpoint_Destroy(Breakpoint* ins)
{
	if (ins)
	{
		IM_DELETE(ins);
		ins = nullptr;
	}
}

CIMGUI_API Coordinates* Coordinates_Coordinates(void)
{
	return IM_NEW(Coordinates);
}
CIMGUI_API void Coordinates_Destroy(Coordinates* ins)
{
	if (ins)
	{
		IM_DELETE(ins);
		ins = nullptr;
	}
}

CIMGUI_API Identifier* Identifier_Identifier(void)
{
	return IM_NEW(Identifier);
}
CIMGUI_API void Identifier_Destroy(Identifier* ins)
{
	if (ins)
	{
		IM_DELETE(ins);
		ins = nullptr;
	}
}

CIMGUI_API Glyph* Glyph_Glyph(char aChar, PaletteIndex aColorIndex)
{
	return IM_NEW(Glyph)(aChar, aColorIndex);
}
CIMGUI_API void Glyph_Destroy(Glyph* ins)
{
	if (ins)
	{
		IM_DELETE(ins);
		ins = nullptr;
	}
}

IMGUI_API TextEditor* TextEditor_TextEditor(void)
{
	return IM_NEW(TextEditor);
}
CIMGUI_API void TextEditor_Destroy(TextEditor* ins)
{
	if (ins)
	{
		IM_DELETE(ins);
		ins = nullptr;
	}
}

CIMGUI_API const Palette igteGetPalette(TextEditor* ins)
{
	return igtPalettePointer(ins->GetPalette());
}
CIMGUI_API void igteSetPalette(TextEditor* ins, const Palette aValue)
{
	if (ins)
	{
		TextEditor::Palette palete;
		for (size_t i = 0; i < (unsigned)TextEditor::PaletteIndex::Max; i++)
		{
			palete[i] = aValue[i];
		}
		ins->SetPalette(palete);
	}
}

//SetErrorMarkers
//SetBreakpoints

CIMGUI_API void igteRender(TextEditor* ins, const char* aTitle, const ImVec2 aSize, bool aBorder)
{
	if (ins)
	{
		ins->Render(aTitle, aSize, aBorder);
	}
}
CIMGUI_API void igteSetText(TextEditor* ins, const char* aText)
{
	if (ins)
	{
		ins->SetText(aText);
	}
}
CIMGUI_API void igteSetTextLines(TextEditor* ins, const char** aLines, int aCount)
{
	if (ins)
	{
		std::vector<std::string> vector;
		for (size_t i = 0; i < aCount; i++)
		{
			vector.push_back(aLines[i]);
		}
		ins->SetTextLines(vector);
	}
}
CIMGUI_API char* igteGetText(TextEditor* ins)
{
	std::string str = ins->GetText();
	auto size = str.size();
	char* cstr = new char[str.length() + 1];
	strcpy_s(cstr, size, str.c_str());
	return cstr;
}
CIMGUI_API char** igteGetTextLines(TextEditor* ins)
{
	auto count = igteGetTextLinesSize(ins);
	auto ret = new char* [count];
	auto data = ins->GetTextLines();

	for (size_t i = 0; i < count; i++)
	{
		std::string str = data[i];
		auto size = str.size();
		char* cstr = new char[str.length() + 1];
		strcpy_s(cstr, size, str.c_str());
		ret[i] = cstr;
	}

	return ret;
}
CIMGUI_API size_t igteGetTextLinesSize(TextEditor* ins)
{
	return ins->GetTextLines().size();
}
CIMGUI_API const char* igteGetSelectedText(TextEditor* ins)
{
	std::string str = ins->GetSelectedText();
	auto size = str.size();
	char* cstr = new char[str.length() + 1];
	strcpy_s(cstr, size, str.c_str());
	return cstr;
}
CIMGUI_API const char* igteGetCurrentLineText(TextEditor* ins)
{
	std::string str = ins->GetCurrentLineText();
	auto size = str.size();
	char* cstr = new char[str.length() + 1];
	strcpy_s(cstr, size, str.c_str());
	return cstr;
}

CIMGUI_API int igteGetTotalLines(TextEditor* ins)
{
	return ins->GetTotalLines();
}
CIMGUI_API bool igteIsOverwrite(TextEditor* ins)
{
	return ins->IsOverwrite();
}

CIMGUI_API void igteSetReadOnly(TextEditor* ins, bool aValue)
{
	if (ins)
	{
		ins->SetReadOnly(aValue);
	}
}
CIMGUI_API bool igteIsReadOnly(TextEditor* ins)
{
	return ins->IsReadOnly();
}
CIMGUI_API bool igteIsTextChanged(TextEditor* ins)
{
	return ins->IsTextChanged();
}
CIMGUI_API bool igteIsCursorPositionChanged(TextEditor* ins)
{
	return ins->IsCursorPositionChanged();
}

CIMGUI_API Coordinates igteGetCursorPosition(TextEditor* ins)
{
	return ins->GetCursorPosition();
}
CIMGUI_API void igteSetCursorPosition(TextEditor* ins, const Coordinates aPosition)
{
	if (ins)
	{
		ins->SetCursorPosition(aPosition);
	}
}

CIMGUI_API void igteInsertText(TextEditor* ins, const char* aValue)
{
	if (ins)
	{
		ins->InsertText(aValue);
	}
}

CIMGUI_API void igteMoveUp(TextEditor* ins, int aAmount, bool aSelect)
{
	if (ins)
	{
		ins->MoveUp(aAmount, aSelect);
	}
}
CIMGUI_API void igteMoveDown(TextEditor* ins, int aAmount, bool aSelect)
{
	if (ins)
	{
		ins->MoveDown(aAmount, aSelect);
	}
}
CIMGUI_API void igteMoveLeft(TextEditor* ins, int aAmount, bool aSelect, bool aWordMode)
{
	if (ins)
	{
		ins->MoveLeft(aAmount, aSelect, aWordMode);
	}
}
CIMGUI_API void igteMoveRight(TextEditor* ins, int aAmount, bool aSelect, bool aWordMode)
{
	if (ins)
	{
		ins->MoveRight(aAmount, aSelect, aWordMode);
	}
}
CIMGUI_API void igteMoveTop(TextEditor* ins, bool aSelect)
{
	if (ins)
	{
		ins->MoveTop(aSelect);
	}
}
CIMGUI_API void igteMoveBottom(TextEditor* ins, bool aSelect)
{
	if (ins)
	{
		ins->MoveBottom(aSelect);
	}
}
CIMGUI_API void igteMoveHome(TextEditor* ins, bool aSelect)
{
	if (ins)
	{
		ins->MoveHome(aSelect);
	}
}
CIMGUI_API void igteMoveEnd(TextEditor* ins, bool aSelect)
{
	if (ins)
	{
		ins->MoveEnd(aSelect);
	}
}

CIMGUI_API void igteSetSelectionStart(TextEditor* ins, const Coordinates aPosition)
{
	if (ins)
	{
		ins->SetSelectionStart(aPosition);
	}
}
CIMGUI_API void igteSetSelectionEnd(TextEditor* ins, const Coordinates aPosition)
{
	if (ins)
	{
		ins->SetSelectionEnd(aPosition);
	}
}
CIMGUI_API void igteSetSelection(TextEditor* ins, const Coordinates aStart, const Coordinates aEnd, SelectionMode aMode)
{
	if (ins)
	{
		ins->SetSelection(aStart, aEnd, aMode);
	}
}
CIMGUI_API void igteSelectWordUnderCursor(TextEditor* ins)
{
	if (ins)
	{
		ins->SelectWordUnderCursor();
	}
}
CIMGUI_API void igteSelectAll(TextEditor* ins)
{
	if (ins)
	{
		ins->SelectAll();
	}
}
CIMGUI_API bool igteHasSelection(TextEditor* ins)
{
	return ins->HasSelection();
}

CIMGUI_API void igteCopy(TextEditor* ins)
{
	if (ins)
	{
		ins->Copy();
	}
}
CIMGUI_API void igteCut(TextEditor* ins)
{
	if (ins)
	{
		ins->Cut();
	}
}
CIMGUI_API void igtePaste(TextEditor* ins)
{
	if (ins)
	{
		ins->Paste();
	}
}
CIMGUI_API void igteDelete(TextEditor* ins)
{
	if (ins)
	{
		ins->Delete();
	}
}

CIMGUI_API bool igteCanUndo(TextEditor* ins)
{
	return ins->CanUndo();
}
CIMGUI_API bool igteCanRedo(TextEditor* ins)
{
	return ins->CanRedo();
}
CIMGUI_API void igteUndo(TextEditor* ins, int aSteps)
{
	if (ins)
	{
		ins->Undo(aSteps);
	}
}
CIMGUI_API void igteRedo(TextEditor* ins, int aSteps)
{
	if (ins)
	{
		ins->Redo(aSteps);
	}
}

CIMGUI_API const Palette igteGetDarkPalette(void)
{
	return igtPalettePointer(TextEditor::GetDarkPalette());
}
CIMGUI_API const Palette igteGetLightPalette(void)
{
	return igtPalettePointer(TextEditor::GetLightPalette());
}
CIMGUI_API const Palette igteGetRetroBluePalette(void)
{
	return igtPalettePointer(TextEditor::GetRetroBluePalette());
}

CIMGUI_API void igteDeleteArray(void* ptr)
{
	delete[] ptr;
}