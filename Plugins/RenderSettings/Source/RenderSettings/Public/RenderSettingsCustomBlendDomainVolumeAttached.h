#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface_RenderSettingsCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainNameWithValue.h"
#include "RenderSettingsCustomBlendDomainVolumeAttached.generated.h"

class AVolume;

UCLASS(Blueprintable)
class RENDERSETTINGS_API ARenderSettingsCustomBlendDomainVolumeAttached : public AActor, public IInterface_RenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AVolume* AttachTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsCustomBlendDomainNameWithValue> Domains;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    ARenderSettingsCustomBlendDomainVolumeAttached();
    UFUNCTION(BlueprintCallable)
    void SetPriority(float NewPriority);
    
    
    // Fix for true pure virtual functions not being implemented
};

