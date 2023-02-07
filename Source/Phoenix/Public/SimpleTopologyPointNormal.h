#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimpleTopologyPointNormal.generated.h"

USTRUCT(BlueprintType)
struct FSimpleTopologyPointNormal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Point;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Normal;
    
    PHOENIX_API FSimpleTopologyPointNormal();
};

