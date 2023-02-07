#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EAlohomoraLevel.h"
#include "LockableManager.generated.h"

class ULockableComponent;

UCLASS(Blueprintable)
class ULockableManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULockableComponent*> AlohomoraComponents;
    
public:
    ULockableManager();
private:
    UFUNCTION(BlueprintCallable)
    void OnPreGameSave();
    
    UFUNCTION(BlueprintCallable)
    void OnPostGameLoad();
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void LockablesSuperAlohomora(bool Enable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LockablesSetAlohomora(EAlohomoraLevel AlohomoraLevel);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LockablesMasterKey(bool Enable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LockablesMarkLocks(bool Enable);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LockablesDrawDebugInfo(bool Enable);
    
};

