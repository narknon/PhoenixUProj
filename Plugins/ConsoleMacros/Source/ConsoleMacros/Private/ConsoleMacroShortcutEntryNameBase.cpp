#include "ConsoleMacroShortcutEntryNameBase.h"

FConsoleMacroShortcutEntryNameBase::FConsoleMacroShortcutEntryNameBase() {
    this->Scope = EConsoleMacroCommandScope::CookedAndEditor;
    this->bNoQuery = false;
    this->bAutoRestoreValue = false;
}

