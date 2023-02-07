#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PickupTool_Interface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UPickupTool_Interface : public UInterface {
    GENERATED_BODY()
};

class IPickupTool_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DeactivateTool();
    
};

