#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "InputCoreTypes.h"
#include "StoryGraphPlayer.h"
#include "SceneParameterInterface.h"
#include "StoryGraphDynamicEventHandlerDelegate.h"
#include "StoryGraphActor.generated.h"

class ATriggerBase;
class UObject;
class UPrimitiveComponent;
class USceneComponent;
class USceneRigPlayer;
class USceneRigStageParameterBlock;
class UStoryNodeState_Custom;
class UStoryNode_Custom;
class UTimeRig_StoryGraph;

UCLASS(Blueprintable)
class SCENERIG_API AStoryGraphActor : public AActor, public IStoryGraphPlayer, public ISceneParameterInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FKey DebugTriggerKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DebugTriggerEventName;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ATriggerBase>> TriggerVolumes;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRig_StoryGraph* StoryGraph;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHoldCurtainUntilPlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> LookupAlias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigStageParameterBlock* ParameterBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowTimeRigsToBeSkipped;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UStoryNode_Custom*, UStoryNodeState_Custom*> CustomNodeStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigPlayer* AmbientPlayer;
    
public:
    AStoryGraphActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool TriggerEventOnActiveSceneRigs(FName Event);
    
    UFUNCTION(BlueprintCallable)
    bool TriggerEvent(FName Event, FName EventSource);
    
    UFUNCTION(BlueprintCallable)
    bool TriggerAnyEvent(FName& OutEventTriggered, FName EventSource);
    
    UFUNCTION(BlueprintCallable)
    bool SetBoolParameter(FName ParameterName, bool bBoolToSet);
    
    UFUNCTION(BlueprintCallable)
    void SetAllowTimeRigsToBeSkipped();
    
    UFUNCTION(BlueprintCallable)
    bool SetActorParameter(FName ParameterName, AActor* ActorToSet);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnCurtainRaised();
    
    UFUNCTION(BlueprintCallable)
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
public:
    UFUNCTION(BlueprintCallable)
    bool HandleEvent(FName Event, FStoryGraphDynamicEventHandler Handler);
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    USceneRigStageParameterBlock* CreateParameterBlock(UObject* OuterObject) override PURE_VIRTUAL(CreateParameterBlock, return NULL;);
    
};

