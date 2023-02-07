#pragma once
#include "CoreMinimal.h"
#include "MIDScalarParameter.generated.h"

USTRUCT(BlueprintType)
struct FMIDScalarParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    MATERIALPERMUTER_API FMIDScalarParameter();
};

