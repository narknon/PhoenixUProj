#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimpleCapsule.h"
#include "SimpleCapsuleSurfacePointNormal.generated.h"

USTRUCT(BlueprintType)
struct FSimpleCapsuleSurfacePointNormal : public FSimpleCapsule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Point;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Normal;
    
    PHOENIX_API FSimpleCapsuleSurfacePointNormal();
};

