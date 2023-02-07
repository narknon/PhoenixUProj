#pragma once
#include "CoreMinimal.h"
#include "ECameraFixupLayer.h"
#include "GameplayTagContainer.h"
#include "DialogLineRule_CameraFixup.generated.h"

class UCameraFixupActorAction;
class UCameraFixupOperation;

USTRUCT(BlueprintType)
struct FDialogLineRule_CameraFixup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraFixupLayer Layer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCameraFixupOperation*> Operations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCameraFixupActorAction*> ActorActions;
    
    PHOENIX_API FDialogLineRule_CameraFixup();
};

