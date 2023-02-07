#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicVarBool.h"
#include "CameraHeightWithCullingRenderSettingsComponent.h"
#include "CameraHeightWithPlayerRequirementsRenderSettingsComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCameraHeightWithPlayerRequirementsRenderSettingsComponent : public UCameraHeightWithCullingRenderSettingsComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName_GameLogicVarBool> PlayerRequirements;
    
    UCameraHeightWithPlayerRequirementsRenderSettingsComponent();
};

