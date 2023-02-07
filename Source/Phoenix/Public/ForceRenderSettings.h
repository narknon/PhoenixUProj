#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EForceRenderSettingsPhase.h"
#include "ForceRenderSettingsCommand.h"
#include "ForceRenderSettings.generated.h"

UCLASS(Blueprintable)
class AForceRenderSettings : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FForceRenderSettingsCommand> Commands;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableAll;
    
    AForceRenderSettings();
    UFUNCTION(BlueprintCallable)
    void QueryAll();
    
    UFUNCTION(BlueprintCallable)
    bool IsPlayInEditor();
    
    UFUNCTION(BlueprintCallable)
    static bool IsEditor();
    
    UFUNCTION(BlueprintCallable)
    void ApplyNow();
    
    UFUNCTION(BlueprintCallable)
    void Apply(EForceRenderSettingsPhase Phase);
    
};

