#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InstallFeature.h"
#include "InstallFeatureSettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class UInstallFeatureSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSupportsLanguagePacks;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSupportsLanguagePackInstalling;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInstallFeature> InstallFeatures;
    
    UInstallFeatureSettings();
};

