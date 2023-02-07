#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CurseInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UCurseInterface : public UInterface {
    GENERATED_BODY()
};

class ICurseInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUncursed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInteractWithCurse();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFailedToUncurse();
    
};

