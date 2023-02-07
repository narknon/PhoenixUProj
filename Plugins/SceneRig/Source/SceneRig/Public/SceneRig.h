#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitect_ComponentOwnerInterface.h"
#include "AnimationArchitect_TagProviderInterface.h"
#include "ETimeRigInitializingBehavior.h"
#include "TimeRig.h"
#include "SceneParameterInterface.h"
#include "SceneRigBoundObject.h"
#include "SceneRigParameters.h"
#include "SceneRigPrecacheCompleteBPDelegate.h"
#include "SceneRigStage_Transform.h"
#include "SceneRig.generated.h"

class UAnimationArchitectTagProvider;
class UBaseArchitectAsset;
class UObject;
class USceneRigInterfaceDefinition;
class USceneRigPlayer;
class USceneRigStage;
class USceneRigStageParameterBlock;
class USceneRigStage_NamedParameter;
class UWorld;

UCLASS(Blueprintable, Config=EditorPerProjectUserSettings)
class SCENERIG_API USceneRig : public UTimeRig, public IAnimationArchitect_TagProviderInterface, public IAnimationArchitect_ComponentOwnerInterface, public ISceneParameterInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BakeSequenceDebug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneRigInterfaceDefinition* Interface;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneRigBoundObject> BoundObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAnimationArchitectTagProvider*> TagProviders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigStage* DefaultStage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PreviewStageDriver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBaseArchitectAsset*> LookupAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool DebugInEditor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool StartDebuggingPaused;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldSimulatePhysics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInstantlySkippable;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerSortOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Transform SceneRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneRigStage_NamedParameter*> NamedParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> CinematicPreviewLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> PreviewLevels;
    
    USceneRig();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    void StartPrecaching(UObject* WorldContextObject, const FSceneRigPrecacheCompleteBP& PrecacheComplete) const;
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    USceneRigPlayer* PlayWithDefaultParameters(UObject* WorldContextObject, UObject* PlayerParent, ETimeRigInitializingBehavior InitializingBehaviorType);
    
    UFUNCTION(BlueprintCallable)
    USceneRigPlayer* Play(const FSceneRigParameters& Parameters, UObject* PlayerParent, ETimeRigInitializingBehavior InitializingBehaviorType);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    USceneRigPlayer* InitializePlayerWithDefaultParameters(UObject* WorldContext, UObject* PlayerParent, ETimeRigInitializingBehavior InitializingBehaviorType);
    
    UFUNCTION(BlueprintCallable)
    USceneRigPlayer* InitializePlayer(const FSceneRigParameters& Parameters, UObject* PlayerParent, ETimeRigInitializingBehavior InitializingBehaviorType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    USceneRigPlayer* FindPlayer(UObject* WorldContextObject) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    void CreateDefaultParameters(FSceneRigParameters& Parameters, UObject* WorldContextObject) const;
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    USceneRigStageParameterBlock* CreateParameterBlock(UObject* OuterObject) override PURE_VIRTUAL(CreateParameterBlock, return NULL;);
    
};

