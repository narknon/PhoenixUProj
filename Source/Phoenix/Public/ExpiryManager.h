#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EExpiryTypes.h"
#include "ExpiryManager.generated.h"

class UExpiryManager;

UCLASS(Blueprintable)
class UExpiryManager : public UObject {
    GENERATED_BODY()
public:
    UExpiryManager();
    UFUNCTION(BlueprintCallable)
    bool RefreshExpiry(const FString& UniqueId, int64 ExpireTime, EExpiryTypes ExpiryType);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
public:
    UFUNCTION(BlueprintCallable)
    bool HasExpiry(const FString& UniqueId, EExpiryTypes ExpiryType);
    
    UFUNCTION(BlueprintCallable)
    int64 GetExpiry(const FString& UniqueId, EExpiryTypes ExpiryType);
    
    UFUNCTION(BlueprintCallable)
    static UExpiryManager* Get();
    
    UFUNCTION(BlueprintCallable)
    bool ClearExpiry(const FString& UniqueId, EExpiryTypes ExpiryType);
    
    UFUNCTION(BlueprintCallable)
    bool AddExpiry(const FString& UniqueId, int64 ExpireTime, EExpiryTypes ExpiryType);
    
};

