#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EFeatureInstallState.h"
#include "EInstallFeatures.h"
#include "InstallManager.generated.h"

class UInstallManager;

UCLASS(Blueprintable)
class PHOENIX_API UInstallManager : public UObject {
    GENERATED_BODY()
public:
    UInstallManager();
    UFUNCTION(BlueprintCallable, Exec)
    void UninstallFeature(EInstallFeatures FeatureId);
    
    UFUNCTION(BlueprintCallable)
    bool IsLanguageInstalledOrInstalling(const FString& Language);
    
    UFUNCTION(BlueprintCallable)
    bool IsInstallingAnyPack();
    
    UFUNCTION(BlueprintCallable)
    bool IsInstallingAnyLanguagePack();
    
    UFUNCTION(BlueprintCallable, Exec)
    void InstallFeature(EInstallFeatures FeatureId);
    
    UFUNCTION(BlueprintCallable)
    EFeatureInstallState GetFeatureInstallState(EInstallFeatures FeatureId);
    
    UFUNCTION(BlueprintCallable)
    float GetFeatureInstallPercentage(EInstallFeatures FeatureId);
    
    UFUNCTION(BlueprintCallable)
    EInstallFeatures GetCurrentlyInstallingFeatureId();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UInstallManager* Get();
    
    UFUNCTION(BlueprintCallable)
    FString FindAvailableInstalledLanguage();
    
};

