#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MIDVectorParameter.generated.h"

USTRUCT(BlueprintType)
struct FMIDVectorParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Value;
    
    MATERIALPERMUTER_API FMIDVectorParameter();
};

