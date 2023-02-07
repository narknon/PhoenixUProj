#include "ToolSetComponent.h"

class ATool;
class UObject;
class USceneComponent;
class UToolRecord;

void UToolSetComponent::StartSettingWhitelistedTools(const TArray<UToolRecord*>& InTools, EStandardManagedPriority InPriority, const UObject* InProvider) {
}

void UToolSetComponent::StartSettingBlacklistedTools(const TArray<UToolRecord*>& InTools, EStandardManagedPriority InPriority, const UObject* InProvider) {
}

void UToolSetComponent::SetAttachmentParent(USceneComponent* InOwnerMesh) {
}

bool UToolSetComponent::IsToolUsageAllowed(const UToolRecord* ToolRecord) const {
    return false;
}

TArray<UToolRecord*> UToolSetComponent::GetToolRecords() const {
    return TArray<UToolRecord*>();
}

int32 UToolSetComponent::GetToolRecordIndex(const UToolRecord* ToolRecord) const {
    return 0;
}

UToolRecord* UToolSetComponent::GetToolRecordByName(const FName Name) const {
    return NULL;
}

USceneComponent* UToolSetComponent::GetAttachmentParent() const {
    return NULL;
}

int32 UToolSetComponent::GetActiveToolRecordIndex() const {
    return 0;
}

ATool* UToolSetComponent::GetActiveTool() const {
    return NULL;
}

void UToolSetComponent::FinishSettingWhitelistedTools(EStandardManagedPriority InPriority, const UObject* InProvider) {
}

void UToolSetComponent::FinishSettingBlacklistedTools(EStandardManagedPriority InPriority, const UObject* InProvider) {
}

ATool* UToolSetComponent::ClearActiveTool() {
    return NULL;
}

void UToolSetComponent::AsyncLoadToolByName(const FName Name) {
}

ATool* UToolSetComponent::ActivateToolByName(const FName Name) {
    return NULL;
}

ATool* UToolSetComponent::ActivateTool(UToolRecord* ToolRecord) {
    return NULL;
}

ATool* UToolSetComponent::ActivateExistingTool(ATool* Tool) {
    return NULL;
}

UToolSetComponent::UToolSetComponent() {
}

