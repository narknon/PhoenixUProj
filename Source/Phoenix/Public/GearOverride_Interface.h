#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GearOverride_Interface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UGearOverride_Interface : public UInterface {
    GENERATED_BODY()
};

class IGearOverride_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FName GetOutfitGear();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FName GetNeckGear();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FName GetHouse();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FName GetHeadGear();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FName GetHandGear();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FName GetFaceGear();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FName GetBackGear();
    
};

