#pragma once
#include "CoreMinimal.h"
#include "GenderVoice.generated.h"

USTRUCT(BlueprintType)
struct FGenderVoice {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    PHOENIX_API FGenderVoice();
};

