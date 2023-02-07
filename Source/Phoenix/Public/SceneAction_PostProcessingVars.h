#pragma once
#include "CoreMinimal.h"
#include "BlendDomain.h"
#include "SceneAction_PostProcessingBaseFeatherInOut.h"
#include "SceneAction_PostProcessingVars.generated.h"

class UPostProcessingVar;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_PostProcessingVars : public USceneAction_PostProcessingBaseFeatherInOut {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UPostProcessingVar*> PostProcessingVars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStretchCurvesToTime;
    
    USceneAction_PostProcessingVars();
};

