#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsExtraScalarVariable.generated.h"

USTRUCT(BlueprintType)
struct ENVIRONMENTALGLOBALS_API FEnvironmentalGlobalsExtraScalarVariable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    FEnvironmentalGlobalsExtraScalarVariable();
};

