#pragma once
#include "CoreMinimal.h"
#include "BurningMaterial.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FBurningMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* MaterialInstanceDynamic;
    
    PHOENIX_API FBurningMaterial();
};

