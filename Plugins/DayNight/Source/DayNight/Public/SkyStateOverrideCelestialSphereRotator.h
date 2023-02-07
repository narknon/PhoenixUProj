#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkyStateOverride.h"
#include "SkyStateOverrideCelestialSphereRotator.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class DAYNIGHT_API USkyStateOverrideCelestialSphereRotator : public USkyStateOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator Rotator;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    USkyStateOverrideCelestialSphereRotator();
};

