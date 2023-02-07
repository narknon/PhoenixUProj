#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EReticuleState.h"
#include "HUDElementGroup.h"
#include "Reticule.generated.h"

class UCanvasPanel;
class UImage;
class UWidget;

UCLASS(Blueprintable, EditInlineNew)
class UReticule : public UHUDElementGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsSubReticuleVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseWeakSub;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SubReticuleMoveToTargetTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FinisherMaxSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FinisherAcceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsFinisherOverlapped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsBestFinisherOverlapped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PreventFinisherWhenNotOverlapped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseLinearFinisherReticule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FinisherStartAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FinisherLinearStartDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialFinisherReticuleDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OverlapHalfAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BestOverlapHalfAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoldFinisherTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* FinisherCircle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* FinisherRing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* FinisherCircleImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* FinisherRingImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* ReticulePanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* Primary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EReticuleState ReticuleState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsReticuleVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsCombatReticuleVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsTargetReticuleVisible;
    
    UReticule();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UseWeakReticuleBP(bool InUseWeakSub);
    
    UFUNCTION(BlueprintCallable)
    void ShowTargetReticule(bool IsVisible);
    
    UFUNCTION(BlueprintCallable)
    void ShowCombatReticule(bool IsVisible);
    
    UFUNCTION(BlueprintCallable)
    void Show(bool IsVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupForLinearFinisher();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupForCircularFinisher();
    
    UFUNCTION(BlueprintCallable)
    void SetState(EReticuleState State);
    
    UFUNCTION(BlueprintCallable)
    void SetFinisherNormalizedAngle(float NormalizedAngle);
    
    UFUNCTION(BlueprintCallable)
    void SetFinisherActive(bool FinisherActiveIn);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleShowTargetReticule(bool IsVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleShowSub(bool IsVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleShowRing(bool IsVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleShowCombatReticule(bool IsVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleShow(bool IsVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleSetTargetRingPosition(FVector2D Position);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleSetSubPosition(FVector2D Position);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleSetState(EReticuleState State);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleSetPrimaryPosition(FVector2D Position);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleOverlapping(bool Overlapping);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleFire();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleFinisherActiveChanged(bool FinisherActiveIn);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleFadeFinisher();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleBestOverlapping(bool Overlapping);
    
    UFUNCTION(BlueprintCallable)
    EReticuleState GetState();
    
    UFUNCTION(BlueprintCallable)
    bool GetFinisherActive();
    
};

