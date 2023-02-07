#pragma once
#include "CoreMinimal.h"
#include "Interface_RenderSettingsCustomBlendDomainOverride.h"
#include "SceneRigActionState.h"
#include "SceneActionState_WeatherGeneric.generated.h"

UCLASS(Blueprintable)
class USceneActionState_WeatherGeneric : public USceneRigActionState, public IInterface_RenderSettingsCustomBlendDomainOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CachedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CachedDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bCachedEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bCachedInsideInterval;
    
    USceneActionState_WeatherGeneric();
    
    // Fix for true pure virtual functions not being implemented
};

