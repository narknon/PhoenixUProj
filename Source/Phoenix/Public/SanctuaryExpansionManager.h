#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SanctuaryExpansionManager.generated.h"

UCLASS(Blueprintable)
class USanctuaryExpansionManager : public UObject {
    GENERATED_BODY()
public:
    USanctuaryExpansionManager();
    UFUNCTION(BlueprintCallable)
    void TriggerExpansion(const FName InExpansionLockID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldSkipUnlockCinematics() const;
    
    UFUNCTION(BlueprintCallable)
    void ReleaseExpansion(const FName InExpansionLockID);
    
    UFUNCTION(BlueprintCallable)
    void LoadExpansion(const FName InExpansionLockID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValidExpansion(const FName InExpansionLockID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsExpansionOpen(const FName InExpansionLockID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsExpansionLoaded(const FName InExpansionLockID) const;
    
};

