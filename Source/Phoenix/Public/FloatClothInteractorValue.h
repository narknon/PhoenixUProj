#pragma once
#include "CoreMinimal.h"
#include "ECLothInteractorValueType.h"
#include "FloatClothInteractorValue.generated.h"

USTRUCT(BlueprintType)
struct FFloatClothInteractorValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECLothInteractorValueType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    PHOENIX_API FFloatClothInteractorValue();
};

