#include "ConsoleVariableWatcher.h"

class UObject;
class UWatchedConsoleVariableBool;
class UWatchedConsoleVariableFloat;
class UWatchedConsoleVariableInt;

void AConsoleVariableWatcher::WatchIntConsoleVariable(UObject* WorldContextObject, const FString& ConsoleVariable, UWatchedConsoleVariableInt*& Variable) {
}

void AConsoleVariableWatcher::WatchFloatConsoleVariable(UObject* WorldContextObject, const FString& ConsoleVariable, UWatchedConsoleVariableFloat*& Variable) {
}

void AConsoleVariableWatcher::WatchBoolConsoleVariable(UObject* WorldContextObject, const FString& ConsoleVariable, UWatchedConsoleVariableBool*& Variable) {
}

void AConsoleVariableWatcher::SetConsoleVariableAsInt(const FString& ConsoleVariable, int32 Value, bool& bExists) {
}

void AConsoleVariableWatcher::SetConsoleVariableAsFloat(const FString& ConsoleVariable, float Value, bool& bExists) {
}

void AConsoleVariableWatcher::SetConsoleVariableAsBool(const FString& ConsoleVariable, bool Value, bool& bExists) {
}

void AConsoleVariableWatcher::GetConsoleVariableAsInt(const FString& ConsoleVariable, int32& Value, bool& bExists, int32 DefaultValue) {
}

void AConsoleVariableWatcher::GetConsoleVariableAsFloat(const FString& ConsoleVariable, float& Value, bool& bExists, float DefaultValue) {
}

void AConsoleVariableWatcher::GetConsoleVariableAsBool(const FString& ConsoleVariable, bool& bValue, bool& bExists, bool bDefaultValue) {
}

void AConsoleVariableWatcher::CreateConsoleVariableAsInt(const FString& ConsoleVariable, int32 DefaultValue, const FString& Help, bool& bSuccess) {
}

void AConsoleVariableWatcher::CreateConsoleVariableAsFloat(const FString& ConsoleVariable, float DefaultValue, const FString& Help, bool& bSuccess) {
}

void AConsoleVariableWatcher::CreateConsoleVariableAsBool(const FString& ConsoleVariable, bool DefaultValue, const FString& Help, bool& bSuccess) {
}

void AConsoleVariableWatcher::ConsoleVariableExists(const FString& ConsoleVariable, bool& bExists) {
}

AConsoleVariableWatcher::AConsoleVariableWatcher(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

