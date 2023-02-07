#pragma once
#include "CoreMinimal.h"
#include "SkinFXEventTriggerFiltered.h"
#include "SkinFXEventTriggerFilteredWithDistance.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USkinFXEventTriggerFilteredWithDistance : public USkinFXEventTriggerFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistanceFromCameraMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseMaxDistanceFromCamera;
    
    USkinFXEventTriggerFilteredWithDistance();
};

