#pragma once
#include "CoreMinimal.h"
#include "MapDungeonSubdivisionData.generated.h"

USTRUCT(BlueprintType)
struct FMapDungeonSubdivisionData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoomFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Owner;
    
    PHOENIX_API FMapDungeonSubdivisionData();
};

