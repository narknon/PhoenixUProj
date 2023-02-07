#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ECLothInteractorValueType.h"
#include "VectorClothInteractorValue.generated.h"

USTRUCT(BlueprintType)
struct FVectorClothInteractorValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECLothInteractorValueType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Value;
    
    PHOENIX_API FVectorClothInteractorValue();
};

