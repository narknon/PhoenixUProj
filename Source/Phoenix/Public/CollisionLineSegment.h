#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CollisionLineSegment.generated.h"

USTRUCT(BlueprintType)
struct FCollisionLineSegment {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Origin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Dir;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Length;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ClosestIntersectionT;
    
public:
    PHOENIX_API FCollisionLineSegment();
};

