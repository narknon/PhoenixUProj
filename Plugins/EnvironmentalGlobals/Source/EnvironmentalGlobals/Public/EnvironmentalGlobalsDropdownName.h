#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsDropdownName.generated.h"

USTRUCT(BlueprintType)
struct FEnvironmentalGlobalsDropdownName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    ENVIRONMENTALGLOBALS_API FEnvironmentalGlobalsDropdownName();
};

