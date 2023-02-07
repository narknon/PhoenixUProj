#pragma once
#include "CoreMinimal.h"
#include "CameraStackTransfigurationPreviewTargetGetter.h"
#include "CameraStackStationaryTransfigurationPreviewTargetGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackStationaryTransfigurationPreviewTargetGetter : public UCameraStackTransfigurationPreviewTargetGetter {
    GENERATED_BODY()
public:
    UCameraStackStationaryTransfigurationPreviewTargetGetter();
};

