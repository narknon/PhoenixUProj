#include "PhoenixRichTextBlock.h"

class UFont;

void UPhoenixRichTextBlock::SetTextKey(const FString& Key) {
}

void UPhoenixRichTextBlock::SetPhoenixText(const FString& InText) {
}

FString UPhoenixRichTextBlock::ReplaceInputActions(const FString& KeyText) {
    return TEXT("");
}

bool UPhoenixRichTextBlock::PreValidateLocalizationKey(const FString& RequestedKey) {
    return false;
}

void UPhoenixRichTextBlock::FontLoadCallback(UFont* Font) {
}

UPhoenixRichTextBlock::UPhoenixRichTextBlock() : URichTextBlock(FObjectInitializer::Get()) {
    this->Translatable = true;
    this->ScaleFontSize = true;
    this->ForceDisplayGamepadGraphics = false;
}

