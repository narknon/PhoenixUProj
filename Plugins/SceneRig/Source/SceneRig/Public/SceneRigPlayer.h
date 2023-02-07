#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SceneRigBudgeterInterface.h"
#include "SignificanceInterface.h"
#include "TimeRigPlayer.h"
#include "SceneRigPlayerInitializedDelegate.h"
#include "SceneRigPlayer.generated.h"

class UObject;
class USceneActionState_PlayBinkMedia;
class USceneActionState_PlayFMV;
class UUserWidget;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigPlayer : public UTimeRigPlayer, public ISceneRigBudgeterInterface, public ISignificanceInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigPlayerInitialized OnSceneRigPlayerInitialized;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneActionState_PlayFMV* OverridingFMV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneActionState_PlayBinkMedia* OverridingBinkMedia;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UUserWidget* SkipWidget;
    
public:
    USceneRigPlayer();
    UFUNCTION(BlueprintCallable)
    bool UpdateTransformParameter(const FString& ParameterName, const FTransform& InValue);
    
    UFUNCTION(BlueprintCallable)
    bool UpdateStringParameter(const FString& ParameterName, const FString& InValue);
    
    UFUNCTION(BlueprintCallable)
    bool UpdateObjectParameter(const FString& ParameterName, UObject* Object);
    
    UFUNCTION(BlueprintCallable)
    bool UpdateIntParameter(const FString& ParameterName, int32 InValue);
    
    UFUNCTION(BlueprintCallable)
    bool UpdateFloatParameter(const FString& ParameterName, float InValue);
    
    UFUNCTION(BlueprintCallable)
    bool UpdateBoolParameter(const FString& ParameterName, bool InValue);
    
    UFUNCTION(BlueprintCallable)
    void ShowSkipUI(bool bShow);
    
    UFUNCTION(BlueprintCallable)
    void ApplyParameterUpdatesImmediately();
    
    
    // Fix for true pure virtual functions not being implemented
};

