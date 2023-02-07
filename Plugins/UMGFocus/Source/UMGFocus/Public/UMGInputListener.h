#pragma once
#include "CoreMinimal.h"
#include "UMGInputListener.generated.h"

class UUMGFocusWidget;

USTRUCT(BlueprintType)
struct FUMGInputListener {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 UIPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUMGFocusWidget* UMGFocusWidget;
    
    UMGFOCUS_API FUMGInputListener();
};

