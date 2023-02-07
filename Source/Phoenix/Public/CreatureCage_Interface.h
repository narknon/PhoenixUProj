#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CreatureCage_Interface.generated.h"

class USceneComponent;

UINTERFACE(Blueprintable)
class UCreatureCage_Interface : public UInterface {
    GENERATED_BODY()
};

class ICreatureCage_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsCageOpen();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    USceneComponent* GetWalkoutTarget();
    
};

