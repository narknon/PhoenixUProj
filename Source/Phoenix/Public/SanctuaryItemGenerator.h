#pragma once
#include "CoreMinimal.h"
#include "TransfigurationObjectBase.h"
#include "SanctuaryItemGenerator.generated.h"

UCLASS(Blueprintable)
class ASanctuaryItemGenerator : public ATransfigurationObjectBase {
    GENERATED_BODY()
public:
    ASanctuaryItemGenerator();
    UFUNCTION(BlueprintCallable)
    void ShowCallout();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_NotifyItemHeldUpdated(FName NewItemHeld, bool bIsInitialState);
    
};

