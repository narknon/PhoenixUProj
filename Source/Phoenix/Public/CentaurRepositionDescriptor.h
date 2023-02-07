#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CentaurRepositionDescriptor.generated.h"

USTRUCT(BlueprintType)
struct FCentaurRepositionDescriptor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D RepositionToTargetRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D HoldPositionTargetRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IdealTargetRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D HeadingToTargetRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RepositionTimeout;
    
    PHOENIX_API FCentaurRepositionDescriptor();
};

