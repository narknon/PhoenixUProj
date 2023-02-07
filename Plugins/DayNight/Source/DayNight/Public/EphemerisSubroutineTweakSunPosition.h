#pragma once
#include "CoreMinimal.h"
#include "EphemerisSubroutineTweakDirection.h"
#include "EphemerisSubroutineTweakSunPosition.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineTweakSunPosition : public UEphemerisSubroutineTweakDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFullSun;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSunDisk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSunLight;
    
    UEphemerisSubroutineTweakSunPosition();
};

