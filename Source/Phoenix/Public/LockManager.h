#pragma once
#include "CoreMinimal.h"
#include "DatabaseLockList.h"
#include "PhxDbRegistryTypeManager.h"
#include "LockManager.generated.h"

UCLASS(Blueprintable)
class ULockManager : public UPhxDbRegistryTypeManager {
    GENERATED_BODY()
public:
    ULockManager();
private:
    UFUNCTION(BlueprintCallable)
    void OnSaveLoad();
    
    UFUNCTION(BlueprintCallable)
    void OnPreSaveLoad();
    
    UFUNCTION(BlueprintCallable)
    void OnPreNewGame();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetLockName(const FDatabaseLockList DatabaseLockList);
    
};

