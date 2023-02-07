#pragma once
#include "CoreMinimal.h"
#include "InputActionHoldInfo.h"
#include "MastermindPopupInfo.generated.h"

USTRUCT(BlueprintType)
struct FMastermindPopupInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPlayingIntro;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPlayingOutro;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputActionHoldInfo> CompletionActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsWaitPopup;
    
    PHOENIX_API FMastermindPopupInfo();
};

