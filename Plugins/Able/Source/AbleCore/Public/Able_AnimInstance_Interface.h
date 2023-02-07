#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "Able_AnimInstance_Interface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UAble_AnimInstance_Interface : public UInterface {
    GENERATED_BODY()
};

class IAble_AnimInstance_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_LastDesiredWorldDirection(FVector InWorldDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_DesiredWorldSpeed(float InSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Set_DesiredWorldDirection(FVector InWorldDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GoToLoco2();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GoToLoco1();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_LastDesiredWorldDirection(FVector& OutWorldDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_DesiredWorldSpeed(float& OutSpeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Get_DesiredWorldDirection(FVector& OutWorldDirection);
    
};

