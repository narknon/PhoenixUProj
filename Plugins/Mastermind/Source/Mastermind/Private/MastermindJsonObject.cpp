#include "MastermindJsonObject.h"

class UMastermindJsonObject;

FString UMastermindJsonObject::ToJsonString() {
    return TEXT("");
}

void UMastermindJsonObject::SetStringListField(const FString& InKey, const TArray<FString>& InValues) {
}

void UMastermindJsonObject::SetStringField(const FString& InKey, const FString& InValue) {
}

void UMastermindJsonObject::SetObjectListField(const FString& InKey, const TArray<UMastermindJsonObject*>& InValues) {
}

void UMastermindJsonObject::SetObjectField(const FString& InKey, const UMastermindJsonObject* InValue) {
}

void UMastermindJsonObject::SetNumberListField(const FString& InKey, const TArray<float>& InValues) {
}

void UMastermindJsonObject::SetNumberField(const FString& InKey, float InValue) {
}

void UMastermindJsonObject::SetNullField(const FString& InKey) {
}

void UMastermindJsonObject::SetBooleanListField(const FString& InKey, const TArray<bool>& InValues) {
}

void UMastermindJsonObject::SetBooleanField(const FString& InKey, bool InValue) {
}

bool UMastermindJsonObject::HasAnyFields() const {
    return false;
}

TArray<FString> UMastermindJsonObject::GetStringListFieldOrDefault(const FString& InKey, bool& bOutHasField) {
    return TArray<FString>();
}

FString UMastermindJsonObject::GetStringFieldOrDefault(const FString& InKey, bool& bOutHasField) {
    return TEXT("");
}

TArray<UMastermindJsonObject*> UMastermindJsonObject::GetObjectListFieldOrDefault(const FString& InKey, bool& bOutHasField) {
    return TArray<UMastermindJsonObject*>();
}

UMastermindJsonObject* UMastermindJsonObject::GetObjectFieldOrDefault(const FString& InKey, bool& bOutHasField) {
    return NULL;
}

TArray<float> UMastermindJsonObject::GetNumberListFieldOrDefault(const FString& InKey, bool& bOutHasField) {
    return TArray<float>();
}

float UMastermindJsonObject::GetNumberFieldOrDefault(const FString& InKey, bool& bOutHasField) {
    return 0.0f;
}

TArray<bool> UMastermindJsonObject::GetBooleanListFieldOrDefault(const FString& InKey, bool& bOutHasField) {
    return TArray<bool>();
}

bool UMastermindJsonObject::GetBooleanFieldOrDefault(const FString& InKey, bool& bOutHasField) {
    return false;
}

UMastermindJsonObject::UMastermindJsonObject() {
}

