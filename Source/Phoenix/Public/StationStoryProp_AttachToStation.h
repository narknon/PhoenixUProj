#pragma once
#include "CoreMinimal.h"
#include "StationStoryPropAttachment.h"
#include "StationStoryProp_AttachToStation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UStationStoryProp_AttachToStation : public UStationStoryPropAttachment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StationSocket;
    
    UStationStoryProp_AttachToStation();
};

