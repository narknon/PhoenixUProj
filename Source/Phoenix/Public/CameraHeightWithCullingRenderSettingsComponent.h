#pragma once
#include "CoreMinimal.h"
#include "CameraHeightRenderSettingsComponent.h"
#include "CameraHeightRenderSettingsCullVolume.h"
#include "CameraHeightWithCullingRenderSettingsComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCameraHeightWithCullingRenderSettingsComponent : public UCameraHeightRenderSettingsComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCameraHeightRenderSettingsCullVolume> CullVolumes;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCameraHeightRenderSettingsCullVolume> SortedCullVolumes;
    
public:
    UCameraHeightWithCullingRenderSettingsComponent();
};

