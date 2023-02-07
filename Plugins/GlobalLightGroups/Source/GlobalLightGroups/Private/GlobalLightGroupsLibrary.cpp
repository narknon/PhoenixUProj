#include "GlobalLightGroupsLibrary.h"

class AActor;
class AGlobalLightGroupsMaster;
class UObject;
class USceneComponent;

void UGlobalLightGroupsLibrary::ValidLightGroup(UObject* WorldContextObject, FName Region, FName Group, bool& bValid) {
}

void UGlobalLightGroupsLibrary::ValidateMyRegion(UObject* WorldContextObject, FName Region, FName& ValidRegion) {
}

void UGlobalLightGroupsLibrary::UnbindComponentVisibility(UObject* WorldContextObject, FName Region, FName Group, USceneComponent* SceneComponent) {
}

void UGlobalLightGroupsLibrary::UnbindComponentsVisibility(UObject* WorldContextObject, FName Region, FName Group) {
}

void UGlobalLightGroupsLibrary::TurnOnLightGroups(UObject* WorldContextObject, FName Region, FGlobalLightGroupsMask GroupMask) {
}

void UGlobalLightGroupsLibrary::TurnOnLightGroup(UObject* WorldContextObject, FName Region, FName Group) {
}

void UGlobalLightGroupsLibrary::TurnOffLightGroups(UObject* WorldContextObject, FName Region, FGlobalLightGroupsMask GroupMask) {
}

void UGlobalLightGroupsLibrary::TurnOffLightGroup(UObject* WorldContextObject, FName Region, FName Group) {
}

void UGlobalLightGroupsLibrary::TestLightRegionAndGroup(FName RegionA, FName GroupA, FName RegionB, FName GroupB, bool& bMatch) {
}

void UGlobalLightGroupsLibrary::SetLightGroupLocks(UObject* WorldContextObject, FName Region, FGlobalLightGroupsMask GroupMask, EGlobalLightGroupsMaskLockState State) {
}

void UGlobalLightGroupsLibrary::SetLightGroupLock(UObject* WorldContextObject, FName Region, FName Group, EGlobalLightGroupsMaskLockState State) {
}

void UGlobalLightGroupsLibrary::RemoveLightComponentSchedule(UObject* WorldContextObject, USceneComponent* Light) {
}

FGlobalLightGroupsMask UGlobalLightGroupsLibrary::NamesLightGroupsMask(UObject* WorldContextObject, FName Region, const TArray<FName>& Groups) {
    return FGlobalLightGroupsMask{};
}

FGlobalLightGroupsMask UGlobalLightGroupsLibrary::NameLightGroupsMask(UObject* WorldContextObject, FName Region, const FName& Group) {
    return FGlobalLightGroupsMask{};
}

FGlobalLightGroupsTimeOnOff UGlobalLightGroupsLibrary::MakeTimeOnOffSun(const FGlobalLightGroupsTimeSunOnOff& SunOnOff) {
    return FGlobalLightGroupsTimeOnOff{};
}

FGlobalLightGroupsTimeOnOff UGlobalLightGroupsLibrary::MakeTimeOnOffHMS(const FGlobalLightGroupsTimeHMSOnOff& TimeOnOff) {
    return FGlobalLightGroupsTimeOnOff{};
}

void UGlobalLightGroupsLibrary::LockAllLightGroups(UObject* WorldContextObject, FName Region) {
}

void UGlobalLightGroupsLibrary::LightGroupGetHermesEvent(UObject* WorldContextObject, FName Region, FName Group, FName& HermesEvent) {
}

void UGlobalLightGroupsLibrary::LightGroupEnableHermesEvent(UObject* WorldContextObject, FName Region, FName Group, FName HermesEvent) {
}

void UGlobalLightGroupsLibrary::LightGroupDisableHermesEvent(UObject* WorldContextObject, FName Region, FName Group) {
}

void UGlobalLightGroupsLibrary::LightComponentSetSchedule(UObject* WorldContextObject, USceneComponent* Light, FName ScheduleName, bool& bSuccess, bool bToggleChildren) {
}

void UGlobalLightGroupsLibrary::LightComponentScheduleToggleChildren(UObject* WorldContextObject, USceneComponent* Light, bool bToggleChildren) {
}

void UGlobalLightGroupsLibrary::LightComponentIsScheduled(UObject* WorldContextObject, USceneComponent* Light, bool& bIsScheduled) {
}

