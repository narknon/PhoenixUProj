#include "PhoenixPlayerInput.h"

EKeyLayout UPhoenixPlayerInput::GetKeyLayout() const {
    return EKeyLayout::QWERTY;
}

void UPhoenixPlayerInput::ForceRebuildTransposedKeyMaps(bool bRestoreDefaults, EKeyLayout InCurrentLayout, EKeyLayout InNewLayout) {
}

UPhoenixPlayerInput::UPhoenixPlayerInput() {
}

