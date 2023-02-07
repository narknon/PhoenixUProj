#pragma once
#include "CoreMinimal.h"
#include "SpawnByPrimitiveOptions.h"
#include "SpawnByPrimitiveOptionsGenerateOverlaps.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USpawnByPrimitiveOptionsGenerateOverlaps : public USpawnByPrimitiveOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGenerateOverlaps;
    
    USpawnByPrimitiveOptionsGenerateOverlaps();
};

