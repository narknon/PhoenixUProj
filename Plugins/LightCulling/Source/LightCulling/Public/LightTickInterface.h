#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LightTickInterface.generated.h"

class ULightComponent;

UINTERFACE(Blueprintable)
class LIGHTCULLING_API ULightTickInterface : public UInterface {
    GENERATED_BODY()
};

class LIGHTCULLING_API ILightTickInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnExitLightTickRange(ULightComponent* LightComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEnterLightTickRange(ULightComponent* LightComponent);
    
};

