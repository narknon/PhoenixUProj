#pragma once
#include "CoreMinimal.h"
#include "NPC_StimulusEvent.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FNPC_StimulusEvent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Broadcaster;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Enemy;
    
    PHOENIX_API FNPC_StimulusEvent();
};

