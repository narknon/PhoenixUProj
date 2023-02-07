#pragma once
#include "CoreMinimal.h"
#include "UMGInputListener.h"
#include "UMGInputListenerStack.generated.h"

USTRUCT(BlueprintType)
struct FUMGInputListenerStack {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FUMGInputListener> InputListenerStack;
    
    UMGFOCUS_API FUMGInputListenerStack();
};

