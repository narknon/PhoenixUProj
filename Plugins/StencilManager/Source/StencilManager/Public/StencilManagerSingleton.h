#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SavePrimitiveRenderCustomDepthOwner.h"
#include "StencilManagerEnableInterfaceList.h"
#include "StencilManagerMPCGlobals.h"
#include "StencilManagerTrackActorLocalStencil.h"
#include "StencilManagerTrackActorSkinFX.h"
#include "StencilManagerTrackActorStencil.h"
#include "StencilManagerSingleton.generated.h"

class UObject;
class UPrimitiveComponent;
class UStencilManagerExternalControls;
class UStencilManagerSettings;

UCLASS(Blueprintable, Transient)
class STENCILMANAGER_API AStencilManagerSingleton : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStencilManagerSettings* Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStencilManagerExternalControls* ExternalControls;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> DisabledGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerEnableInterfaceList EnableInterfaces;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> HardReferences;
    
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, FStencilManagerTrackActorStencil> LegacyStencilActors;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, FStencilManagerTrackActorLocalStencil> StencilLocalActors;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, FStencilManagerTrackActorSkinFX> SkinFXActors;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, FStencilManagerTrackActorStencil> StencilMaskActors;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, FStencilManagerTrackActorStencil> AutoStencilMaskActors;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UPrimitiveComponent>, FSavePrimitiveRenderCustomDepthOwner> ExternalLocks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float StencilBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bUpdatedStencilBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FStencilManagerMPCGlobals MPCGlobals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> ConsoleDisabledGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bConsoleDisableStencil;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDisableStencil;
    
public:
    AStencilManagerSingleton(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetStencilPlayerNearFadeDisable(UObject* WorldContextObject, bool bPlayerNearFadeDisable);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetStencilBlend(UObject* WorldContextObject, float blendVal);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetOutdoorsDaytimeBoost(UObject* WorldContextObject, float boostVal);
    
};

