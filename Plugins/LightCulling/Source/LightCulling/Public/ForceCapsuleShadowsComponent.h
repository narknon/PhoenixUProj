#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ForceCapsuleShadowsSettings.h"
#include "ForceCapsuleShadowsComponent.generated.h"

class AActor;
class UForceCapsuleShadowsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LIGHTCULLING_API UForceCapsuleShadowsComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FForceCapsuleShadowsSettings Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDisable: 1;
    
    UForceCapsuleShadowsComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateSettings(FForceCapsuleShadowsSettings NewSettings);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void Enabled(bool& bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void Enable(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    static void DetachAndDestroyForceCapsuleShadows(AActor* Owner, UForceCapsuleShadowsComponent* ExistingForceCapsuleShadowsComponent);
    
    UFUNCTION(BlueprintCallable)
    void DestroyForceCapsuleShadows();
    
    UFUNCTION(BlueprintCallable)
    static void CreateAndAttachForceCapsuleShadows(AActor* Owner, FForceCapsuleShadowsSettings NewSettings, UForceCapsuleShadowsComponent*& NewForceCapsuleShadowsComponent, bool bTransient);
    
};

