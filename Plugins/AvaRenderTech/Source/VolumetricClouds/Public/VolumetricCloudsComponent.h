#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EVisibilityGroupMask -FallbackName=EVisibilityGroupMask
#include "EVisibilityGroupMask.h"
#include "Components/SceneComponent.h"
#include "VolumetricCloudsGroundShadowsCutOut.h"
#include "VolumetricCloudsGroundShadowsParams.h"
#include "VolumetricCloudsParams.h"
#include "VolumetricCloudsComponent.generated.h"

class UDirectionalLightComponent;
class UVolumetricCloudsGroundWorldState;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class VOLUMETRICCLOUDS_API UVolumetricCloudsComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsParams Params;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Height;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, Transient, meta=(AllowPrivateAccess=true))
    float HeightOffset;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UDirectionalLightComponent> PrimaryDirectionalLight;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UDirectionalLightComponent> SecondaryDirectionalLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsGroundShadowsParams GroundShadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsGroundShadowsCutOut GroundShadowsCutOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float GroundShadowsStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UVolumetricCloudsGroundWorldState* GroundShadowsState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsIntro: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVisibilityGroupMask VisibilityGroupMask;
    
    UVolumetricCloudsComponent();
};

