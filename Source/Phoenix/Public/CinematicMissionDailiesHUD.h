#pragma once
#include "CoreMinimal.h"
#include "CinematicBatchHUD.h"
#include "CinematicMissionDailiesHUD.generated.h"

class USceneRig;
class USceneRigPlayer;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UCinematicMissionDailiesHUD : public UCinematicBatchHUD {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SceneRigName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString StoryGraphName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MissionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTotalFramesSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasSceneRigBeenInitialized;
    
    UCinematicMissionDailiesHUD();
    UFUNCTION(BlueprintCallable)
    void UpdateStoryGraphName(const FString& NewSGName);
    
    UFUNCTION(BlueprintCallable)
    void UpdateSceneRigName(const FString& NewSRName);
    
    UFUNCTION(BlueprintCallable)
    void UpdateMissionID(const FString& NewMissionID);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowSR();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowSG();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowFrames();
    
    UFUNCTION(BlueprintCallable)
    void SetSceneRig(USceneRig* InSceneRig);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSceneRigChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideSR();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideSG();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideFrames();
    
    UFUNCTION(BlueprintCallable)
    float GetHUDSRLength(USceneRigPlayer* SceneRigPlayer, USceneRig* InSceneRig, bool bInFrames);
    
    UFUNCTION(BlueprintCallable)
    float GetActiveSRFrame(USceneRigPlayer* SceneRigPlayer);
    
};

