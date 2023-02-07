#pragma once
#include "CoreMinimal.h"
#include "DayNightEventSystem.h"
#include "SkyStateOverrides.h"
#include "TimeOverrides.h"
#include "DayNightWorldInfo.generated.h"

class UDayNightLightControllerComponent;
class UDayNightMasterComponent;
class UEphemerisBasis;
class UObject;

USTRUCT(BlueprintType)
struct DAYNIGHT_API FDayNightWorldInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEphemerisBasis* LevelDefaultBasis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEphemerisBasis* ForceBasis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEphemerisBasis* OverrideBasis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDayNightMasterComponent* Master;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> DayNightOverrides;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> BasisOverrides;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<UDayNightLightControllerComponent>> LightControllers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimeOverrides TimeOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSkyStateOverrides SkyStateOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDayNightEventSystem EventSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bEventSystemReset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bMissingComputeMasterTemplate;
    
    FDayNightWorldInfo();
};

