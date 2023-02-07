#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ObjectStateInterface.generated.h"

class UAkComponent;
class UPrimitiveComponent;

UINTERFACE(Blueprintable, MinimalAPI)
class UObjectStateInterface : public UInterface {
    GENERATED_BODY()
};

class IObjectStateInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupSfx(UAkComponent* AkComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReset();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UPrimitiveComponent* GetMainPrimitive();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FName GetMainBone();
    
};

