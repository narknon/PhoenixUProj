#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapSphereSelectionActor.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapSphereSelectionActor {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double LastTouched;
    
    FMaterialSwapSphereSelectionActor();
};

