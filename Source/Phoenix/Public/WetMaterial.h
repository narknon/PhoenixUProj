#pragma once
#include "CoreMinimal.h"
#include "WetMaterial.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FWetMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMaterialInstanceDynamic> MaterialInstanceDynamic;
    
    PHOENIX_API FWetMaterial();
};

