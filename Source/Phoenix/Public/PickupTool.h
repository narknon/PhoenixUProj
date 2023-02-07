#pragma once
#include "CoreMinimal.h"
#include "ItemTool.h"
#include "PickupTool_Interface.h"
#include "PickupTool.generated.h"

UCLASS(Blueprintable)
class APickupTool : public AItemTool, public IPickupTool_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UnequipAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AccioCatchable;
    
    APickupTool();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUseReleased();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUsePressed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeactivateReleased();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeactivatePressed();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DeactivateTool();
    
    
    // Fix for true pure virtual functions not being implemented
};

