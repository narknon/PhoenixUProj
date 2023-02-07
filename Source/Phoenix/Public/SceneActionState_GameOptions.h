#pragma once
#include "CoreMinimal.h"
#include "Interface_RenderSettingsCustomBlendDomainOverride.h"
#include "SceneRigActionState.h"
#include "SceneActionState_GameOptions.generated.h"

UCLASS(Blueprintable)
class USceneActionState_GameOptions : public USceneRigActionState, public IInterface_RenderSettingsCustomBlendDomainOverride {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CachedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CachedDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bCachedEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bCachedInsideInterval;
    
public:
    USceneActionState_GameOptions();
    
    // Fix for true pure virtual functions not being implemented
};

