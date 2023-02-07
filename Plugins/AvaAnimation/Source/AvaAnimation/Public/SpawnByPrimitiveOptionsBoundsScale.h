#pragma once
#include "CoreMinimal.h"
#include "SpawnByPrimitiveOptions.h"
#include "SpawnByPrimitiveOptionsBoundsScale.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USpawnByPrimitiveOptionsBoundsScale : public USpawnByPrimitiveOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BoundsScale;
    
    USpawnByPrimitiveOptionsBoundsScale();
};

