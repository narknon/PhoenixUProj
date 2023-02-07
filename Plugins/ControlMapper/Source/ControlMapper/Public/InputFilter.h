#pragma once
#include "CoreMinimal.h"
#include "InputFilter.generated.h"

USTRUCT(BlueprintType)
struct CONTROLMAPPER_API FInputFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FilterName;
    
    FInputFilter();
};

