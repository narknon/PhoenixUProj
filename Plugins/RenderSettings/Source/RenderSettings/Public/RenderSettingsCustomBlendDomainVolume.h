#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "Interface_RenderSettingsCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainNameWithValue.h"
#include "RenderSettingsCustomBlendDomainVolume.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API ARenderSettingsCustomBlendDomainVolume : public AVolume, public IInterface_RenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnbounded;
    
    ARenderSettingsCustomBlendDomainVolume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetPriority(float NewPriority);
    
    
    // Fix for true pure virtual functions not being implemented
};

