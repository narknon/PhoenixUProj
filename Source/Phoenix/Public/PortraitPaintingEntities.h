#pragma once
#include "CoreMinimal.h"
#include "PortraitPaintingEntity.h"
#include "PortraitPaintingEntities.generated.h"

USTRUCT(BlueprintType)
struct FPortraitPaintingEntities {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPortraitPaintingEntity> Entities;
    
    PHOENIX_API FPortraitPaintingEntities();
};

