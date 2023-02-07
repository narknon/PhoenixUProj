#pragma once
#include "CoreMinimal.h"
#include "EInteractiveAction.h"
#include "EInteractiveState.h"
#include "InteractiveObjectLinkData.generated.h"

USTRUCT(BlueprintType)
struct FInteractiveObjectLinkData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInteractiveState m_startState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInteractiveState m_endState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInteractiveAction m_action;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText m_message;
    
    PHOENIX_API FInteractiveObjectLinkData();
};

