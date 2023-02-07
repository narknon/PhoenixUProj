#pragma once
#include "CoreMinimal.h"
#include "MultiFXHandle.h"
#include "MultiFXPlusHandles.generated.h"

USTRUCT(BlueprintType)
struct FMultiFXPlusHandles {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMultiFXHandle> FXHandleArray;
    
    PHOENIX_API FMultiFXPlusHandles();
};

