#pragma once
#include "CoreMinimal.h"
#include "PhoenixBudgetedActor.h"
#include "TransfigurableObjectInterface.h"
#include "InteractiveObjectActor.generated.h"

class UObjectStateComponent;

UCLASS(Blueprintable)
class AInteractiveObjectActor : public APhoenixBudgetedActor, public ITransfigurableObjectInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjectStateComponent* ObjectState;
    
    AInteractiveObjectActor(const FObjectInitializer& ObjectInitializer);
    
    // Fix for true pure virtual functions not being implemented
};

