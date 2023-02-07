#pragma once
#include "CoreMinimal.h"
#include "ContextArray.h"
#include "FrameToContexts.generated.h"

USTRUCT(BlueprintType)
struct FFrameToContexts {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, FContextArray> FrameToContextsMap;
    
    PHOENIX_API FFrameToContexts();
};

