#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "StagePreviewDriver.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UStagePreviewDriver : public UBaseProvider {
    GENERATED_BODY()
public:
    UStagePreviewDriver();
};

