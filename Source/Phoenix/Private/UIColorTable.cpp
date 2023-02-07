#include "UIColorTable.h"

FLinearColor UUIColorTable::GetColorByTag(FName pColorTag) {
    return FLinearColor{};
}

FLinearColor UUIColorTable::GetColorByRowHandleBP(FDataTableRowHandle pRowHandle) {
    return FLinearColor{};
}

FLinearColor UUIColorTable::GetColorByRowHandle(FDataTableRowHandle& pRowHandle) {
    return FLinearColor{};
}

FLinearColor UUIColorTable::CreateColorBlindColor(EColorVisionDeficiency pColorType, FLinearColor pColor, int32 bCorrectDeficiency, int32 bSimulateCorrectionWithDeficiency, int32 Severity) {
    return FLinearColor{};
}

UUIColorTable::UUIColorTable() {
}

