#pragma once
#include "CoreMinimal.h"
#include "DuelTechnique_UIData.h"
#include "HUDElementGroup.h"
#include "DuelTechniquesHUDBase.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UDuelTechniquesHUDBase : public UHUDElementGroup {
    GENERATED_BODY()
public:
    UDuelTechniquesHUDBase();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTimedTechniqueUpdated(FName TechniqueID, const FText& TimeStr);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDuelTechniqueUpdatedByID(FName TechniqueID, int32 NewValue);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDuelTechniquesInitialized(const TArray<FDuelTechnique_UIData>& TechniqueUIData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDuelTechniquesDone();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDuelTechniqueProgressFailedByID(FName TechniqueID, bool IsNew);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDuelTechniqueProgressCompletedByID(FName TechniqueID, bool IsNew);
    
private:
    UFUNCTION(BlueprintCallable)
    void HideUITimerExpired();
    
};

