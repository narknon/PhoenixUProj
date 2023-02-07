#pragma once
#include "CoreMinimal.h"
#include "EOrientToSlerpType.h"
#include "OrientToSlerp.generated.h"

USTRUCT(BlueprintType)
struct FOrientToSlerp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOrientToSlerpType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Filter;
    
    PHOENIX_API FOrientToSlerp();
};

