#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EObjectFadeCompletedAction.h"
#include "EObjectFadeDirection.h"
#include "EObjectFadeMasterState.h"
#include "ObjectFadeParamsCurve.h"
#include "ObjectFadeParamsEaseFunction.h"
#include "ObjectFadeParamsSpeedDuration.h"
#include "Objectfade.h"
#include "ObjectFadeMaster.generated.h"

class UMeshComponent;
class UObject;

UCLASS(Blueprintable, NotPlaceable, Transient)
class FXUTIL_API AObjectFadeMaster : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UObject>, FObjectfade> FadeMap;
    
public:
    AObjectFadeMaster();
    UFUNCTION(BlueprintCallable)
    static bool MeshStartFadeEaseFunction(UMeshComponent* Mesh, const FObjectFadeParamsEaseFunction& Setup, EObjectFadeCompletedAction FadeCompletedAction, float TimeFactorOverride);
    
    UFUNCTION(BlueprintCallable)
    static bool MeshStartFadeDirectCurve(UMeshComponent* Mesh, const FObjectFadeParamsCurve& Setup, EObjectFadeCompletedAction FadeCompletedAction, float TimeFactorOverride);
    
    UFUNCTION(BlueprintCallable)
    static bool MeshStartFade(UMeshComponent* Mesh, const FObjectFadeParamsSpeedDuration& Setup, EObjectFadeCompletedAction FadeCompletedAction, float TimeFactorOverride);
    
    UFUNCTION(BlueprintCallable)
    static void MeshRemoveFade(UMeshComponent* Mesh, bool& wasFading);
    
    UFUNCTION(BlueprintCallable)
    static void MeshIsFadingOut(UMeshComponent* Mesh, bool& isFading, bool& isDone);
    
    UFUNCTION(BlueprintCallable)
    static void MeshIsFadingIn(UMeshComponent* Mesh, bool& isFading, bool& isDone);
    
    UFUNCTION(BlueprintCallable)
    static bool ActorStartFadeEaseFunction(AActor* Actor, const FObjectFadeParamsEaseFunction& Setup, EObjectFadeCompletedAction FadeCompletedAction, float TimeFactorOverride);
    
    UFUNCTION(BlueprintCallable)
    static bool ActorStartFadeDirectCurve(AActor* Actor, const FObjectFadeParamsCurve& Setup, EObjectFadeCompletedAction FadeCompletedAction, float TimeFactorOverride);
    
    UFUNCTION(BlueprintCallable)
    static bool ActorStartFade(AActor* Actor, const FObjectFadeParamsSpeedDuration& Setup, EObjectFadeCompletedAction FadeCompletedAction, float TimeFactorOverride);
    
    UFUNCTION(BlueprintCallable)
    static void ActorSetFadeInOut(AActor* Actor, EObjectFadeDirection Direction, EObjectFadeMasterState& FadeState, float Duration, EObjectFadeCompletedAction FadeInCompletedAction, EObjectFadeCompletedAction FadeOutCompletedAction, bool bFadeInIfNotInSystem);
    
    UFUNCTION(BlueprintCallable)
    static void ActorRemoveFade(AActor* Actor, bool& wasFading);
    
    UFUNCTION(BlueprintCallable)
    static void ActorPingPongFade(AActor* Actor, EObjectFadeDirection Direction, EObjectFadeMasterState& FadeState, float Duration);
    
    UFUNCTION(BlueprintCallable)
    static void ActorIsFadingOut(AActor* Actor, bool& isFading, bool& isDone);
    
    UFUNCTION(BlueprintCallable)
    static void ActorIsFadingIn(AActor* Actor, bool& isFading, bool& isDone);
    
};

