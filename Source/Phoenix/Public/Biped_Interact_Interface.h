#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Biped_Interact_Interface.generated.h"

class UBTService_AvaAITree;

UINTERFACE(Blueprintable, MinimalAPI)
class UBiped_Interact_Interface : public UInterface {
    GENERATED_BODY()
};

class IBiped_Interact_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Interact(UBTService_AvaAITree* AvaService);
    
};

