#pragma once
#include "CoreMinimal.h"
#include "GameplayPropertyNumeric.h"
#include "GameplayProperty_Float.generated.h"

USTRUCT(BlueprintType)
struct FGameplayProperty_Float : public FGameplayPropertyNumeric {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Current;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Base;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Min;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Max;
    
    GAMEPLAYMODS_API FGameplayProperty_Float();
};

