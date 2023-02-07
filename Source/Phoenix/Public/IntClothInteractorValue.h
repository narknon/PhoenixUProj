#pragma once
#include "CoreMinimal.h"
#include "ECLothInteractorValueType.h"
#include "IntClothInteractorValue.generated.h"

USTRUCT(BlueprintType)
struct FIntClothInteractorValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECLothInteractorValueType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    PHOENIX_API FIntClothInteractorValue();
};

