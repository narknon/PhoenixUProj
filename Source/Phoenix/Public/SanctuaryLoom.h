#pragma once
#include "CoreMinimal.h"
#include "TransfigurationObjectBase.h"
#include "SanctuaryLoom.generated.h"

UCLASS(Blueprintable)
class ASanctuaryLoom : public ATransfigurationObjectBase {
    GENERATED_BODY()
public:
    ASanctuaryLoom(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowLoomUI();
    
};

