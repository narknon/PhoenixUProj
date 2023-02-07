#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MiniSelectionDiamondBase.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UMiniSelectionDiamondBase : public UUserWidget {
    GENERATED_BODY()
public:
    UMiniSelectionDiamondBase();
    UFUNCTION(BlueprintCallable)
    void SetState(bool IsActive);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetState(int32 NewState);
    
};

