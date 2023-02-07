#include "ConsoleVariableLienFunctionLibrary.h"

class UConsoleVariableLienAsset;
class UObject;

void UConsoleVariableLienFunctionLibrary::ConsoleVariableRemoveLiens(UObject* LienHolder, bool& bSuccess) {
}

void UConsoleVariableLienFunctionLibrary::ConsoleVariableRemoveLien(UObject* LienHolder, const FString& Variable, bool& bSuccess) {
}

void UConsoleVariableLienFunctionLibrary::ConsoleVariableRemoveAssetLiens(UObject* LienHolder, UConsoleVariableLienAsset* LienAsset, bool& bSuccess) {
}

void UConsoleVariableLienFunctionLibrary::ConsoleVariableHasLien(UObject* LienHolder, const FString& Variable, bool& bHasALien) {
}

void UConsoleVariableLienFunctionLibrary::ConsoleVariableHasAnyLiens(UObject* LienHolder, bool& bHasALien) {
}

void UConsoleVariableLienFunctionLibrary::ConsoleVariableAssetLiensActivate(UObject* LienHolder, UConsoleVariableLienAsset* LienAsset, bool& bSuccess, bool bActivate) {
}

void UConsoleVariableLienFunctionLibrary::ConsoleVariableAddStringLien(UObject* LienHolder, const FString& Variable, const FString& Value, bool& bSuccess, float Priority) {
}

void UConsoleVariableLienFunctionLibrary::ConsoleVariableAddIntegerLien(UObject* LienHolder, const FString& Variable, int32 Value, bool& bSuccess, float Priority) {
}

void UConsoleVariableLienFunctionLibrary::ConsoleVariableAddFloatLien(UObject* LienHolder, const FString& Variable, float Value, bool& bSuccess, float Priority) {
}

void UConsoleVariableLienFunctionLibrary::ConsoleVariableAddDefaultLien(UObject* LienHolder, const FString& Variable, bool& bSuccess, float Priority) {
}

void UConsoleVariableLienFunctionLibrary::ConsoleVariableAddAssetLiens(UObject* LienHolder, UConsoleVariableLienAsset* LienAsset, bool& bSuccess) {
}

UConsoleVariableLienFunctionLibrary::UConsoleVariableLienFunctionLibrary() {
}

