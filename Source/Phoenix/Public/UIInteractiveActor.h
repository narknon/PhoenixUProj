#pragma once
#include "CoreMinimal.h"
#include "InteractiveObjectActor.h"
#include "UIInteractiveActor.generated.h"

class UCognitionStimuliSourceComponent;

UCLASS(Blueprintable)
class AUIInteractiveActor : public AInteractiveObjectActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CognitionStimuliSourceComponent;
    
    AUIInteractiveActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InteractionInitiated();
    
};

