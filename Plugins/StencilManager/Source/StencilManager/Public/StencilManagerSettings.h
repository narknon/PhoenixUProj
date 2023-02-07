#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StencilManagerEffectInfo.h"
#include "StencilManagerMPCGlobals.h"
#include "StencilPrimitiveTagRules.h"
#include "StencilManagerSettings.generated.h"

class ULocalStencilEffectActorOverrides;
class UMaterialInterface;
class UMaterialParameterCollection;
class UStencilManagerAccessibilityOverrides;
class UStencilManagerWholeActorOverrides;

UCLASS(Blueprintable)
class STENCILMANAGER_API UStencilManagerSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> StencilPostProcessingMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* PreferredStencilPostProcessingMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForcePreferredStencilPostProcessingMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MaterialParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerMPCGlobals MaterialParameterGlobals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Groups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStencilManagerEffectInfo> EffectsList;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStencilManagerAccessibilityOverrides* AccessibilityOverrides;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStencilManagerWholeActorOverrides* WholeActorOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilPrimitiveTagRules DefaultLocalStencilTagRules;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocalStencilEffectActorOverrides* LocalStencilFXOverrides;
    
    UStencilManagerSettings();
};

