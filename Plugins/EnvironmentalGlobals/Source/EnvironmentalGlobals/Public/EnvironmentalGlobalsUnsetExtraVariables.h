#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsUnsetExtraVariables.generated.h"

USTRUCT(BlueprintType)
struct ENVIRONMENTALGLOBALS_API FEnvironmentalGlobalsUnsetExtraVariables {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> UnsetScalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> UnsetColors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> UnsetVectors;
    
    FEnvironmentalGlobalsUnsetExtraVariables();
};

