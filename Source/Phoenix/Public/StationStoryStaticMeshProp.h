#pragma once
#include "CoreMinimal.h"
#include "StationStoryProp.h"
#include "StationStoryStaticMeshProp.generated.h"

class UStaticMesh;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UStationStoryStaticMeshProp : public UStationStoryProp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* StaticMesh;
    
    UStationStoryStaticMeshProp();
};

