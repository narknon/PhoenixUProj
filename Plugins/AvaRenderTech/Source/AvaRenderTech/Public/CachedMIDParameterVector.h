#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CachedMIDParameter.h"
#include "CachedMIDParameterVector.generated.h"

USTRUCT(BlueprintType)
struct AVARENDERTECH_API FCachedMIDParameterVector : public FCachedMIDParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Value;
    
    FCachedMIDParameterVector();
};

