#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsExtraColorVariable.h"
#include "EnvironmentalGlobalsExtraScalarVariable.h"
#include "EnvironmentalGlobalsExtraVectorVariable.h"
#include "EnvironmentalGlobalsExtraVariables.generated.h"

USTRUCT(BlueprintType)
struct ENVIRONMENTALGLOBALS_API FEnvironmentalGlobalsExtraVariables {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnvironmentalGlobalsExtraScalarVariable> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnvironmentalGlobalsExtraColorVariable> Colors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnvironmentalGlobalsExtraVectorVariable> Vectors;
    
    FEnvironmentalGlobalsExtraVariables();
};

