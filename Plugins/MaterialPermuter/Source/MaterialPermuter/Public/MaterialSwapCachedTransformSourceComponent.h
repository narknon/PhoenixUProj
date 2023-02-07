#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapCachedTransformSourceComponent.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapCachedTransformSourceComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> Component;
    
    FMaterialSwapCachedTransformSourceComponent();
};

