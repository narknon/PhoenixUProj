#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DayNightLightRigSetup.h"
#include "DayLightRig.generated.h"

class ULightSettingsModCurve;

UCLASS(Blueprintable)
class DAYNIGHT_API UDayLightRig : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDayNightLightRigSetup Sun;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULightSettingsModCurve*> AltitudeMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULightSettingsModCurve*> TimeMods;
    
    UDayLightRig();
};

