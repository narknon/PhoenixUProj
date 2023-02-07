#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "Interface_RenderSettingsCustomBlendDomain.h"
#include "InsideOutsideOverrideVolume.generated.h"

UCLASS(Abstract, Blueprintable)
class RENDERSETTINGS_API AInsideOutsideOverrideVolume : public AVolume, public IInterface_RenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    AInsideOutsideOverrideVolume();
    UFUNCTION(BlueprintCallable)
    void SetPriority(float NewPriority);
    
    
    // Fix for true pure virtual functions not being implemented
};

