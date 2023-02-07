#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ECLothInteractorValueType.h"
#include "Vector2DClothInteractorValue.generated.h"

USTRUCT(BlueprintType)
struct FVector2DClothInteractorValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECLothInteractorValueType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D Value;
    
    PHOENIX_API FVector2DClothInteractorValue();
};

