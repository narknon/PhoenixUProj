#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ConditionalStaticMeshPool.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FConditionalStaticMeshPool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D TimeRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UStaticMesh>> StaticMeshPool;
    
    AVAANIMATION_API FConditionalStaticMeshPool();
};

