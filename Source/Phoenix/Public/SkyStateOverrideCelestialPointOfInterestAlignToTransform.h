#pragma once
#include "CoreMinimal.h"
#include "SkyStateOverrideCelestialPointOfInterestAlignTo.h"
#include "SkyStateOverrideCelestialPointOfInterestAlignToTransform.generated.h"

class UTransformProvider;

UCLASS(Blueprintable, EditInlineNew)
class USkyStateOverrideCelestialPointOfInterestAlignToTransform : public USkyStateOverrideCelestialPointOfInterestAlignTo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* OrientTo;
    
    USkyStateOverrideCelestialPointOfInterestAlignToTransform();
};

