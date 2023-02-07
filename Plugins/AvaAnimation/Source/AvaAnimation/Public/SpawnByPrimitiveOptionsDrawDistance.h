#pragma once
#include "CoreMinimal.h"
#include "SpawnByPrimitiveOptions.h"
#include "SpawnByPrimitiveOptionsDrawDistance.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USpawnByPrimitiveOptionsDrawDistance : public USpawnByPrimitiveOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDrawDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CullDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeverDistanceCull;
    
    USpawnByPrimitiveOptionsDrawDistance();
};

