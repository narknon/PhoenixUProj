#pragma once
#include "CoreMinimal.h"
#include "Interface_ExposureExpressionsGlobalsProvider.h"
#include "BlendDomain.h"
#include "SceneRigActionBase.h"
#include "SceneAction_EmissiveAdaptationBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_EmissiveAdaptationBase : public USceneRigActionBase, public IInterface_ExposureExpressionsGlobalsProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FeatherInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FeatherOutTime;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    USceneAction_EmissiveAdaptationBase();
    
    // Fix for true pure virtual functions not being implemented
};