void UGlobalLightGroupsLibrary::LightComponentGetScheduleName(UObject* WorldContextObject, USceneComponent* Light, FName& ScheduleName) {
}

void UGlobalLightGroupsLibrary::LightComponentGetHermesEvent(UObject* WorldContextObject, USceneComponent* Light, FName& HermesEvent) {
}

void UGlobalLightGroupsLibrary::LightComponentEnableHermesEvent(UObject* WorldContextObject, USceneComponent* Light, FName HermesEvent) {
}

void UGlobalLightGroupsLibrary::LightComponentDisableHermesEvent(UObject* WorldContextObject, USceneComponent* Light) {
}

void UGlobalLightGroupsLibrary::IsLightComponentScheduleEnabled(UObject* WorldContextObject, USceneComponent* Light, bool& bEnabled) {
}

void UGlobalLightGroupsLibrary::HermesGetLightGroupMessageDelegateName(UGlobalLightGroupsLibrary::FLightGroupMessageDelegate Event, FName& EventName) {
}

void UGlobalLightGroupsLibrary::HermesGetLightComponentMessageDelegateName(UGlobalLightGroupsLibrary::FLightComponentMessageDelegate Event, FName& EventName) {
}

void UGlobalLightGroupsLibrary::HermesBindLightGroupMessage(UGlobalLightGroupsLibrary::FLightGroupMessageDelegate Event, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UGlobalLightGroupsLibrary::HermesBindLightComponentMessage(UGlobalLightGroupsLibrary::FLightComponentMessageDelegate Event, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UGlobalLightGroupsLibrary::GetRegionFromLocation(UObject* WorldContextObject, FVector Location, FName& Region) {
}

void UGlobalLightGroupsLibrary::GetRegionFromActor(UObject* WorldContextObject, AActor* Actor, FName& Region) {
}

void UGlobalLightGroupsLibrary::GetMyRegion(UObject* WorldContextObject, FName& Region) {
}

void UGlobalLightGroupsLibrary::GetLightGroupLock(UObject* WorldContextObject, FName Region, FName Group, EGlobalLightGroupsMaskLockState& State) {
}

void UGlobalLightGroupsLibrary::GetGlobalLightGroupsMaster(UObject* WorldContextObject, AGlobalLightGroupsMaster*& GlobalLightGroupsMaster) {
}

void UGlobalLightGroupsLibrary::EnableLightGroupSchedule(UObject* WorldContextObject, FName Region, FName Group) {
}

void UGlobalLightGroupsLibrary::EnableLightComponentSchedule(UObject* WorldContextObject, USceneComponent* Light) {
}

void UGlobalLightGroupsLibrary::DisableLightGroupSchedule(UObject* WorldContextObject, FName Region, FName Group) {
}

void UGlobalLightGroupsLibrary::DisableLightComponentSchedule(UObject* WorldContextObject, USceneComponent* Light) {
}

FName UGlobalLightGroupsLibrary::Conv_RegionDropDownToRegionName(FGlobalLightGroupsRegionName RegionDropdown) {
    return NAME_None;
}

FName UGlobalLightGroupsLibrary::Conv_GroupDropDownToLightComponentScheduleName(FLightComponentScheduleName LightComponentScheduleDropdown) {
    return NAME_None;
}

FName UGlobalLightGroupsLibrary::Conv_GroupDropDownToGroupName(FGlobalLightGroupsGroupName GroupDropdown) {
    return NAME_None;
}

void UGlobalLightGroupsLibrary::ClearAllLightGroupLocks(UObject* WorldContextObject, FName Region) {
}

void UGlobalLightGroupsLibrary::CheckLightGroups(UObject* WorldContextObject, FName Region, FGlobalLightGroupsMask GroupMask, bool& bIsOn) {
}

void UGlobalLightGroupsLibrary::CheckLightGroup(UObject* WorldContextObject, FName Region, FName Group, bool& bIsOn) {
}

void UGlobalLightGroupsLibrary::BindComponentVisibility(UObject* WorldContextObject, FName Region, FName Group, USceneComponent* SceneComponent, FLightGroupBoundComponentSettings Settings) {
}

void UGlobalLightGroupsLibrary::BindComponentsVisibility(UObject* WorldContextObject, FName Region, FName Group, const TArray<USceneComponent*>& SceneComponents, FLightGroupBoundComponentSettings Settings) {
}

UGlobalLightGroupsLibrary::UGlobalLightGroupsLibrary() {
}

