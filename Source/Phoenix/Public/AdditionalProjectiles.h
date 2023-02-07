#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AdditionalProjectiles.generated.h"

class AMunitionType_Base;

USTRUCT(BlueprintType)
struct FAdditionalProjectiles {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> MunitionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Delay;
    
    PHOENIX_API FAdditionalProjectiles();
};

