#pragma once
#include "CoreMinimal.h"
#include "UseItemAbilityInfo.generated.h"

USTRUCT(BlueprintType)
struct FUseItemAbilityInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AbilityName;
    
    PHOENIX_API FUseItemAbilityInfo();
};

