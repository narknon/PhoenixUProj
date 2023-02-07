#pragma once
#include "CoreMinimal.h"
#include "EAdjustedValueBooleanMode.h"
#include "AdjustedValueBoolean.generated.h"

USTRUCT(BlueprintType)
struct FAdjustedValueBoolean {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAdjustedValueBooleanMode Value;
    
    GLOBALLIGHTRIG_API FAdjustedValueBoolean();
};

