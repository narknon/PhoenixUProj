#pragma once
#include "CoreMinimal.h"
#include "EphemerisSubroutine.h"
#include "EphemerisSubroutineTweakDirection.generated.h"

class UCurveFloat;

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API UEphemerisSubroutineTweakDirection : public UEphemerisSubroutine {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TweakAltitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TweakAzimuth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* NormalizedTimeBlend;
    
    UEphemerisSubroutineTweakDirection();
};

