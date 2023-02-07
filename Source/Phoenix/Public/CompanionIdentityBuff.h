#pragma once
#include "CoreMinimal.h"
#include "CompanionIdentityBuff.generated.h"

USTRUCT(BlueprintType)
struct FCompanionIdentityBuff {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AbilityName;
    
    PHOENIX_API FCompanionIdentityBuff();
};

