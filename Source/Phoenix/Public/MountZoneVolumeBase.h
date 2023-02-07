#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "GameFramework/Volume.h"
#include "EMountTypes.h"
#include "EPrerequisiteType.h"
#include "MountZoneVolumeBase.generated.h"

class AFlyingBroom;
class APawn;
class UCreature_MountComponent;

UCLASS(Abstract, Blueprintable, HideDropdown)
class AMountZoneVolumeBase : public AVolume {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableOnHighEndPlatforms;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 IgnoredMounts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPrerequisiteType PrerequisiteType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo MissionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 MissionStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo LockId;
    
public:
    AMountZoneVolumeBase();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsIgnored(EMountTypes InType) const;
    
    UFUNCTION(BlueprintCallable)
    static bool GetMountType(const APawn* InPawn, EMountTypes& OutType);
    
    UFUNCTION(BlueprintCallable)
    static UCreature_MountComponent* GetMount(const APawn* InPawn);
    
    UFUNCTION(BlueprintCallable)
    static bool GetEquivalentGroundType(EMountTypes InType, EMountTypes& OutType);
    
    UFUNCTION(BlueprintCallable)
    static bool GetEquivalentFlyingType(EMountTypes InType, EMountTypes& OutType);
    
    UFUNCTION(BlueprintCallable)
    static AFlyingBroom* GetBroom(const APawn* InPawn);
    
protected:
    UFUNCTION(BlueprintCallable)
    void EnableZone(bool Enable);
    
};

