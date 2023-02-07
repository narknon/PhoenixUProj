#pragma once
#include "CoreMinimal.h"
#include "WorldEventPersistenceInfo.generated.h"

USTRUCT(BlueprintType)
struct FWorldEventPersistenceInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Stages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRepeatOnComplete;
    
    PHOENIX_API FWorldEventPersistenceInfo();
};

