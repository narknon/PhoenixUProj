#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimMetaData.h"
#include "PerClipLayerGroupLayer.h"
#include "PerClipLayerGroup.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UPerClipLayerGroup : public UAnimMetaData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPerClipLayerGroupLayer> LayerContent;
    
    UPerClipLayerGroup();
};

