#pragma once
#include "CoreMinimal.h"
#include "DialogueLineRule_PickCameraItem.generated.h"

class UActorProvider;

USTRUCT(BlueprintType)
struct FDialogueLineRule_PickCameraItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* Camera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    PHOENIX_API FDialogueLineRule_PickCameraItem();
};

