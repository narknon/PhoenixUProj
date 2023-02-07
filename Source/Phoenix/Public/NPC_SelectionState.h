#pragma once
#include "CoreMinimal.h"
#include "ENPC_SelectionStates.h"
#include "NPC_SelectionState.generated.h"

USTRUCT(BlueprintType)
struct FNPC_SelectionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_SelectionStates StateType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StateEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StateValue;
    
    PHOENIX_API FNPC_SelectionState();
};

