#pragma once
#include "CoreMinimal.h"
#include "EPostCalculationRoundingType.h"
#include "GameplayPropertyNumeric.h"
#include "GameplayProperty_Int.generated.h"

USTRUCT(BlueprintType)
struct FGameplayProperty_Int : public FGameplayPropertyNumeric {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 Current;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Base;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Min;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Max;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPostCalculationRoundingType RoundingType;
    
    GAMEPLAYMODS_API FGameplayProperty_Int();
};

