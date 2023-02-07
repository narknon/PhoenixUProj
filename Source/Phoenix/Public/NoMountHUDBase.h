#pragma once
#include "CoreMinimal.h"
#include "HUDElementGroup.h"
#include "NoMountHUDBase.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UNoMountHUDBase : public UHUDElementGroup {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsAnimating;
    
public:
    UNoMountHUDBase();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUseStateChanged(bool Show);
    
};

