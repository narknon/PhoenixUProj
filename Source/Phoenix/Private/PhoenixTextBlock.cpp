#include "PhoenixTextBlock.h"

class UFont;

void UPhoenixTextBlock::SetTextKey(const FString& Key) {
}

void UPhoenixTextBlock::SetColorTag(FDataTableRowHandle NewColorTag) {
}

bool UPhoenixTextBlock::PreValidateLocalizationKey(const FString& RequestedKey) {
    return false;
}

FString UPhoenixTextBlock::GetPhoenixText() {
    return TEXT("");
}

FSlateFontInfo UPhoenixTextBlock::GetFontInfo() {
    return FSlateFontInfo{};
}

float UPhoenixTextBlock::GetCurrentFontScale() {
    return 0.0f;
}

FDataTableRowHandle UPhoenixTextBlock::GetColorTag() {
    return FDataTableRowHandle{};
}

void UPhoenixTextBlock::FontLoadCallback(UFont* LoadedFont) {
}

UPhoenixTextBlock::UPhoenixTextBlock() {
    this->Translatable = true;
    this->ScaleFontSize = true;
}

