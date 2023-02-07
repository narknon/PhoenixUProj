#pragma once
#include "CoreMinimal.h"
#include "ETagType.h"
#include "BaseTagCommand.generated.h"

USTRUCT(BlueprintType)
struct AIPATHSCHEDULER_API FBaseTagCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETagType TagCommandType;
    
    FBaseTagCommand();
};

