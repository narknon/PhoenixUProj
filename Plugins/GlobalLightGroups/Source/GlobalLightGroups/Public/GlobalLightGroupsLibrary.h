#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HermesBPDelegateHandle.h"
#include "EGlobalLightGroupsMaskLockState.h"
#include "GlobalLightGroupsGroupName.h"
#include "GlobalLightGroupsMask.h"
#include "GlobalLightGroupsRegionName.h"
#include "GlobalLightGroupsTimeHMSOnOff.h"
#include "GlobalLightGroupsTimeOnOff.h"
#include "GlobalLightGroupsTimeSunOnOff.h"
#include "LightComponentMessage.h"
#include "LightComponentScheduleName.h"
#include "LightGroupBoundComponentSettings.h"
#include "LightGroupMessage.h"
#include "GlobalLightGroupsLibrary.generated.h"

class AActor;
class AGlobalLightGroupsMaster;
class UObject;
class USceneComponent;

UCLASS(Blueprintable)
class GLOBALLIGHTGROUPS_API UGlobalLightGroupsLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FLightGroupMessageDelegate, const UObject*, Caller, const FLightGroupMessage&, Message);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FLightComponentMessageDelegate, const UObject*, Caller, const FLightComponentMessage&, Message);
    
    UGlobalLightGroupsLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void ValidLightGroup(UObject* WorldContextObject, FName Region, FName Group, bool& bValid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void ValidateMyRegion(UObject* WorldContextObject, FName Region, FName& ValidRegion);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void UnbindComponentVisibility(UObject* WorldContextObject, FName Region, FName Group, USceneComponent* SceneComponent);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void UnbindComponentsVisibility(UObject* WorldContextObject, FName Region, FName Group);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void TurnOnLightGroups(UObject* WorldContextObject, FName Region, FGlobalLightGroupsMask GroupMask);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void TurnOnLightGroup(UObject* WorldContextObject, FName Region, FName Group);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void TurnOffLightGroups(UObject* WorldContextObject, FName Region, FGlobalLightGroupsMask GroupMask);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void TurnOffLightGroup(UObject* WorldContextObject, FName Region, FName Group);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void TestLightRegionAndGroup(FName RegionA, FName GroupA, FName RegionB, FName GroupB, bool& bMatch);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetLightGroupLocks(UObject* WorldContextObject, FName Region, FGlobalLightGroupsMask GroupMask, EGlobalLightGroupsMaskLockState State);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetLightGroupLock(UObject* WorldContextObject, FName Region, FName Group, EGlobalLightGroupsMaskLockState State);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RemoveLightComponentSchedule(UObject* WorldContextObject, USceneComponent* Light);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FGlobalLightGroupsMask NamesLightGroupsMask(UObject* WorldContextObject, FName Region, const TArray<FName>& Groups);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FGlobalLightGroupsMask NameLightGroupsMask(UObject* WorldContextObject, FName Region, const FName& Group);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGlobalLightGroupsTimeOnOff MakeTimeOnOffSun(const FGlobalLightGroupsTimeSunOnOff& SunOnOff);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGlobalLightGroupsTimeOnOff MakeTimeOnOffHMS(const FGlobalLightGroupsTimeHMSOnOff& TimeOnOff);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LockAllLightGroups(UObject* WorldContextObject, FName Region);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LightGroupGetHermesEvent(UObject* WorldContextObject, FName Region, FName Group, FName& HermesEvent);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LightGroupEnableHermesEvent(UObject* WorldContextObject, FName Region, FName Group, FName HermesEvent);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LightGroupDisableHermesEvent(UObject* WorldContextObject, FName Region, FName Group);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LightComponentSetSchedule(UObject* WorldContextObject, USceneComponent* Light, FName ScheduleName, bool& bSuccess, bool bToggleChildren);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LightComponentScheduleToggleChildren(UObject* WorldContextObject, USceneComponent* Light, bool bToggleChildren);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LightComponentIsScheduled(UObject* WorldContextObject, USceneComponent* Light, bool& bIsScheduled);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LightComponentGetScheduleName(UObject* WorldContextObject, USceneComponent* Light, FName& ScheduleName);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LightComponentGetHermesEvent(UObject* WorldContextObject, USceneComponent* Light, FName& HermesEvent);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LightComponentEnableHermesEvent(UObject* WorldContextObject, USceneComponent* Light, FName HermesEvent);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LightComponentDisableHermesEvent(UObject* WorldContextObject, USceneComponent* Light);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void IsLightComponentScheduleEnabled(UObject* WorldContextObject, USceneComponent* Light, bool& bEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void HermesGetLightGroupMessageDelegateName(UGlobalLightGroupsLibrary::FLightGroupMessageDelegate Event, FName& EventName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void HermesGetLightComponentMessageDelegateName(UGlobalLightGroupsLibrary::FLightComponentMessageDelegate Event, FName& EventName);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindLightGroupMessage(UGlobalLightGroupsLibrary::FLightGroupMessageDelegate Event, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindLightComponentMessage(UGlobalLightGroupsLibrary::FLightComponentMessageDelegate Event, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetRegionFromLocation(UObject* WorldContextObject, FVector Location, FName& Region);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetRegionFromActor(UObject* WorldContextObject, AActor* Actor, FName& Region);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetMyRegion(UObject* WorldContextObject, FName& Region);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetLightGroupLock(UObject* WorldContextObject, FName Region, FName Group, EGlobalLightGroupsMaskLockState& State);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetGlobalLightGroupsMaster(UObject* WorldContextObject, AGlobalLightGroupsMaster*& GlobalLightGroupsMaster);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void EnableLightGroupSchedule(UObject* WorldContextObject, FName Region, FName Group);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void EnableLightComponentSchedule(UObject* WorldContextObject, USceneComponent* Light);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DisableLightGroupSchedule(UObject* WorldContextObject, FName Region, FName Group);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DisableLightComponentSchedule(UObject* WorldContextObject, USceneComponent* Light);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName Conv_RegionDropDownToRegionName(FGlobalLightGroupsRegionName RegionDropdown);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName Conv_GroupDropDownToLightComponentScheduleName(FLightComponentScheduleName LightComponentScheduleDropdown);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName Conv_GroupDropDownToGroupName(FGlobalLightGroupsGroupName GroupDropdown);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ClearAllLightGroupLocks(UObject* WorldContextObject, FName Region);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void CheckLightGroups(UObject* WorldContextObject, FName Region, FGlobalLightGroupsMask GroupMask, bool& bIsOn);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void CheckLightGroup(UObject* WorldContextObject, FName Region, FName Group, bool& bIsOn);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void BindComponentVisibility(UObject* WorldContextObject, FName Region, FName Group, USceneComponent* SceneComponent, FLightGroupBoundComponentSettings Settings);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void BindComponentsVisibility(UObject* WorldContextObject, FName Region, FName Group, const TArray<USceneComponent*>& SceneComponents, FLightGroupBoundComponentSettings Settings);
    
};

