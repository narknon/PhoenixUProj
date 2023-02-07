#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LightInterface.generated.h"

class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class ULightInterface : public UInterface {
    GENERATED_BODY()
};

class ILightInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnExitedNearby();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnExitedLightProximity(AActor* LumosBP);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnExitedLight(AActor* LumosBP, bool bPlayerOwned);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnteredNearby(AActor* LumosBP);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnteredLightProximity(AActor* LumosBP);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnteredLight(AActor* LumosBP, bool bPlayerOwned);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DisableLightRaytrace();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool DisableLightInteraction();
    
};

