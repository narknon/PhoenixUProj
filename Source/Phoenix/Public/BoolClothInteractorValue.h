#pragma once
#include "CoreMinimal.h"
#include "EBoolClothInteractorValueType.h"
#include "BoolClothInteractorValue.generated.h"

USTRUCT(BlueprintType)
struct FBoolClothInteractorValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBoolClothInteractorValueType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Value;
    
    PHOENIX_API FBoolClothInteractorValue();
};

