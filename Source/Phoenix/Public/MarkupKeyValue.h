#pragma once
#include "CoreMinimal.h"
#include "EMarkupType.h"
#include "MarkupKeyValue.generated.h"

USTRUCT(BlueprintType)
struct FMarkupKeyValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMarkupType Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    PHOENIX_API FMarkupKeyValue();
};

