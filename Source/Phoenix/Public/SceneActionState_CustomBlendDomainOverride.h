#pragma once
#include "CoreMinimal.h"
#include "Interface_RenderSettingsCustomBlendDomainOverride.h"
#include "SceneRigActionState.h"
#include "SceneActionState_CustomBlendDomainOverride.generated.h"

UCLASS(Blueprintable)
class USceneActionState_CustomBlendDomainOverride : public USceneRigActionState, public IInterface_RenderSettingsCustomBlendDomainOverride {
    GENERATED_BODY()
public:
    USceneActionState_CustomBlendDomainOverride();
    
    // Fix for true pure virtual functions not being implemented
};

