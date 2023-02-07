#pragma once
#include "CoreMinimal.h"
#include "SceneAction_ConsoleRenderingVar.h"
#include "SceneAction_DynamicShadowQualityScale.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_DynamicShadowQualityScale : public USceneAction_ConsoleRenderingVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 QualityScale;
    
    USceneAction_DynamicShadowQualityScale();
};

