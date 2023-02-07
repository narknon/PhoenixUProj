#pragma once
#include "CoreMinimal.h"
#include "BTCustomAction.h"
#include "GameFramework/Actor.h"
#include "Tool.generated.h"

class UAkAudioEvent;
class UToolEffectData;
class UToolRecord;
class UToolSetComponent;

UCLASS(Blueprintable)
class TOOLSET_API ATool : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseEffectsOnTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EffectsTimeIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EffectsTimeOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UToolEffectData*> ActivateEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UToolEffectData*> DeactivateEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* EquipSfx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* UnequipSfx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBTCustomAction ToolEquipAction;
    
    ATool();
    UFUNCTION(BlueprintCallable)
    AActor* GetUltimateOwner();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UToolRecord* GetToolRecord() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UToolSetComponent* GetOurToolSetComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DeactivationFx();
    
    UFUNCTION(BlueprintCallable)
    void DeactivationComplete();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BlueprintDeactivate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BlueprintActivate();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ActivateFx();
    
};

